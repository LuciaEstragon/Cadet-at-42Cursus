/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:38:24 by igomez-c          #+#    #+#             */
/*   Updated: 2025/12/02 12:17:59 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_file_content.h"

int	handle_file_content(char *file, char *dictionary)
{
	char	buffer[165000];
	int		file_read;

	file_read = open_and_read_file(file, buffer, 165000);
	if (file_read == -1)
		return (-1);
	copy_string(dictionary, buffer);
	return (1);
}

int	open_and_read_file(char *file, char *buffer, int b_size)
{
	int	file_ref;
	int	file_read;

	file_ref = open(file, O_RDONLY);
	if (file_ref == -1)
		return (-1);
	file_read = read(file_ref, buffer, b_size - 1);
	if (file_read == -1)
	{
		close(file_ref);
		return (-1);
	}
	buffer[file_read] = '\0';
	close(file_ref);
	return (file_read);
}

void	copy_string(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
