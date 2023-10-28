/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:35:16 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:53:33 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (haystack == NULL && len == 0)
		return (NULL);
	while (haystack[i] && needle[j] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			while ((haystack[i + j] == needle[j]) && ((i + j) < len))
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

// it	main()
// {
// char	*s1 = "see Fuking Ass your Fuking Ass return Fuking Ass now Fuking Ass";
// char	*s2 = "your";
// printf("%s\n",ft_strnstr(s1, s2,100));
// }
