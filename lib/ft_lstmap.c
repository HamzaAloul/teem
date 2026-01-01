/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halalul <halalul@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:35:54 by halalul           #+#    #+#             */
/*   Updated: 2025/12/13 15:36:31 by halalul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop(t_list **list, t_list **nude, t_list **mid)
{
	(*nude)->next = NULL;
	if (!(*list))
	{
		*list = *nude;
		*mid = *nude;
	}
	else
	{
		(*mid)->next = *nude;
		*mid = (*mid)->next;
	}
}

static t_list	*clear(void (*del)(void *), t_list **list)
{
	ft_lstclear(list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*nude;
	t_list	*mid;

	mid = NULL;
	list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		nude = malloc(sizeof(t_list));
		if (!nude)
			return (clear(del, &list));
		nude->content = f(lst->content);
		if (!nude->content)
		{
			free(nude);
			ft_lstclear(&list, del);
			return (NULL);
		}
		loop(&list, &nude, &mid);
		lst = lst->next;
	}
	return (list);
}
