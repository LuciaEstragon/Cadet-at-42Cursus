/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:41:41 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/26 18:59:59 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	ind;

	ind = 0;
	while (str[ind])
	{
		if ((str[ind] >= 'A' && str[ind] <= 'Z'))
			str[ind] += 32;
		ind++;
	}
	ind = 0;
	while (str[ind])
	{
		if (ind == 0 && (str[ind] >= 'a' && str[ind] <= 'z'))
			str[ind] = str[ind] - 32;
		else if ((str[ind] >= 'a') && (str[ind] <= 'z'))
		{
			if (!(str[ind - 1] >= 'a' && str[ind - 1] <= 'z')
				&& !(str[ind - 1] >= 'A' && str[ind - 1] <= 'Z')
				&& !(str[ind - 1] >= '0' && str[ind - 1] <= '9'))
				str[ind] = str[ind] - 32;
		}
		ind++;
	}
	return (str);
}
