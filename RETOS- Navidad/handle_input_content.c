/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:30:16 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/01 20:57:36 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void find_numb(char *input)
{
	int code = 55;
	int count = 0;
	int numero = 0;
	int neg = 1;
	int dig = 1;

	int ind = 0;
	int sub_ind = 0;
	write(1, "HOLA MARIA\n", 17);
	while (input[ind] != '\0')
	{
		printf("LUCIA");
		sub_ind = 0;
		neg = 1;
		dig = 1;
		numero = 0;
		// printf("Input %c %c %c %c %c %c FIN\n", input[ind], input[ind+1], input[ind+2], input[ind+3], input[ind+4], input[ind+5]);
		while (input[ind] != '\n' /*|| input[ind] != '\0'*/)
		{
			sub_ind++;
			ind++;
			// printf("SUB_INDICE %d \n", sub_ind);
		}
		printf("INDICE %d \n", ind);
		// fill_info_numb(input[ind - sub_ind], sub_ind);
		if (input[ind - sub_ind] == 'L')
			neg = -1;
		printf("%d \n", neg);
		printf("sub_ind  %d \n", sub_ind);
		printf("ind  %d \n", ind);
		/*while (sub_ind -2 != 0)
		{
			char caracter = input[sub_ind-1];
			int num = caracter -'0';
			numero = numero + (num) * dig;
			dig = 10 * dig;
			sub_ind--;
			char caracter = input[ind];
			int num = caracter -'0';
			numero = numero + (num) * dig;
			dig = 10 * dig;
			ind--;
		}*/
		int contar = 2;
		while (sub_ind - 1 != 0)
		{
			contar--;
			char caracter = input[sub_ind - 1];
			int num = caracter - '0';
			numero = numero + (num)*dig;
			dig = 10 * dig;
			sub_ind--;
		}
		printf("ind = %d \n", ind);
		numero = numero * neg;
		printf("numero = %d \n", numero);
		code = code + numero;
		// while (code > 99 && code < 0)// (code !=0)
		{
			if (code > 99)
			{
				count++;
				code -= 99;
			}
			if (code < 0)
			{
				count++;
				code += 99;
			}
		}
		printf("code = %d \n", code);
	}
	ind++;

	printf("%d", count);
}
