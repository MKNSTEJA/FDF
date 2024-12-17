/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:57:20 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/13 13:02:57 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	count_char(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static int	free_mem(char **string, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(string[j]);
		j++;
	}
	free(string);
	return (0);
}

static int	make_substrings(char const *s, char c, char **string)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			len = count_char(s, c);
			string[i] = malloc(sizeof(char) * (len + 1));
			if (!string[i])
				return (free_mem(string, i));
			j = 0;
			while (j < len)
				string[i][j++] = *s++;
			string[i++][j] = '\0';
		}
	}
	string[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		count_str;

	if (!s)
		return (NULL);
	count_str = count_strings(s, c);
	string = malloc(sizeof(char *) * (count_str + 1));
	if (!string)
		return (NULL);
	if (!make_substrings(s, c, string))
		return (NULL);
	return (string);
}
