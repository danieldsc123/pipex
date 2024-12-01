/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielda <danielda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:51:26 by danielda          #+#    #+#             */
/*   Updated: 2024/12/01 18:38:18 by danielda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// funçao filho que roda dentro de um fork, pega o arquivo e coloca a saida dentro de um pipe e depois fecha com a funçao exec
void	child_process(char **argv, char **enpv, int *fd)
{
}

//funçao pai que pega os dados do pipe, altera a saida para o fileout e tambem fecha com a funçao exec
void	parent_process(char **argv, char **enpv, int *fd)
{
}

//funçao principal executa o processo pai e filho ou exibe um erro mensagem se os argumentos estiverem errados
int	main(int argc, char **argv, char **envp)
{
}
