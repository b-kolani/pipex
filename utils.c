/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:01:04 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/17 21:47:28 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	if (!str || !*str)
		return (0);
	return (1 + ft_strlen(str + 1));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				p;

	i = 0;
	p = 0;
	while ((s1[i] || s2[i]) && p == 0 && i < n)
	{
		if (s1[i] != s2[i])
			p = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	str_len;
	int		i;

	str_len = ft_strlen(str);
	cpy = malloc(str_len + 1);
	if (!cpy)
		return (NULL);
	i = -1;
	while (str[++i])
		cpy[i] = str[i];
	cpy[i] = '\0';
	return (cpy);
}

void	ft_handle_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
