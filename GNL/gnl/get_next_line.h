/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:26:15 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/27 11:26:50 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int file);
char	*read_file(int file, char *save);
char	*make_line(char **save);
/*      ---             utils   ---     */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *save, int character);
void	*ft_calloc(unsigned long int size, unsigned long int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

#endif
