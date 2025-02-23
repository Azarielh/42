/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 06:35:11 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/23 07:12:35 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int nb_args_check(int argc, int nb, char *str)
{
    if (argc < nb)
    {
        ft_printf("%s", str);
        return (-1);
    }
    return (1);    
}
void execute_command(char *cmd, char **envp) {
    char *args[4];
    args[0] = "sh";
    args[1] = "-c";
    args[2] = cmd;
    args[3] = NULL;

    if (execve("/bin/sh", args, envp) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[], char *envp[]) {
    if (nb_args_check(argc, 4, "Usage: %s file cmd1 cmd2 ... file2\n") < 5) {
        return EXIT_FAILURE;
    }

    // Ouverture du fichier d'entrée
    int fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Ouverture du fichier de sortie
    int fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
        perror("open");
        close(fd_in);
        return EXIT_FAILURE;
    }

    int pipefd[2];
    pid_t pid;

    // Boucle sur les commandes intermédiaires
    for (int i = 2; i < argc - 2; i++) {
        if (pipe(pipefd) == -1) {
            perror("pipe");
            close(fd_in);
            close(fd_out);
            return EXIT_FAILURE;
        }

        pid = fork();
        if (pid == -1) {
            perror("fork");
            close(fd_in);
            close(fd_out);
            return EXIT_FAILURE;
        }

        if (pid == 0) {
            // Processus enfant
            if (i == 2) {
                dup2(fd_in, STDIN_FILENO);
            } else {
                dup2(pipefd[0], STDIN_FILENO);
            }

            if (i == argc - 3) {
                dup2(fd_out, STDOUT_FILENO);
            } else {
                dup2(pipefd[1], STDOUT_FILENO);
            }

            close(fd_in);
            close(fd_out);
            close(pipefd[0]);
            close(pipefd[1]);

            execute_command(argv[i], envp);
        } else {
            // Processus parent
            close(pipefd[1]);
            fd_in = pipefd[0];
        }
    }

    // Dernier processus enfant
    pid = fork();
    if (pid == -1) {
        perror("fork");
        close(fd_in);
        close(fd_out);
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        dup2(fd_in, STDIN_FILENO);
        dup2(fd_out, STDOUT_FILENO);

        close(fd_in);
        close(fd_out);

        execute_command(argv[argc - 2], envp);
    } else {
        close(fd_in);
        close(fd_out);
    }

    // Attendre la fin de tous les processus enfants
    while (wait(NULL) > 0);

    return EXIT_SUCCESS;
}
