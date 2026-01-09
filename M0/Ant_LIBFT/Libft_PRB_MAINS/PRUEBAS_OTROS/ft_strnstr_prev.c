/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:26 by lestrada          #+#    #+#             */
/*   Updated: 2025/07/01 13:48:13 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	*ft_strstr(char *str, char *to_find)
{
	int	ind;
	int	ind_check;
	int	sub_ind;

	ind = 0;
	while (to_find[ind] == '\0')
	{
		return (str);
	}
	while (str[ind] != '\0')
	{
		ind_check = ind;
		sub_ind = 0;
		while (str[ind_check] == to_find[sub_ind])
		{
			sub_ind++;
			ind_check++;
			if (to_find[sub_ind] == '\0')
			{
				//return (&str[ind]);
				//poner codigo para que se acuerde de la ultima coincidencia
			}
		}
		ind++;
	}
	return (NULL);
}
