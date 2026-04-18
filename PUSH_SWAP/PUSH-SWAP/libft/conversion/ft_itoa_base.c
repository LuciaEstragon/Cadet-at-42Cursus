/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:06:33 by lestrada          #+#    #+#             */
/*   Updated: 2026/01/09 19:11:35 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	digit_count(long long nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		count = 1;
	while (nb != 0)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}

char	*ft_itoa_base(int n, char *base_set)
{
	char		*str;
	int			len_nmb;
	int			base;
	long long	nb;

	base = 0;
	while (base_set[base])
		base++;
	nb = n;
	if (nb < 0 && base == 16)
		nb = (unsigned int)n;
	len_nmb = digit_count(nb, base);
	str = (char *)calloc((len_nmb + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = base_set[0];
	while (nb != 0)
	{
		str[--len_nmb] = base_set[nb % base];
		nb = nb / base;
	}
	return (str);
}
