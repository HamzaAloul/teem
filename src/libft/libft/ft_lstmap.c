/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabu-are <mabu-are@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:01:38 by mabu-are          #+#    #+#             */
/*   Updated: 2025/12/08 17:52:30 by mabu-are         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*r_lst;
	t_list	*str_begin;
	t_list	*loop;

	if (!lst || !f || !del)
		return (NULL);
	r_lst = ft_lstnew(f(lst->content));
	if (!r_lst)
		return (NULL);
	loop = lst->next;
	str_begin = r_lst;
	while (loop)
	{
		r_lst->next = ft_lstnew(f(loop->content));
		if (!r_lst->next)
		{
			ft_lstclear(&str_begin, del);
			return (NULL);
		}
		r_lst = r_lst->next;
		loop = loop->next;
	}
	return (str_begin);
}
