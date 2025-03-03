/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:50:00 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/18 18:33:43 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "sys/wait.h"
# include "utils.h"

void	ft_handle_fd(int ac, char **argv, int *fd, int *i);
void	ft_exec(char *cmd, char **paths);
char	*ft_get_path(char **paths, char **cmd_args);
void	ft_handle_pipe(char *argv, char **path, int *pipe_fd);
void	ft_handle_here_doc(int ac, char **av, int *fd, int *i);
void	handle_invalid_args(void);

char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	ft_handle_err(char *str);

#endif
