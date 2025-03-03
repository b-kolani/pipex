/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:00:23 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/16 11:10:37 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*ft_strncpy(char *s1, char const *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	count_word;
	int		in_word;
	int		i;

	count_word = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		if (str[i] != c && !in_word)
		{
			count_word++;
			in_word = 1;
		}
		i++;
	}
	return (count_word);
}

static char	**ft_create_result(char const *str, char **result, char c, int i)
{
	int		j;
	int		k;

	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			result[k] = (char *)malloc((i - j) + 1 * sizeof(char));
			if (!result[k])
			{
				while (k > 0)
					free(result[--k]);
				return (NULL);
			}
			ft_strncpy(result[k++], &str[j], (i - j));
		}
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(const char *str, char c)
{
	int		words_counted;
	int		i;
	char	**result;

	i = 0;
	words_counted = ft_count_words(str, c);
	result = (char **)malloc((words_counted + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_create_result(str, result, c, i))
	{
		free(result);
		return (NULL);
	}
	return (result);
}
