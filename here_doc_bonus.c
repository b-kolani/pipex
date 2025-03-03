/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:57:26 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/18 22:28:50 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_invalid_args(void)
{
	write(1, "\033[0;31mpipex: Invalid number of arguments\033[0m\n", 46);
	write(1, "Usage: \033[0;33m "
		"./pipex file1 <cmd1> <cmd2> <cmd3> ... <cmdn> file2\033[0m\n", 71);
	write(1, "\033[0;33m  	./pipex here_doc LIMITER cmd cmd1 file\033[0m\n", 52);
	exit(EXIT_FAILURE);
}

static void	ft_handle_heredoc_fd(int ac, char **argv, int *fd)
{
	int	input_fd;
	int	output_fd;

	input_fd = open(".heredoc", O_WRONLY | O_CREAT, 0644);
	if (input_fd == -1)
		ft_handle_err("\033[1;31m input file error!\033[0m");
	output_fd = open(argv[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (output_fd == -1)
		ft_handle_err("\033[1;31m output file error!\033[0m");
	fd[0] = input_fd;
	fd[1] = output_fd;
}

void	ft_handle_here_doc(int ac, char **av, int *fd, int *i)
{
	char	*line;

	if (ac != 6)
	{
		write(1, "\033[0;31mpipex: Invalid number of arguments\033[0m\n", 46);
		write(1, "Usage: \033[0;33m./pipex here_doc LIMITER "
			"cmd cmd1 file\033[0m\n", 52);
		exit(EXIT_FAILURE);
	}
	ft_handle_heredoc_fd(ac, av, fd);
	while (1)
	{
		write(1, "pipex heredoc> ", 15);
		line = get_next_line(1);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
			break ;
		write(fd[0], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd[0]);
	fd[0] = open(".heredoc", O_RDONLY);
	if (fd[0] == -1)
		ft_handle_err("\033[1;31m input file error!\033[0m");
	*i = 2;
}
