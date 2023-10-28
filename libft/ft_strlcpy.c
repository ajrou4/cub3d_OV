/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:59:24 by majrou            #+#    #+#             */
/*   Updated: 2022/10/27 00:29:24 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)src;
	if (size == 0)
	{
		while (s[i])
		{
			i++;
		}
		return (i);
	}
	while (s[i] != '\0' && i < size - 1)
	{
		dest[i] = s[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*int main()
{

        char src[27] = "Dans cette première partie";
        char dest[27];

        printf("%ld\n",ft_strlcpy(dest, src,0));

        printf("%s\n", dest);

}*/
