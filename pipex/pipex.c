/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:29:38 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/04/17 17:33:30 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	wait_child_and_close(int *pfd, int *lpid, char *msg_err)
{
	int	status;
	int	pid;
	int	exitcode;

	exitcode = 0;
	pid = wait(&status);
	while (pid != -1)
	{
		if (pid == *lpid && WIFEXITED(status))
			exitcode = WEXITSTATUS(status);
		else if (pid == *lpid && WIFSIGNALED(status))
			exitcode = 128 + WTERMSIG(status);
		pid = wait(&status);
	}
	if (pfd)
		free(pfd);
	if (msg_err)
		ft_putendl_fd(msg_err, 2);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (exitcode);
}

static int	get_cmdpath(char *path, char *cmd, char buffer[PATH_MAX])
{
	int	idx;
	int	offset;
	int	cmdlen;
	int	pathlen;

	if (path == NULL)
		return (-1);
	cmdlen = strlen(cmd);
	idx = 0;
	offset = 0;
	while (path[idx])
	{
		while (path[idx] && path[idx] != ':')
			idx++;
		pathlen = idx - offset;
		strncpy(buffer, &path[offset], pathlen);
		buffer[pathlen] = '/';
		strcpy(&buffer[pathlen + 1], cmd);
		buffer[pathlen + 1 + cmdlen] = '\0';
		if (access(buffer, F_OK) == 0)
			return (0);
		offset = ++idx;
	}
	return (-1);
}

int	exec_cmd(char *cmd, char **env)
{
	static char		**environ = NULL;
	static char		*path = NULL;
	char			cmd_path[PATH_MAX];
	char			**cmd_args;

	if (env != NULL)
	{
		environ = env;
		while (*env && (ft_strncmp("PATH=", *env, 5)))
			(*env)++;
		if (*env != NULL)
			path = (&(*env)[5]);
	}
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		return (-1);
	if (get_cmdpath(path, cmd_args[0], cmd_path))
	{
		dprintf(2, "%s: command not found\n", cmd_args[0]);
		free(cmd_args);
		return (-1);
	}
	execve(cmd_path, cmd_args, environ);
	return (-1);
}

static int	cmd_to(int to_pipe, char *cmd, int readfd, int *pfd)
{
	int	result;

	pfd[1] = -to_pipe;
	result = 0;
	if (to_pipe)
		result = pipe(pfd);
	if (!result)
		result = fork();
	if (!result)
	{
		if (to_pipe)
			close(pfd[READ_END]);
		if (dup2(readfd, STDIN_FILENO) == -1
			|| dup2(pfd[to_pipe], STDOUT_FILENO) == -1)
			exit(-1);
		close(pfd[to_pipe]);
		if (readfd != -1)
			close(readfd);
		exit(exec_cmd(cmd, NULL));
	}
	if (readfd != -1)
		close(readfd);
	if (pfd[to_pipe] != -1)
		close(pfd[to_pipe]);
	return (result);
}

int	main(int argc, char **argv, char **envp)
{
	int	*pfd;
	int	pid;
	int	idx;
	int	fd;

	if (argc < 5)
		return (wait_child_and_close(NULL, NULL, USAGE));
	pfd = malloc((sizeof(int) * (argc - 2)) << 1);
	if (pfd == NULL)
		return (wait_child_and_close(pfd, NULL, NULL));
	exec_cmd(NULL, envp);
	pfd[0] = open(argv[1], O_RDONLY);
	idx = 2;
	fd = 0;
	while (idx < argc - 2)
	{
		pid = cmd_to(PIPE, argv[idx], pfd[fd], &pfd[fd + 2]);
		if (pid == -1)
			return (wait_child_and_close(pfd, &pid, NULL));
		idx++;
		fd += 2;
	}
	pfd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	pid = cmd_to(FILE, argv[argc - 2], pfd[(argc - 4) << 1], &pfd[1]);
	return (wait_child_and_close(pfd, &pid, NULL));
}
