/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:26 by danielda          #+#    #+#             */
/*   Updated: 2024/12/04 21:39:21 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_exec(char **arguments, char **environment, int *pipe_fd)
{
	int	input_file;

	input_file = open(arguments[1], O_RDONLY, 0777);
	if (input_file == -1)
		error_handler();
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(input_file, STDIN_FILENO);
	close(pipe_fd[0]);
	run_command(arguments[2], environment);
}

void	parent_process(char **argv, char **enpv, int *fd)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (1);
	}
	if (pipe(fd) == -1)
		error();
	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		child_exec(argv, envp, fd);
	else
	{
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	return (0);
}
