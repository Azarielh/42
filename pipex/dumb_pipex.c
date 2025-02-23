/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:53 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/23 06:15:37 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include "libft/libft.h"
#include "libft/gnl/get_next_line_bonus.h"
#include <fcntl.h>

// _______________________ GETTING TO TERMINAL CMD __________________________________________

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

// _____________________________ EXECUTE THEM ________________________________
void execute_command(char *cmd, char *file_src, char *file_dest, char **env) 
{
    int     in_fd;
    int     out_fd;
    pid_t   child;

    in_fd = open(file_src, O_RDONLY);
    out_fd = open(file_dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    child = fork();

    dup2(in_fd, 3);
    if (in_fd == -1 || out_fd == -1) 
    {
        perror("Erreur lors de la création du fichier");
        exit(EXIT_FAILURE);
    }

    if (child < 0)// Error while creating process
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (child == 0) 
        {
        ft_printf("Je suis le child %d\n", getpid());
        char *cmd_path = find_command_path(cmd, env);
        ft_printf("\n\033[1;36mExecuting command:\033[0m %s\n\033[1;32mFile content :\n\033[1;0m", cmd_path);
        if (!cmd_path) {
            ft_printf("\033[1;31mCommand not found: %s\033[0m\n", cmd);
            exit(EXIT_FAILURE);
        }
        char *args[] = {cmd, file_src, NULL};  // On passe la commande et le fichier d'entrée
        execve(cmd_path, args, env);
// Si execve failed
        perror("execve failed");
        exit (EXIT_FAILURE);
    } else {
// Bloc exécuté par le processus parent
        int status;
        waitpid(child, &status, 0);
// Attente de la fin du processus enfant
        ft_printf("\nLe processus enfant est terminé.\n");
        ft_printf("Je suis le processus parent avec PID %d\n", getpid());
    }
}


int main(int argc, char **argv, char **env) {
    if (argc < 2) {
        ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
        return (EXIT_FAILURE);
    }
    if (!env)
    {
        ft_printf("There is an issue with your env");
        return (EXIT_FAILURE);
    }

    char *file_src = argv[1];  // File or input to work with
    char *cmd = argv[2];   // cmd to execute
    char *file_dest = argv[argc - 1];

    execute_command(cmd, file_src, file_dest, env);  // Passer les arguments

    return (0);
}
