/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:26:15 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/27 11:26:50 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H

# include <libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_scanf(int file);
char	*read_file(int file, char *save);
char	*make_line(char **save);

#endif
