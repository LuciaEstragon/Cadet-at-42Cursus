/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 08:16:27 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/14 16:09:51 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *scr, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)scr;
	i = 0;
	while (ptr[i] != '\0' || i <= n)
	{
		if (ptr[i] == c)
			return ((void *)ptr);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)ptr);
	return ((void *)0);
}
