/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 17:43:31 by fgallois          #+#    #+#             */
/*   Updated: 2017/05/08 19:05:30 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int croissant(int a, int b)
{
	return (a <= b);
}

int		decroissant(int a, int b)
{
	return (a >= b);
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

static void		ft_swap(t_list *l1, t_list *l2)
{
	int mem;

	mem = l1->data;
	l1->data = l2->data;
	l2->data = mem;
}

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp;

	tmp = lst;
	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			ft_swap(lst , lst->next);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}

int		main(void)
{
	t_list *lst;
	t_list *lst2;
	t_list *lst3;
	t_list	*lst4;
	t_list	*lst5;
	t_list	*lst6;
	t_list	*lst7;
	t_list	*lst8;
	t_list	*lst9;
	t_list	*lst10;
	t_list	*lst11;

	lst = NULL;
	lst = new_list(7);
	lst2 = new_list(19);
	lst3 = new_list(15);
	lst4 = new_list(12);
	lst5 = new_list(11);
	lst6 = new_list(9);
	lst7 = new_list(0);
	lst8 = new_list(10);
	lst9 = new_list(19);
	lst10 = new_list(12);
	lst11 = new_list(1);
	add_list(lst, lst2);
	add_list(lst, lst3);
	add_list(lst, lst4);
	add_list(lst, lst5);
	add_list(lst, lst6);
	add_list(lst, lst7);
	add_list(lst, lst8);
	add_list(lst, lst9);
	add_list(lst, lst10);
	add_list(lst, lst11);
	sort_list(lst, &croissant);
	print_list(lst);
	return (0);
}
