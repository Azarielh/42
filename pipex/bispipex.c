/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bispipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:14:21 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/01 23:19:19 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// ______________________________Check before processing input

int env_in_here(char **env)
{
    if (!env)
    {
        ft_printf("Your env is missing. No Env = no pipex");
        return (1);
    }
    return (0);
}
int nb_args_check(int argc, int nb)
{
    
    if (argc < nb)
    {
        ft_printf("Usage: infile cmd1 cmd2 ... outfile\n");
        return (1);
    }
    return (0);
}

// ______________________________Safe guard for processus ID (pid)

int is_pid_safe(pid_t pid, int fd_in, int fd_out)
{
    if (pid == -1)
    {
        perror("fork error");
        close(fd_in);
        close(fd_out);
        return (0);
    }
    return (1);
}
// ______________________________Safe opening and closing

int ope_n_check(char *file, int flags, int mod)
{
    int fd;

    if (mod == 0)
        fd = open(file, flags);
    else
        fd = open(file, flags, mod);
    if (fd != -1)
    {
        ft_printf(BLUE"%s"RESET" has successfully opened\n", file);
        return (fd); 
    }
    perror("Failure while opening ");
    return (fd);
}

void close_it_all(int fd_count, ...)
{
    va_list args;
    int fd;
    int i;

    i = 0;
    va_start(args, fd_count);
    while (i++ < fd_count)
    {
        fd = va_arg(args, int);
        if (fd != -1)
            close(fd);
    }
    va_end(args);
}

// _______________________ GETTING TO TERMINAL CMD __________________________________________

char *getent_from_env(char **env, char *key)
{
    int len;

    len = ft_strlen(key);
    while (*env)
	{
		if (strncmp(*env, key, len) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

char *find_command_path(char *cmd, char **env)
{
    char *path_env = getent_from_env(env, "PATH=");
    char **paths = ft_split(path_env, ':');
    char *full_path;
    
    for (int i = 0; paths[i]; i++) {
        full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
        if (access(full_path, X_OK) == 0) 
            return full_path;
        free(full_path);
    }
    return (NULL);
}

// _______________________ SETTING UP CHILD __________________________________________

void get_a_child(char **cmd, char *file_src, char *file_dest, char **env)
{
    ft_printf(YELLOW"Entrée dans la fonction get_a_child\n"RESET);
    int i;
    int fd_in;
    int fd_out;
    int pipefd[2];
    char *path;
    char *cmd_path;
    pid_t child;

    i = 0;
    fd_in = ope_n_check (file_src, O_RDONLY, 0);
    fd_out = ope_n_check (file_dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    path = getent_from_env(env, "PATH=");
    cmd_path = find_command_path(cmd[0], env);
    while (*cmd != file_dest)
        ft_printf(YELLOW"cmd :"RESET"%s\n", *cmd++);

    // ======  FD CHECK  ======
    if (fd_in == -1 || fd_out == -1)
        exit(EXIT_FAILURE);

    // ======  PID CHECK  ======
    child = fork();

    if (!is_pid_safe(child, fd_in, fd_out))
        exit(EXIT_FAILURE);
    // ======  GET CHILD  ======
    else 
    {
        ft_printf("Process id %i are opened and safe\n", child);
        if (i == 2)
            dup2(fd_in, STDIN_FILENO);
        else
            dup2(pipefd[1], STDOUT_FILENO);
    }
    close_it_all(fd_in, fd_out, pipefd[0], pipefd[1]); 
}

int main(int argc, char **argv, char **env)
{
    if (nb_args_check(argc, 4) || env_in_here(env))
        return (EXIT_FAILURE);
    char *file_src;
    char *file_dest;
    char **cmd;
    int i;

    i = 0;
    cmd = argv + 2;
    while (i++ < argc - 1)
        ft_printf(YELLOW"Argument n %d:"RESET" %s\n", i, argv[i]);

    file_src = argv[1];
    file_dest = argv[argc - 1];
    ft_printf(BLUE"File_src : "RESET"%s\n"BLUE"File_dest : "RESET"%s\n", file_src, file_dest);

    get_a_child(cmd, file_src, file_dest, env);
    return (EXIT_SUCCESS);
}
