/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:37:34 by allefebv          #+#    #+#             */
/*   Updated: 2021/02/02 11:37:39 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
	#define LIBASM_H

#include <stdlib.h>

size_t 	ft_strlen(char *str);
char 	*ft_strcpy(char *dst, char *src);
int 	ft_strcmp(char *s1, char *s2);
char 	*ft_strdup(char *s1);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, const void *buf, size_t count);

#endif
