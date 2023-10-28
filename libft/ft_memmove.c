/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:02:45 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:49:16 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;
	size_t			i;

	i = 0;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if (cast_src < cast_dest)
	{
		while (n--)
		{
			cast_dest[n] = cast_src[n];
		}
	}
	else
	{
		ft_memcpy(cast_dest, cast_src, n);
	}
	return (cast_dest);
}

// int    main()
// {
//     char dest[] = "oldstring";
//    const char src[]  = "newstring";

//    memmove(dest, src, 9);
//    printf("After memmove  orignal dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, 9);
//    printf("After my memmove dest = %s, src = %s\n", dest, src);
// }
