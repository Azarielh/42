/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:53 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/17 18:51:18 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "libft/libft.h"


char *parsing_cmd_from_env(char **argv, const void *cmd)
{
    //argv is the string passed as argument when program is called upon
    //cmd is dest for cmd storage with their respective paramaters
    int i;
    int cmd_len;
    
    i = 0;
    cmd_len = 0;
    while (argv[i][cmd_len++])
    {
        if(argv[i][cmd_len + 1] == ' ')
            ft_memmove(cmd, argv[i], cmd_len);
        if(argv[i][cmd_len + 1] == '-')
            ft_memmove(cmd, argv[i], cmd_len);
    }
}
char *get_path_from_env(char **env)		// Find Path environment
{
	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
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
        if (access(full_path, X_OK) == 0) 
            return full_path;
        free(full_path);
    }
    return NULL;
}


void execute_command(char *cmd, char *file, char **env) {
    char *cmd_path = find_command_path(cmd, env);
    if (!cmd_path) {
        ft_printf("\033[1;31mCommand not found: %s\033[0m\n", cmd);
        exit(EXIT_FAILURE);
    }

    // Créer un tableau args propre
    char *args[] = {cmd, file, NULL};  // On passe la commande et le fichier d'entrée

    ft_printf("\n\033[1;36mExecuting command:\033[0m %s\n\033[1;32mFile content :\n\033[1;0m", cmd_path);
    execve(cmd_path, args, env);
    perror("execve failed");
    exit(EXIT_FAILURE);
}



int main(int argc, char **argv, char **env) {
    if (argc < 2) {
        ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
        return (EXIT_FAILURE);
    }

    char *file1 = argv[1];  // File or input to work with
    char *cmd = argv[2];   // cmd to execute

    execute_command(cmd, file1, env);  // Passer correctement les arguments

    return (0);
}
