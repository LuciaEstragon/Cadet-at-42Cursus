/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_error_main.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:14:57 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/29 22:18:47 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_ERROR_MAIN_H
# define LIB_ERROR_MAIN_H

# include <unistd.h>
# include <fcntl.h>

int		ft_str_is_numeric(char *str);
int		ctrl_zero(char *nmb);
void	negative_numbers(char *src);

#endif
