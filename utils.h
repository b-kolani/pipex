/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:08:26 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/17 23:03:12 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "unistd.h"
# include "stdarg.h"
# include "stdlib.h"

char	**ft_split(const char *str, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_handle_path(char *path, char *cmd);
void	ft_free_tab(char **tab);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gl(char const *s1, char const *s2);

#endif