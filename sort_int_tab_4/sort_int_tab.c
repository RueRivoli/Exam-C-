/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:28:16 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/08 19:39:32 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlen(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int mem;

	i = 0;
	if (size == 0 || size == 1)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			mem = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = mem;
			i = 0;
		}
		else
			i++;
	}
}

void		print(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("[%d] -", tab[i]);
		i++;
	}
}

int		main(void)
{
	int *tab;

	if (!(tab = (int *)malloc(sizeof(int) * 1 + 1)))
		return (0);
	tab[0] = 1;
	/*tab[1] = 2;
	tab[2] = 5;
	tab[3] = 8;
	tab[4] = (int)0;
	tab[5] = 16;
	tab[6] = 4;
	tab[7] = 81;
	tab[8] = 18;
	tab[9] = 2;*/
	tab[1] = '\0';
	sort_int_tab(tab, ft_strlen(tab));
	print(tab);
	return (0);
}
