/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:43:27 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/01 14:11:23 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		power(int n, int pow)
{
	int nb;

	nb = 1;
	while (pow > 0)
	{
		nb = nb * n;
		pow--;
	}
	return (nb);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int		ft_length(int nb)
{
	int ct;

	ct = 0;
	if (nb < 0)
		return (1 + ft_length(-nb));
	else if (nb == 0)
		return (1);
	else
	{
		while (nb > 0)
		{
			nb = nb / 10;
			ct++;
		}
	}
		return (ct);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;
	int		l;
	
	l = ft_strlen(s1);
	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	while (i < l)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int nbr)
{
	int i;
	char *str;
	int len;
	char c;


	if (nbr == -1 * power(2, 31))
			return (ft_strdup("-2147483648"));
	len = ft_length(nbr);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nbr < 0)
	{	
		str[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
		i = len - 1;
		while (i >= 0 && nbr > 0)
		{
			str[i]= nbr % 10 + '0';
			nbr = nbr / 10;
			i--;
		}
		str[len] = '\0';
	return (str);
}

int		main(int argc, char **argv)
{
	int nb;
	char *str;

	str = ft_itoa(-1 * power(2, 31));
	str = ft_itoa(-12135420);
	printf("%s\n", str);
	return (0);
}
