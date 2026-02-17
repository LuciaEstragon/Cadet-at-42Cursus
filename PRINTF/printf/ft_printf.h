/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:45:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/09 19:10:30 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include "libft/libft.h"

int			ft_printf(char const *s, ...);
static int	function_types(char const *s, va_list arg);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putstr_free(char *str);
int			ft_putnbr(int nb);
int			ft_putnbr_pos(unsigned int nb);
char		*ft_itoa_base(int n, char *base_set);
char		*ft_itoa_base_ptr(unsigned long long nb, char *base_set);

#endif
