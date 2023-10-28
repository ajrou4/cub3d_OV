/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:00:25 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:49:19 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	char			*cast_str;
	unsigned char	cast_c;

	i = 0;
	cast_str = (char *)str;
	cast_c = (unsigned char)c;
	while (i < n)
	{
		cast_str[i] = cast_c ;
		i++;
	}
	return (cast_str);
}
/*int main()
{
char strr[20] = "ajrouune";
printf("%s\n", ft_memset(strr, 'a', 5));
printf("%s", memset(strr, 'a', 5));
}*/
