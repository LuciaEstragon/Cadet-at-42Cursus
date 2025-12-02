/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dictionary_content.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:26:41 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/29 23:14:31 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_DICTIONARY_CONTENT_H
# define HANDLE_DICTIONARY_CONTENT_H

# include <unistd.h>
# include <stdlib.h>

void	find_numb(char *nmb, char *dictionary);
int		print_numb(int save_ind, char *dictionary);
int		str_len(char *nmb);
void	no_printable_num(char *nmb, char *dictionary);

#endif
