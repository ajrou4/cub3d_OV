/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:08:22 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:51:01 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static	size_t	countk(char const *s, char c)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static	void	*null_arr(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**save;

	i = 0;
	k = 0;
	save = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (s == NULL || !save)
		return (NULL);
	while (i < words(s, c))
	{
		save[i] = (char *)malloc(sizeof(char) * (countk(s + k, c) + 1));
		if (!save[i])
			return (null_arr(save));
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
			save[i][j++] = s[k++];
		save[i][j] = '\0';
		i++;
	}
	save[i] = NULL;
	return (save);
}

// int main()
// {
// 	char **arr;
// 	arr = ft_split("lorem ipsum dolor sit amet, ", ' ');
// 	int i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		printf("%s \n", arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
