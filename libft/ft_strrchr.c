/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:14:16 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 04:39:38 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*cast_str;

	i = ft_strlen(str);
	cast_str = (char *)str;
	while (i >= 0)
	{
		if (cast_str[i] == (char)c)
			return (&cast_str[i]);
		i--;
	}
	return (0);
}

// int	main()
// {
// 	char s[] = "ana mkwda 3lia";
// 	char *c = ft_strrchr(s, '3');
// 	printf("%s", c);
// }
