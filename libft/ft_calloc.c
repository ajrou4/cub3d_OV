/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:04:54 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:46:16 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero (ptr, count * size);
	return (ptr);
}

/*int main(void)
{
char *j;

	j = ft_calloc(4,sizeof(char));
	int i = 0;
	while(i < 4)
	{
		printf("%d\n",j[i]);
		i++;
	}
	free(j);
}*/
