/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:13:12 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:46:58 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int nbr)
{
	if (!nbr)
		return (0);
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len(n);
	str = (char *)malloc(sizeof(char ) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		i--;
		str[i] = ft_check(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

//  int	main()
//  {
//  	char	*i1 = ft_itoa(-677);
// // 	char	*i2 = ft_itoa(156);
//  	char	*i3 = ft_itoa(-1);
// 	printf("%c",i1[0]);
//  	printf ("%d\n", strcmp(i1,"59"));
// // 	printf ("%d\n", strcmp(i2,"156"));
//  	printf ("%d\n", strcmp(i3,"5"));
//  }
