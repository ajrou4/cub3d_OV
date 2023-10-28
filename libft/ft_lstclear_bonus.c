/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 05:11:45 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 05:49:24 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swp;

	while (*lst)
	{
		swp = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = swp;
	}
}

// void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*head;
// 	a = ft_lstnew(ft_strdup("JAMAICA  RGRDFGDFG"));
// 	b = ft_lstnew(ft_strdup("FDGDFGDFG JAMAICA"));
// 	a->next = b;
// 	head = a;
// 	ft_lstclear(&head, del);
// 	while (head)
// 	{
// 		printf("%s", head->content);
// 		head = head->next;
// 	}
// }
