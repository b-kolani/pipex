/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:05:31 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/17 15:34:12 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "sys/wait.h"
# include "utils.h"

void	ft_handle_fd(int ac, char **argv, int *fd);
void	ft_exec(char *cmd, char **paths);
char	*ft_get_path(char **paths, char **cmd_args);
void	ft_handle_pipe(char **argv, char **path, int *fd, int *pipe_fd);

char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	ft_handle_err(char *str);

#endif
