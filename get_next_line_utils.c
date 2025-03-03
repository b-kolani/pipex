/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:29:53 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/18 22:30:50 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>

char	*ft_strjoin_gl(char const *s1, char const *s2)
{
	int		len;
	char	*tab;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tab = (char *)malloc(sizeof(char) * (len));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
		tab[i++] = s2[len++];
	tab[i] = '\0';
	return (tab);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		s = (char *)malloc(sizeof(char) * 1);
		if (!s)
			return (0);
		s[0] = '\0';
		return (s);
	}
	if (len > ft_strlen(s) - start)
		dest = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s[start] && len > i && (start < ft_strlen(s)))
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
