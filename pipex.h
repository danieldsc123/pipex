/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:38 by danielda          #+#    #+#             */
/*   Updated: 2024/12/11 22:53:00 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

void	child_process1(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **enpv, int *fd);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
char	*check_paths(char **paths, char *cmd);
void	free_cmd(char **cmd);
void	free_paths(char **paths);
void	error(void);
void	check(int argc);
#endif