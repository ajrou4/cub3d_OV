/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:33:26 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 03:58:07 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

// int	main()
// {

// 	t_list *lst;
// 	t_list	*new;
// 	t_list	*node1;

// 	lst = ft_lstnew("");
// 	new = ft_lstnew("this is supposed to be the first");
// 	node1 = ft_lstnew("this is the secand");
// 	lst->next = node1;
// 	node1 ->next = NULL;

// 	ft_lstadd_front(&lst, new);
// 	while (lst)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}

// }

// int main()
// {
// 	t_list *lst;
// 	t_list *tmp;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	t_list *new;

// 	lst = NULL;
// 	node1 = ft_lstnew(strdup("tass"));
// 	node2 = ft_lstnew(strdup("zb"));
// 	node3 = ft_lstnew(strdup("bb"));
// 	new = ft_lstnew(strdup("this is supposed to be the first node"));

// 	lst -> next = node1;
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = NULL;
// 	tmp = lst;
// 	while (tmp)
// 	{
// 	printf(" before --------->: %s\n" , tmp->content);
// 	tmp = tmp->next;
// 	}
// 	tmp = lst;
// 	ft_lstadd_front(&tmp, new);

// 	while (tmp)
// 	{
// 	printf(" after ----------> : %s\n" , tmp->content);
// 	tmp = tmp->next;
// 	}
// }
