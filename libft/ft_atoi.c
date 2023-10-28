/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 03:11:26 by majrou            #+#    #+#             */
/*   Updated: 2023/10/19 17:26:41 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		result;
	int		i;

	s = (char *)str;
	i = 0;
	result = 0;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		printf("Error not a number safdsf \n");
		exit(1);
	}
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '\n')
		{
			printf("Error not a number \n");
			exit(1);
		}
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result);
}

// int main()
// {
// 	int ori;
// 	int cre;

// 	ori = atoi("-52");
// 	cre = ft_atoi("-52");
// 	printf("original atoi : %d\n", ori);
// 	printf("my atoi : %d", cre);
// }
