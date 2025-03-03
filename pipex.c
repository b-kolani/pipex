/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:27:06 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/18 22:48:28 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char **paths, char **cmd_args)
{
	char	*cmd_path;
	int		i;
	int		p;

	i = -1;
	p = 0;
	while (paths[++i])
	{
		cmd_path = ft_handle_path(paths[i], cmd_args[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			p++;
			break ;
		}
		free(cmd_path);
	}
	if (p == 0)
	{
		ft_free_tab(cmd_args);
		ft_free_tab(paths);
		ft_handle_err("pipex: command not found");
	}
	return (cmd_path);
}

void	ft_handle_fd(int ac, char **argv, int *fd)
{
	int	input_fd;
	int	output_fd;

	if (access(argv[ac - 1], F_OK) == 0)
		unlink(argv[ac - 1]);
	input_fd = open(argv[1], O_RDONLY, 0644);
	if (input_fd == -1)
		ft_handle_err("\033[1;31m input file error!\033[0m");
	output_fd = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_handle_err("\033[1;31m output file error!\033[0m");
	fd[0] = input_fd;
	fd[1] = output_fd;
}

void	ft_exec(char *cmd, char **paths)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		return ;
	cmd_path = ft_get_path(paths, cmd_args);
	ft_free_tab(paths);
	if (execve(cmd_path, cmd_args, NULL) == -1)
		ft_handle_err("\033[1;31m execve error!\033[0m");
}

void	ft_handle_pipe(char **argv, char **path, int *fd, int *pipe_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_handle_err("\033[1;31m fork error!\033[0m");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(pipe_fd[1]);
		ft_exec(argv[2], path);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(pipe_fd[0]);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	**paths;
	int		pipe_fd[2];
	int		fd[2];

	if (ac != 5)
	{
		write(1, "\033[0;31mpipex: Invalid number of arguments\033[0m\n", 46);
		write(1, "Usage: \033[0;33m"
			"./pipex infile <cmd1> <cmd2> outfile\033[0m\n", 56);
		exit(EXIT_FAILURE);
	}
	ft_handle_fd(ac, av, fd);
	if (pipe(pipe_fd) == -1)
		ft_handle_err("\033[1;31m pipe error!\033[0m");
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	paths = ft_split(envp[i] + 5, ':');
	ft_handle_pipe(av, paths, fd, pipe_fd);
	ft_exec(av[3], paths);
	return (0);
}
