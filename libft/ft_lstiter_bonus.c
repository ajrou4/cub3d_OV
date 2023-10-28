/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:33:03 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 06:33:33 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
/*
void	f(void *content)
{
	printf("%s", content);
}
int main()
{
	t_list	*a;
	t_list	*b;
	t_list	*head;
	a = ft_lstnew("TAFESR");
	b = ft_lstnew("FGDRGDFGDFG");
	a->next = b;
	head = a;
	ft_lstiter(head, f);
}
*/
