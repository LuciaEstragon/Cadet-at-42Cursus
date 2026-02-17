/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file_content.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:30:00 by igomez-c          #+#    #+#             */
/*   Updated: 2025/12/01 19:48:27 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FILE_CONTENT_H
# define HANDLE_FILE_CONTENT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		handle_file_content(char *file, char *dictionary);
int		open_and_read_file(char *file, char *buffer, int b_size);
void	copy_string(char *dest, char *src);

#endif
