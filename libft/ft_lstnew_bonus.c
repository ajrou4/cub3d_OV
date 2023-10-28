/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:28:58 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:48:27 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc (sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr -> content = content;
	ptr -> next = NULL;
	return (ptr);
}

// int main()
// {
// 	t_list *lst;
// 	t_list *node1;
// 	t_list *node2;
// 	// lst = ft_lstnew(strdup(""));
// 	node1 = ft_lstnew("jamaika");
// 	node2 = ft_lstnew("golum");
// 	lst -> next = node1;
// 	node1 -> next = node2;
// 	node2 -> next = NULL;
// 	while (lst)
// 	{
// 		printf("%s\n", lst->content);
// 		lst = lst->next;
// 	}
// }

// int main()
//{
//		t_list *lst;
//		t_list *node1;
//		t_list *node2;
//		t_list *node3;
//		lst = NULL;
//		node1= ft_lstnew(strdup("tass"));
//		node2= ft_lstnew(strdup("L3dem"));
//		node3= ft_lstnew(strdup("ajrou"));
//	lst ->next = node1;
//	node1 ->next = node2;
//	node2 ->next = node3;
//	node3 ->next = NULL;
//	while (lst)
//	{
//		printf("%s\n", lst->content);
//		lst = lst->next;
//	}
//}
