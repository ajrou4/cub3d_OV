/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:26:44 by majrou            #+#    #+#             */
/*   Updated: 2022/10/19 15:32:17 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*int main()
{
	    printf("%d\n",ft_isalpha('5'));
    printf("%d\n",ft_isalpha('H'));
    printf("%d\n",ft_isalpha('&'));
    printf("%d\n",ft_isalpha('b'));
    printf("%d\n",ft_isalpha(0));
}*/
