/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:37:23 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 04:02:03 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

// int main()
// {
// 	t_list *lst;
// 	t_list *tmp;

// 	lst = NULL;
// 	ft_lstadd_front(&lst, ft_lstnew(strdup("tass")));
// 	ft_lstadd_front(&lst, ft_lstnew(strdup("ayoub")));
// 	ft_lstadd_front(&lst, ft_lstnew(strdup("ajrou")));
// 	lst = ft_lstlast(lst);
// 	while (lst)
// 	{
// 	printf("%s", lst->content);
// 	lst = lst->next ;
// 	}

// }
