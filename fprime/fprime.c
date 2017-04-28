/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:31:01 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/10 18:43:38 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			nb_premier(int n)
{
	int i;

	i = n - 1;
	while (i > 1)
	{
		if (n % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int		factorisation(int nb)
{
	int fact;

	if (nb == 1)
		printf("1\n");
	while (nb != 1)
	{
		fact = 2;
		while (fact <= nb)
		{
			if (nb_premier(fact) == 1 && nb % fact == 0)
			{
				printf("%d", fact);
				nb = nb/fact;
				if (nb != 1)
					printf("*");
				else
					printf("\n");
			}
			else
				fact++;
		}
	}
	return (0);
}


int			main(int argc, char **argv)
{
	if (argc != 2)
		printf("\n");
	else
	{
		factorisation(atoi(argv[1]));
	}
	return (0);
}
