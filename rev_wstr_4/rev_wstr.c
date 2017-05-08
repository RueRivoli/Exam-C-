/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:25:34 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/08 14:37:53 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int		is_space(char const *str, int i)
{
	return (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\0');
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


char	*ft_strsub(char const *s, int start, int len)
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
	int	i;

	i = 0;
	compteur = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && is_space(s, i) == 0)
			compteur++;
		if (is_space(s, i) == 1 && is_space(s, i + 1) == 0)
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
		if (is_space(s, i) == 1)
			i++;
		else if (is_space(s, i) == 0)
		{
			start = i;
			while (s[i] && is_space(s, i) == 0)
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

int			main(int argc, char **argv)
{
	char **split;
	int len;

	if (argc != 2)
		ft_putchar('\n');
	else
	{
		split = ft_strsplit(argv[1]);
		len = ft_strlent(split);
		if (!split || len == 0)
			ft_putchar('\n');
		else
		{
			while (len--)
			{
				ft_putstr(split[len]);
				if (len > 0)
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
	}
	return (0);
}
