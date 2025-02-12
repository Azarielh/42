/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:53 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/13 00:28:15 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "libft.h"

char *get_path_from_env(char **env)		// Find Path environment
{
	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			printf("cmd : %s\n",*env + 5);
			return (*env + 5);
		}
		env++;
	}
	return (NULL);
}

char *find_command_path(char *cmd, char **env) 
{
    char *path_env = get_path_from_env(env);
    char **paths = ft_split(path_env, ':');
    char *full_path;
    
    for (int i = 0; paths[i]; i++) {
        full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
        if (access(full_path, X_OK) == 0) {
            return full_path;
        }
        free(full_path);
    }
    return NULL;
}


void execute_command(char *cmd, char **args, char **env) {
    char *cmd_path = find_command_path(cmd, env);
    if (!cmd_path) {
        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    execve(cmd_path, args, env);
    perror("execve failed");
    exit(EXIT_FAILURE);
}


int	main(int argc, char **argv, char **env)
{

	if (argc < 4)
		return (ft_printf("This program require at least 4 arguments\nMust be : ./pipex file1 cmd1 cmd2 file2"));
	int i = 2;
	while (i < argc - 1) {
		char *cmd = argv[i];
		char **args = &argv[i]; // Arguments starting from the command itself
		execute_command(cmd, args, env);
		i++;
	}
	return(0);
}