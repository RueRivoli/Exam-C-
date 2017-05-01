#include <stdio.h>
#include <stdlib.h>


/*clang ft_list_remove_if.c
 *./a.out
 */
typedef struct s_list t_list;
struct s_list
{
	int data;
	t_list *next;
};

void	add_elem(t_list **test, int data)
{
	t_list	*l;
	t_list	*new_elem;

	l = *test;
	new_elem = malloc(sizeof(t_list));
	while (l->next)
	{
		l = l->next;
	}
	new_elem->data = data;
	new_elem->next = NULL;

	l->next = new_elem;
}

void	new_elem(t_list **test)
{
	*test = malloc(sizeof(t_list));
	(*test)->data = 42;
	(*test)->next = NULL;
}


void	ft_list_remove_if_rec(t_list **begin_list, int *data_ref)
{
	t_list *free_me;

	if (*begin_list)
	{
		if ((*begin_list)->data == *data_ref)
		{
			free_me = *begin_list;
			*begin_list = (*begin_list)->next;
			free(free_me);
			ft_list_remove_if(begin_list, data_ref);
		}
		else
			ft_list_remove_if(&(*begin_list)->next, data_ref);
	}
}

void	ft_list_remove_if_ite(t_list **begin_list, int *data_ref)
{
	t_list		*tmp;
	t_list		*i;

	while (*begin_list && (*begin_list)->data == *data_ref)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (i->next->data ==  *data_ref)
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}

int main(void)
{
	t_list		*test;
	int		nb;

	nb = 43;
	new_elem(&test);
	add_elem(&test, 43);
	add_elem(&test, 44);
	ft_list_remove_if_ite(&test, &nb);
	while (test)
	{
		printf("[%d]-", test->data);
		test = test->next;
	}
	printf("\n");
	return (0);
}
