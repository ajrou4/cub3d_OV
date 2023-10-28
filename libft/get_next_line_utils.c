/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:45:08 by majrou            #+#    #+#             */
/*   Updated: 2023/10/10 16:33:34 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*kl_strdup(const char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc ((kl_strlen(str) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	*kl_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cast_src;
	unsigned char	*cast_dest;

	if (!dest && ! src)
		return (NULL);
	i = 0;
	cast_src = (unsigned char *)src;
	cast_dest = (unsigned char *)dest;
	while (i < n)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	return (cast_dest);
}

char	*kl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(len +1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && start < kl_strlen (s))
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*kl_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1)
		s1 = kl_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (kl_strlen(s1) + kl_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	kl_memcpy(str, s1, kl_strlen(s1));
	kl_memcpy(str + kl_strlen(s1), s2, kl_strlen(s2));
	str[kl_strlen(s1) + kl_strlen(s2)] = '\0';
	free((char *)s1);
	return (str);
}

char	*kl_strchr(const char *str, int c)
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
