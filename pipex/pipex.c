/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:05:53 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/19 22:40:24 by jlacaze-         ###   ########.fr       */
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
    // char *cmd_path = find_command_path(cmd, env);
    // if (!cmd_path) {
    //     ft_printf("\033[1;31mCommand not found: %s\033[0m\n", cmd);
    //     exit(EXIT_FAILURE);
    // }

    // Créer un tableau args propre

    // char *args[] = {cmd, file_src, NULL};  // On passe la commande et le fichier d'entrée

    // ft_printf("\n\033[1;36mExecuting command:\033[0m %s\n\033[1;32mFile content :\n\033[1;0m", cmd_path);

    // Gerer l'ouverture du fichier

    int fd =   fd = open(file_dest, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1) 
    {
        perror("Erreur lors de la création du fichier");
        exit(EXIT_FAILURE);
    }

    pid_t child = fork();

    if (child < 0)
    {
        // Error while creating process
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (child == 0) {
        // This is executed by the child's process
        ft_printf("Je suis le child %d\n", getpid());
        // Execute of new program within the child process
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
        ft_printf("\nJe suis le processus parent avec PID %d\n", getpid());
        // Attente de la fin du processus enfant
        int status;
        pid_t child_pid
        waitpid(child, );
        ft_printf("\nLe processus enfant est terminé.\n");
    }
}



int main(int argc, char **argv, char **env) {
    if (argc < 2) {
        ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
        return (EXIT_FAILURE);
    }

    char *file_src = argv[1];  // File or input to work with
    char *cmd = argv[2];   // cmd to execute
    char *file_dest = argv[argc - 1];

    execute_command(cmd, file_src, file_dest, env);  // Passer les arguments

    return (0);
}
