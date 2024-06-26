/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:26:42 by ychng             #+#    #+#             */
/*   Updated: 2024/04/22 17:44:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nowords(const char *str, const char *delim)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(delim, str[i]) != NULL)
			i++;
		if (str[i] != '\0')
			word_count++;
		while (str[i] && ft_strchr(delim, str[i]) == NULL)
			i++;
	}
	return (word_count);
}

static int	count_word_len(const char *str, const char *delim)
{
	int	len;

	len = 0;
	while (str[len] && ft_strchr(delim, str[len]) == NULL)
		len++;
	return (len);
}

static void	insert_chars(char **result, const char *str, const char *delim)
{
	int		word_len;
	char	*new_word;
	int		i;

	word_len = count_word_len(str, delim);
	new_word = malloc(sizeof(char) * (word_len + 1));
	i = 0;
	while (i < word_len)
	{
		new_word[i] = str[i];
		i++;
	}
	new_word[i] = '\0';
	result[0] = new_word;
}

static void	insert_word(char **result, const char *str, const char *delim)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(delim, str[i]) != NULL)
			i++;
		if (str[i] != '\0')
		{
			insert_chars(result + j, str + i, delim);
			j++;
		}
		while (str[i] && ft_strchr(delim, str[i]) == NULL)
			i++;
	}
	if (j == 0)
		result[j++] = (char *)str;
	result[j] = NULL;
}

char	**ft_split(const char *str, const char *delim)
{
	int		word_count;
	char	**result;

	if (!str || !delim)
		return (NULL);
	word_count = count_nowords(str, delim);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	insert_word(result, str, delim);
	return (result);
}
