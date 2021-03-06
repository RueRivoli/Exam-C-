/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:25:34 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/28 17:39:17 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
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

void		ft_bzero(void *b, int n)
{
	char *str;

	str = b;
	while (n--)
	{
		*str = 0;
		str++;
	}
}

int		ft_strlen(char const *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	else
	{
		ft_bzero(str, size + 1);
		return (str);
	}
}


char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *p;
	int i;

	i = 0;
	p = ft_strnew(len);
	if (p == NULL || s == NULL || start + len > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	return (p);
}

static int		ft_strlent(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int		ft_nbremots(char const *s)
{
	size_t	compteur;
	size_t	i;

	i = 0;
	compteur = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && s[i] != ' ')
			compteur++;
		if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0')
			compteur++;
		i++;
	}
	return (compteur);
}

static char		**ft_remplissage(char const *s, char **tab)
{
	size_t		i;
	size_t		start;
	size_t		index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else if (s[i] != ' ')
		{
			start = i;
			while (s[i] && s[i] != ' ')
				i++;
			tab[index] = ft_strsub(s, start, i - start);
			index++;
			tab[index] = NULL;
		}
	}
	tab[index] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_nbremots(s) + 1))))
		return (NULL);
	ft_bzero(tab, (ft_nbremots(s) + 1));
	return (ft_remplissage(s, tab));
}

int		main(int argc, char **argv)
{
	char **split;
	int len;
	int i;

	i = 1;
	
	if (argc != 2)
		ft_putchar('\n');
	else
	{
		split = ft_strsplit(argv[1]);
		len = ft_strlent(split);
		while (i < len)
		{
			ft_putstr(split[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putstr(split[0]);
		ft_putchar('\n');
	}
	return (0);
}
