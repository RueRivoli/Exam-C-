/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:12:16 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/08 20:29:12 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int		is_space(char *str, int i)
{
	return (str[i] == ' '  || str[i] == '\t' || str[i] == '\n' || str[i] == '\0');
}

char	*ft_strsub(char *s, int start, int len)
{
	int i;
	char *str;

	if (s == NULL || start + len > ft_strlen(s))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

int		number_of_words(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		if (is_space(str, i) == 1 && is_space(str, i + 1) == 0)
			count++;
		if (i == 0 && is_space(str, i) == 0)
			count++;
		i++;
	}
	return (count);
}

char	**fill(char **tab, char *phrase)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < ft_strlen(phrase) - 1)
	{
		if (is_space(phrase, i) == 1 && is_space(phrase, i + 1) == 0)
		{
			j = 0;
			i++;
			while (is_space(phrase, i + j) == 0)
				j++;
			tab[count] = ft_strsub(phrase, i, j);
			count++;
		}
		if (i == 0 && is_space(phrase, i) == 0)
		{
			j = 0;
			while (is_space(phrase, i + j) == 0)
				j++;
			tab[count] = ft_strsub(phrase, i, j);
			count++;
		}
		i++;
	}
	tab[count] = NULL;
	return (tab);
}

char	**ft_split(char *str)
{
	char **tab;

	if (!str)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * number_of_words(str) + 1)))
		return (NULL);
	tab = fill(tab, str);
	return (tab);
}

