/* ************************************************************************** *//*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:25:51 by lestrada          #+#    #+#             */
/*   Updated: 2025/10/02 16:14:25 by lestrada         ###   ########.fr       */
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

char    *ft_strchr(const char *str, int c)
{
	while (*str != c && *str != '\0')
		 str++;
	return ((void*)str);
}

char    *ft_strrchr(const char *str, int c)
{
	int	count;
       
	count = ft_strlen(str);
	str = str + count; //Aqui estaria el puntero de str al final de la cadena
	while (*str != c && count != 0)
	{
		str--;
		count--;
	}
	return ((void*)str);
}

///** NO ME SALE CON IND **/
char    *ft_strchr_IND(const char *str, int c)
{
	int	i;
	int	j;
	char	*aux = NULL;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	j = 0;
	while (str[i] != '\0')
	{
		aux[j] = str[i];
		i++;
		j++;
	}
	return (aux);
}

int	main(void)
{
	char	*msg;
	//char	ans;

	msg = "Hola lucia";
	//ans = *ft_strchr(msg, 'l');
	ft_putstr(msg);
	write(1, "\n", 1);
	ft_putstr(ft_strchr_IND(msg, 'l'));
	//ft_putstr(&ans);
	ft_putstr(msg);
	return (0);
}
