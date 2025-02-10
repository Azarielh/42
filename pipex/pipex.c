/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:53 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/10 17:12:27 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"

// char *get_path_from_env(char **env)		// Find Path environment
// {
// 	while (*env)
// 	{
// 		if (ft_strncmp(*env, "PATH=", 5) == 0)
// 			return (*env + 5);
// 		env++;
// 	}
// 	return (NULL);
// }


// char *find_command_path(char *cmd, char **env) 
// {
//     char *path_env = get_path_from_env(env);
//     char **paths = ft_split(path_env, ':');
//     char *full_path;
    
//     for (int i = 0; paths[i]; i++) {
//         full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
//         if (access(full_path, X_OK) == 0) {
//             free(paths); // Free the split array
//             return full_path;
//         }
//         free(full_path);
//     }
//     free(paths);
//     return NULL;
// }


// void execute_command(char *cmd, char **args, char **env) {
//     char *cmd_path = find_command_path(cmd, env);
//     if (!cmd_path) {
//         perror("Command not found");
//         exit(EXIT_FAILURE);
//     }
//     execve(cmd_path, args, env);
//     perror("execve failed");
//     exit(EXIT_FAILURE);
// }


int	main(int argc, char **argv/*, char **env*/)
{
    int nb = argc;

	if (argc == 1)
		return (printf("This program require some arguments"));
	char *cmd = argv[1];
	// char **args = &argv[1]; // Arguments starting from the command itself
	// execute_command(cmd, args, env);
	while (nb >= 1)
	{
		printf("%c\n",cmd[nb--]);
	}
	return(0);
}