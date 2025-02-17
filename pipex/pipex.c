/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:53 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/17 17:16:34 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "libft/libft.h"

char *get_path_from_env(char **env)		// Find Path environment
{
	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
        {
            ft_printf("\033[1;33mLe chemin d'accès vers PATH= trouve est :\033[0m\n%s\n", *env);
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
        ft_printf("\033[1;33mBuild full path from ft_split :\033[0m\n%s\n", full_path);
        if (access(full_path, X_OK) == 0) 
        {
            ft_printf("\033[1;33mLa valeur de path trouvé est\033[0m :\n%s\n", full_path);
            return full_path;
        }
        free(full_path);
    }
    return NULL;
}


void execute_command(char *cmd, char **file, char **env) {
    char *cmd_path = find_command_path(cmd, env);
    if (!cmd_path) {
        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    // ft_printf("\033[1;33mThis is file\033[0m\n%s\n\033[1;33mThis is cmd :\033[0m\n%s\n", *file, cmd);
    execve(cmd_path, file, env);
    perror("execve failed");
    exit(EXIT_FAILURE);
}


int	main(char **argv, char **env)
{

	// if (argc < 4)
	// 	return (ft_printf("This program require at least 4 arguments\nMust be : ./pipex file1 cmd1 cmd2 file2"));
	int i = argc;

	//while (i < argc) {
		char file = argv[1];// File or input to work with
        char cmd = argv[2];// Arguments starting from the command itself
		execute_command(cmd, file, env);
		//i++;
	//}
	return(0);
}

