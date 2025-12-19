/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:26:04 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/29 22:50:29 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_file_content.h"
#include "handle_dictionary_content.h"
#include "lib_error_main.h"

int	main(int argn, char **argv)
{
	char	*nmb;
	char	*file_name;
	char	dictionary[1024];

	file_name = "./numbers.dict";
	if (handle_file_content(file_name, dictionary) == -1)
		write(2, "Dict Error\n", 12);
	else
		write(1, "fichero abierto\n", 17);
	if (argn == 2)
		nmb = argv[1];
	else
		return (0);
	if (ctrl_zero(nmb) != 0)
		return (1);
	negative_numbers(nmb);
	if (ft_str_is_numeric(nmb) != 0)
	{
		write(2, "Dict Error\n", 12);
		return (1);
	}
	find_numb(nmb, dictionary);
	return (0);
}

int	ctrl_zero(char *nmb)
{
	char	a;
	int		error;

	a = *nmb;
	error = 0;
	if (a == '0')
	{
		write(1, "zero", 4);
		error = 1;
	}
	return (error);
}

void	negative_numbers(char *src)
{
	int		i;
	int		len;
	char	a;
	char	*aux;

	aux = src;
	i = 0;
	len = 0;
	a = src[0];
	if (a == '-')
	{
		write(1, "(negative)", 10);
		while (src[len] != '\0')
			len++;
		while (i < len - 1)
		{
			src[i] = aux[i + 1];
			i++;
		}
		src[i] = '\0';
	}
}

int	ft_str_is_numeric(char *nmb)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	while (nmb[i] != '\0')
	{
		if (nmb[i] > 57 || nmb[i] < 48)
			error = 1;
		i++;
	}
	return (error);
}
