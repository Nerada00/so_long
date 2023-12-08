/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:25:49 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/08 17:37:52 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		word++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word);
}

static int	count_len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (*s && *s == c)
		s++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		word_len;
	int		word;

	word = count_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < word && *s)
	{
		while (*s == c)
			s++;
		word_len = count_len_word(s, c);
		strs[i] = ft_strndup(s, word_len);
		if (!strs[i])
			return (ft_free(strs, i));
		s += word_len;
		i++;
	}
	strs[word] = 0;
	return (strs);
}
