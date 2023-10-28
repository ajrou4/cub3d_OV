/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:37:10 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 03:55:16 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next;
	int		i;

	i = 0;
	next = lst;
	while (next != NULL)
	{
		next = next->next;
		i++;
	}
	return (i);
}

// int main()
// {
// 	int i;
// 	t_list *h;
// 	t_list *c;
// 	t_list *head;

// 	head = ft_lstnew("");
// 	h = ft_lstnew("hhhh");
// 	c = ft_lstnew("ooooo");

// 	head ->next = h;
// 	h->next = c;
// 	c->next = NULL;
// 	i = ft_lstsize(head);
// 	printf("%d", i);
// }
