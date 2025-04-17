/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:18:23 by tkok-kea          #+#    #+#             */
/*   Updated: 2025/04/17 22:28:01 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* adds new element to a linked list into
 * their sorted position based on a comparision function */
void	lstadd_sorted(t_list **lst, t_list *new, int (*cmp)(t_list *, t_list *))
{
	t_list		*curr;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		curr = *lst;
		if (!cmp(new, curr))
		{
			new->next = curr;
			*lst = new;
		}
		else
		{
			while (curr->next && cmp(new, curr->next))
				curr = curr->next;
			new->next = curr->next;
			curr->next = new;
		}
	}
}

//look for a certain content in the list and returns its index
int	lstfind(t_list *lst, void *target)
{
	t_list	*ptr;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	ptr = lst;
	while (ptr)
	{
		if (ptr->content == target)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (0);
}

// find and delete the node matching target content
void	lstfind_and_del(t_list **lst, void *target)
{
	t_list	*curr;
	t_list	*prev;

	curr = *lst;
	prev = NULL;
	while (curr)
	{
		if (curr->content == target)
		{
			if (prev != NULL)
				prev->next = curr->next;
			else
				*lst = curr->next;
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

//do nothing. to be passed to ft_lstclear instead of free
void	nothing(void *ptr)
{
	(void)ptr;
	return ;
}
