/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:51:36 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/08 11:50:32 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	*ft_memset(void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	//while (i < n)
	//{
	//	src[i] = c;
	//	i++;
	//}
	ft_putstr(src);
	//src[0] = c;
	//src[n] = c;
	c=0;
	n=0;
	return ((void*)src);
}

int	main (void)
{
	char	*src;
       
	src = "Hola Lucia";
	//ft_memset(src, 'X', 5);
	ft_putstr(src);
	ft_putstr(ft_memset(src, 'X', 5));
	return (0);
}
