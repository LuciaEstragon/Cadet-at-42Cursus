/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:26:59 by lestrada          #+#    #+#             */
/*   Updated: 2025/06/25 18:31:22 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	ind;

	ind = 0;
	while ((ind < n) && (src[ind] != '\0'))
	{
		dest[ind] = src[ind];
		ind++;
	}
	while (ind < n)
	{
		dest[ind] = '\0';
		ind++;
	}
	return (dest);
}
