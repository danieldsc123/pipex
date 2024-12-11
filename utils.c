/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:09:08 by danielda          #+#    #+#             */
/*   Updated: 2024/12/11 00:42:17 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	*check_paths(char **paths, char *cmd)
{
	char	*part_path;
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	paths = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				return (NULL);
			break ;
		}
		i++;
	}
	if (!paths)
		return (NULL);
	path = check_paths(paths, cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		perror("comand not faund");
		exit(127);
	}
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_cmd(cmd);
		perror("comand not faund");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{	
		free(path);
		free_cmd(cmd);
		perror("comand not faund");
		exit(EXIT_FAILURE);
	}
}

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
	}
}
