/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:52:12 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:48:45 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;
	unsigned char	cast_c;

	i = 0;
	cast_s = (unsigned char *)s;
	cast_c = (unsigned char )c;
	while (i < n)
	{
		if (cast_s[i] == cast_c)
			return (&cast_s[i]);
		i++;
	}
	return (NULL);
}
// int main()
// {

// 	char k[] = "HAMZA";
//         char *str;
//         str =ft_memchr(k, 'A',4);
//          printf("%s\n",str);
// }
