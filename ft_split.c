/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-hac <imel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:55:02 by imel-hac          #+#    #+#             */
/*   Updated: 2026/11/10 10:35:12 by imel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count_words;
	size_t	i;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c && s[i + 1]))
			count_words++;
		i++;
	}
	return (count_words);
}

static size_t	ft_len_word(char const *s, char c)
{
	char const	*start;

	start = s;
	while (*s && *s != c)
		s++;
	return (s - start);
}

static void	ft_free_all(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
}

static char	**ft_fill_array(char const *s, char c, char **array)
{
	int		i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			word_len = ft_len_word(s, c);
			array[i] = malloc(word_len + 1);
			if (!array[i])
				return (ft_free_all(array, i - 1), NULL);
			ft_memcpy(array[i], s, word_len);
			array[i++][word_len] = '\0';
			s += word_len;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (ft_fill_array(s, c, array));
}
