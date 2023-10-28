/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:13:46 by majrou            #+#    #+#             */
/*   Updated: 2022/10/21 20:14:05 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd (s, fd);
	ft_putchar_fd ('\n', fd);
}
// int main()
// {
// 	int fd ;
// 	fd = open("ajrou.txt", O_CREAT | O_RDWR, 777);
// 	ft_putendl_fd("ayouuuub", fd);

// }
