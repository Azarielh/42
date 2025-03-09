/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:43:54 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/09 16:37:09 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**getent_env(char **env, char *key)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (paths);
}

char	*get_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	paths = getent_env(env, "PATH=");
	i = 0;
	while (paths[i++])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
		{
			free_arr(paths);
			return (path);
		}
		free(path);
	}
	free_arr(paths);
	return (NULL);
}

void	exec_cmd(char *arg, char **env)
{
	char	*path;
	char	**cmd_args;

	cmd_args = ft_split_v2(arg, ' ');
	path = get_path(cmd_args[0], env);
	if (path == NULL)
	{
		free_arr(cmd_args);
		print_error("command not found", 1);
	}
	execve(path, cmd_args, env);
	print_error("execve failed", 1);
}
