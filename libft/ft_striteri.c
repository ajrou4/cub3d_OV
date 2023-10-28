/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:10:18 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:53:13 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// void myf(unsigned int i , char *s)
// {
// 	if(i > 2)
// 	{
// 		s[i] = 'X';
// 	}
// }
// #include<stdio.h>

// int main()
// {
// 	char str[] ="hassan";

//   ft_striteri(str,myf);
//   printf("%s\n",str);

// }
