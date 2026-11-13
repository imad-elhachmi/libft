/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imel-hac <imel-hac@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:19:35 by imel-hac          #+#    #+#             */
/*   Updated: 2026/10/27 16:19:39 by imel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_newlst;
	t_list	*new_lst;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	head_newlst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_lst = ft_lstnew(content);
		if (new_lst == NULL)
		{
			del(content);
			ft_lstclear(&head_newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&head_newlst, new_lst);
		lst = lst->next;
	}
	return (head_newlst);
}
