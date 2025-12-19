/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*   Created: 2025/12/01 19:48:27 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int file);
char    *read_line(int file, char *save);
char	*make_line(char *save);
/*      ---             utils   ---     */
char    *ft_substr(char const *s, unsigned int start, size_t len);
unsigned long int       ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *save, int character);
void    *ft_calloc(unsigned long int size, unsigned long int c);


#endif
