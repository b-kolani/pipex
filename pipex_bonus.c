/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:56:22 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/18 18:40:45 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	ft_handle_fd(int ac, char **argv, int *fd, int *i)
{
	int	input_fd;
	int	output_fd;

	if (access(argv[ac - 1], F_OK) == 0)
		unlink(argv[ac - 1]);
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		ft_handle_err("\033[1;31m input file error!\033[0m");
	output_fd = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_handle_err("\033[1;31m output file error!\033[0m");
	fd[0] = input_fd;
	fd[1] = output_fd;
	*i = 1;
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

void	ft_handle_pipe(char *argv, char **path, int *pipe_fd)
{
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		ft_handle_err("\033[1;31m pipe error!\033[0m");
	pid = fork();
	if (pid == -1)
		ft_handle_err("\033[1;31m fork error!\033[0m");
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		ft_exec(argv, path);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		if (access(".heredoc", F_OK) == 0)
			unlink(".heredoc");
	}
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		j;
	char	**paths;
	int		pipe_fd[2];
	int		fd[2];

	if (ac < 5)
		handle_invalid_args();
	if (!ft_strncmp("here_doc", av[1], ft_strlen(av[1])))
		ft_handle_here_doc(ac, av, fd, &i);
	else
		ft_handle_fd(ac, av, fd, &i);
	j = -1;
	while (envp[++j])
	{
		if (!ft_strncmp(envp[j], "PATH=", 5))
			break ;
	}
	paths = ft_split(&envp[j][5], ':');
	dup2(fd[0], 0);
	while (ac - 2 > ++i)
		ft_handle_pipe(av[i], paths, pipe_fd);
	dup2(fd[1], 1);
	ft_exec(av[ac - 2], paths);
	return (0);
}
