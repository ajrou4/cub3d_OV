/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:40:53 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 02:55:09 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	free(content);
}
int main()
{
	t_list	*a;
	t_list	*b;
	t_list	*head;
	a = ft_lstnew(ft_strdup("JAMAICA  RGRDFGDFG"));
	b = ft_lstnew(ft_strdup("FDGDFGDFG JAMAICA"));
	a->next = b;
	head = a;
	ft_lstdelone(head, del);
	while (head)
	{
		printf("%s", head->content);
		head = head->next;
	}
}
*/
