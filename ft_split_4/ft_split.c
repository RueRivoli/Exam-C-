/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:12:16 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/01 15:59:11 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
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
		if (str[i] == ' ' && str[i + 1] != ' ')
			count++;
		if (i == 0 && str[i] != ' ')
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
		if (phrase[i] == ' ' && phrase[i + 1] != ' ')
		{
			j = 0;
			i++;
			while (phrase[i + j] != ' ')
				j++;
		tab[count] = ft_strsub(phrase, i, j );
		count++;
		}
		if (i == 0 && phrase[i] != ' ')
		{
			j = 0;
			while (phrase[i + j] != ' ')
				j++;
			tab[count] = ft_strsub(phrase, i, j);
			count++;
		}
			i++;
	}
	tab[count] = NULL;
	return (tab);
}

void		print_result(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
	}
}
char		**ft_split(char *mot)
{
	char **str;
	
	if (mot == NULL)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * number_of_words(mot) + 1)))
		return (NULL);
	str = fill(str, mot);
	return (str);
}

int		main(void)
{
	char **s;
	char *mot;

	mot = "chenille vaudou a une epaule gauche   ";
	s = ft_split(mot);
	print_result(s);
	return (0);
}
