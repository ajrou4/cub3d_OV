/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:45:04 by majrou            #+#    #+#             */
/*   Updated: 2023/10/19 17:24:32 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	kl_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*my_read(int fd, char *save)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!ptr)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, ptr, BUFFER_SIZE);
		if (i != -1)
			ptr[i] = '\0';
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(save);
			save = NULL;
			break ;
		}
		save = kl_strjoin(save, ptr);
		if (kl_strchr(ptr, '\n'))
			break ;
	}
	return (free(ptr), save);
}

char	*kl_line(char *save)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = kl_substr(save, 0, i + 1);
	return (line);
}

char	*sub(char *save)
{
	char	*sub;
	size_t	i;
	size_t	len;

	sub = NULL;
	i = 0;
	len = kl_strlen(save);
	while (save[i] && save[i] != '\n')
		i++;
	if (i < len - 1)
		sub = kl_substr(save, i + 1, len);
	free(save);
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;
	str = my_read(fd, str);
	if (!str)
		return (NULL);
	line = kl_line(str);
	str = sub(str);
	return (line);
}
/*int main()
{
	int fd = open("ajrou.txt", O_RDONLY);
	//char *hello = "Hello World\n";
   	//printf("%s",get_line(hello));
	//printf("%s",sub(hello));
get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}*/
