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
#include <fcntl.h>

/*
_____________________________________________________________________________________
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
*                               GETTING PATH FROM ENV 
*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/**
 * @brief Look for key data within your environment.
 *
 * @param env is machine environment data and is recquiered to look for your key.
 * @param key is what data you're looking for inside your environment.
 *
 * @return the string it found within your key.
 */
char *getent_from_env(char **env, char *key);

/**
 *@brief It is specifically designed to look for tty command.
 * In order to do thism, it goes through the "PATH=" variable within your machine environment.
 * It calls for 'get_path_from_env' to get the so call PATH
 *
 * @param cmd is the tty command to look for
 * @param env is machine environment data and is recquiered to look for your key.
 */
char *find_command_path(char *cmd, char **env);

/*
_____________________________________________________________________________________
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
*                               CHECKING FUNCTION 
*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/**
 * @brief This is a boolean function. It checks how many arguments has been entered from argc and print the corresponding error message in two row only with this brand new function. 
 * You can also write your own message in there. Scream it hard and clear. User have to feel bad about themselves while reading your message ! Is it not amazing?
 * 
 * @param argc Put your argc variable here.
 * @param nb  Here is the number of arguments your program recquires to work properly
 *
 * @return nb_args_check is boolean
 * It returns 1 if there is enough arguments
 * Otherwise, it returns -1 in addition of printing your custom message.
 */
int nb_args_check(int argc, int nb);

/**
 * @brief This is a boolean function. It simply checks out if you have an environment to look for tty command.
 * 
 * @param env Give it the variable '**env' that you've got from your  main.abort
 * 
 * @return As any boolean would do, it returns 1 if true, 0 if false.
 */
int env_in_here(char **env);

/**
 * @brief This is a boolean function. is_pid_safe is meant to secure your subprocess, usually run with fork(). If it find an error, it will close the two file directory passed in argument.
 * 
 * @param pid is the process id we want to run.
 * @param fd_in is the fd where we want to read intel from
 * @param fd_out is the fd where we want to write answers to
 * 
 * @return it returns 1 if everything is fine. If it's not, it returns 0 after closing both file directory and send an error.
 */
int is_pid_safe(pid_t pid, int fd_in, int fd_out);

/**
 * @brief This function will open your file with the intended flags passed onto in arguments. Then, it will checks out if the open function worked fine or not.
 * 
 * @param file The file you want to open
 * @param flags All flags you intend to open your file with. 
 * @param mod Here is where you allow your fellow students or anyone you want to mess with your file. Make 0 if you don't want to bother !
 * 
 * @return It open failed, -1 will be returned. Otherwise you'll be granted with an fd integer.
 */
int ope_n_check(char *file, int flags, int mod);

/**
 * 
 */
void get_a_child(char **cmd, char *file_src, char *file_dest, char **env);

/**
 * @brief This is a variadic function. You have plenty of file to close and it takes you a lot load of line to close them all? Here is your savior my dear ! It will close as many file directors as you want it to.
 * 
 * @param fd_count is the number of fd you'll write in h
 */
void close_it_all(int fd_count, ...)
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"

#endif // PIPEX_H
