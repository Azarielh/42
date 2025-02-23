/**
 * @file pipex.h
 * @brief Header file for the pipex project.
 *
 * This file includes the necessary headers and defines the prototypes for
 * the pipex project.
 *
 * @author jlacaze-
 * @date Created on: 2025/02/23
 */

#ifndef PIPEX_H
#define PIPEX_H

#include "libft.h"

#endif // PIPEX_H

/**
 * @brief Look for key data within your environment.
 *
 * @param env is machine environment data and is recquiered to look for your key.
 * @param key is what data you're looking for inside your environment.
 *
 * @return the string it found within your key.
 */
char *get_path_from_env(char **env, char *key);

/**
 *@brief It is specifically designed to look for tty command.
 * In order to do thism, it goes through the "PATH=" variable within your machine environment.
 * It calls for 'get_path_from_env' to get the so call PATH
 *
 * @param cmd is the tty command to look for
 * @param env is machine environment data and is recquiered to look for your key.
 */
char *find_command_path(char *cmd, char **env);

/**
 * @brief check your argc and print the corresponding error message in two row only with this brand new function. Is it not amazing?
 *
 * @param argc Put your argc variable here.
 * @param nb  Here is the number of arguments your program recquires to work properly
 * @param str Here is your personnal error message. Scream it hard and clear. User have to feel bad about themselves while reading your message !
 *
 * @return nb_args_check is boolean
 * It returns 1 if there is enough arguments
 * Otherwise, it returns -1 in addition of printing your custom message.
 */
int nb_args_check(int argc, int nb, char *str);

// int opendup(const char *file, int)