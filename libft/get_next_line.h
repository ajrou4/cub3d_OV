/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:12:16 by majrou            #+#    #+#             */
/*   Updated: 2023/10/18 20:54:46 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char			*get_next_line(int fd);
char			*kl_substr(char const *s, unsigned int start, size_t len);
char			*kl_strjoin(char const *s1, char const *s2);
size_t			kl_strlen(const char *str);
void			*kl_memcpy(void *dest, const void *src, size_t n);
char			*kl_strdup(const char *str);
char			*my_read(int fd, char *str);
char			*kl_strchr(const char *str, int c);
char			*kl_line(char *str);

#endif
