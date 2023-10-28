/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:26:57 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:53:41 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cast_s1;
	char	*new_str;
	size_t	len_s1;

	if (!s1 || !set)
		return (NULL);
	cast_s1 = (char *)s1;
	while (*cast_s1 && ft_strchr(set, *cast_s1))
		cast_s1++;
	len_s1 = ft_strlen(cast_s1);
	while (len_s1 && ft_strchr(set, cast_s1[len_s1]))
		len_s1--;
	new_str = ft_substr(cast_s1, 0, len_s1 +1);
	return (new_str);
}

//int main()
//{
//	const char	*s1 = "ba ter  ab";
//	const char	*s2 = "ab";
//
//    printf("%s\n", ft_strtrim(s1,s2))
//	char *hi = "***********************h*ell*lo***";
//	char *a;
//	printf("%s",ft_strtrim(hi, "*"));
//}
