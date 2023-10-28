/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:57:39 by majrou            #+#    #+#             */
/*   Updated: 2022/10/28 04:48:09 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cast_c;
	char	*cast_str;
	int		i;

	i = 0;
	cast_str = (char *)str;
	cast_c = (unsigned char)c;
	while (cast_str[i] && cast_str[i] != cast_c)
		i++;
	if (cast_str[i] == cast_c)
		return (&cast_str[i]);
	return (0);
}

// int	main()
// {
// 	char hhh[] = "ana mkwda 3lia";
// 	char *c = ft_strchr(hhh, 'a');
// 	printf("%s", c);
// }
