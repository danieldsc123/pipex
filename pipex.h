/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:38 by danielda          #+#    #+#             */
/*   Updated: 2024/12/04 20:37:38 by danielda         ###   ########.fr       */
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

void	error(void);
char	*find_path(char *cmd, char **envp);
void	parent_process(char **argv, char **enpv, int *fd);
void	child_exec(char **arguments, char **environment, int *pipe_fd);
void	execute(char *argv, char **envp);
