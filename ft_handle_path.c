/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:30:30 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/18 12:39:35 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

char	*ft_handle_path(char *path, char *cmd)
{
	char	*cmd_path;

	if (ft_strncmp("/bin/", cmd, 5) == 0)
		cmd_path = ft_strjoin(path, cmd + 5);
	else
		cmd_path = ft_strjoin(path, cmd);
	if (!cmd_path)
		return (NULL);
	return (cmd_path);
}
