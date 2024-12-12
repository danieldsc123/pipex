/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:26 by danielda          #+#    #+#             */
/*   Updated: 2024/12/11 22:53:48 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(filein, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(filein);
	execute(argv[2], envp);
}

void	child_process2(char **argv, char **envp, int *fd)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(file_out, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

void	check(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		exit_code;

	exit_code = 0;
	check(argc);
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
		child_process1(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		exit(EXIT_FAILURE);
	if (pid2 == 0)
		child_process2(argv, envp, fd);
	close (fd[0]);
	close (fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &exit_code, 0);
	return (WEXITSTATUS(exit_code));
}

void	error(void)
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}
