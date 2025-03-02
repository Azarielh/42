/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 06:35:11 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/02 20:43:54 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int ope_n_check(char *file, int flags, int mod)
{
    int fd;

    if (mod == 0)
        fd = open(file, flags);
    else
        fd = open(file, flags, mod);
    if (fd == -1)
    {
        ft_printf(RED"%s"RESET" : Failure while opening with fd %i ", file, fd);

        exit(EXIT_FAILURE);
    }
    ft_printf(BLUE"%s"RESET" has successfully opened\n", file);
    return (fd);
}

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


int env_in_here(char **env)
{
    if (!env)
    {
        ft_printf("Your env is missing. No Env = no pipex");
        exit(EXIT_FAILURE);
        return (-1);
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

void child(char **argv,char **env, int *fd)
{
    int filein;

    filein = ope_n_check(argv[1], O_RDONLY, 0);
    dup2(fd[1], STDOUT_FILENO);
    dup2(filein, STDIN_FILENO);
    close(fd[0]);
    execute (argv[2], env);
}
void parent(char *dest_file, char **argv, char **env, int *fd)
{
    int fileout;
    
    fileout = ope_n_check(dest_file, O_RDONLY | O_WRONLY | O_TRUNC, 0777);
    dup2(fd[0], STDIN_FILENO);
    dup2(fileout, STDOUT_FILENO);
    close(fd[1]);
    execute (argv[3], env);
}

void execute(char *argv, char **env)
{
    char    **commands;
    int     i;
    char    *path;

    i = -1;
    commands = ft_split(argv, ' ');
    path = find_command_path(commands[0], env);
    if (!path)
    {
        while (commands[i])
        {
            free(commands[i]);
            i++;
        }
        free(commands);
        perror("execute");
    }
    if (execve(path, commands, env) == -1)
        perror("execve");
}

int main(int argc, char **argv, char **env)
{
    int fd[2];
    pid_t pid1;
    char *dest_file;

    dest_file = argv[argc - 1];
    if (!*env)
        return (env_in_here(env));
    if (argc == 5)
    {
        if (pipe (fd) == -1)
            perror("twix");
        pid1 = fork();
        if (pid1 == -1)
            perror("twix");
        if(pid1 == 0)
            child(argv, env, fd);
        waitpid(pid1, NULL, 0);
        parent(dest_file, argv, env, fd);
    }
    else
    {
        ft_printf("Error: Bad arguments\n");
        perror("twix");
    }
    return (0);
}
