/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:43:31 by fgallois          #+#    #+#             */
/*   Updated: 2017/04/28 18:55:08 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int croissant(int a, int b)
{
	return (a <= b);
}

t_list		*new_list(int data)
{
	t_list *lst;
	
	lst = malloc(sizeof(t_list));
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void		add_list(t_list *lst, t_list *la)
{
	t_list *l;

	l = lst;
	while (l->next)
		l = l->next;
	l->next = la;
}

void		print_list(t_list *lst)
{
	t_list *l;

	l = lst;
	while (l)
	{
		printf("%d -> ", l->data);
		l = l->next;
	}
	printf("NULL ");
}


/*t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *x;
	t_list *tmp;

	tmp = lst;
	x = lst;
	while (*x)
	{
		tmp = x->next;
		if (cmp(x->data, tmp->data) == 0)
		{
			lst = tmp;
		}
	}
	return (x);
}*/

int		main(void)
{
	t_list *lst;
	t_list *lst2;
	t_list *lst3;

	lst = new_list(7);
	lst2 = new_list(13);
	lst3 = new_list(15);
	add_list(lst, lst2);
	add_list(lst, lst3);

	print_list(lst);
	return (0);
}
