/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:30:16 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:22 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void find_numb(char *input)
{
	long code = 0;
	int numero = 0;
	int numero_max1 = 0;
	int numero_max2 = 0;
	int saltar_sub_ind = 0;

	int ind = 0;
	int sub_ind_max = 0;
	int sub_ind = 0;
	write(1, "ENTRA! \n\n", 10);
	printf("Lo que veo en el archivo: %c%c%c%c NADA \n", input[ind], input[ind+1], input[ind+2],input[ind+3]);
	while (input[ind] != 'p')
	{
		sub_ind = 0;
		sub_ind_max = 0;
		numero_max1 = 0;
		numero_max2 = 0;
		numero = 0;
		printf("sub_ind_max ANTES= %d \n", sub_ind_max);
		while (input[ind] != '\n' /*|| input[ind] != '\0'*/)
		{
			sub_ind_max++;
			ind++;
		}
		printf("sub_ind_max = %d \n", sub_ind_max);
		printf("ind = %d \n", ind);
		printf("Sub_ind = ");
		//int n = 14; // n = sub_ind_max - 1
		while ((sub_ind) < (sub_ind_max - 1)) // el n son las lineas de entrada empezando desde el 0, -1
		{
			//printf("Num de vuelta = %d \n", sub_ind_max - sub_ind - 2);
			char caracter = input[ind - (sub_ind_max - sub_ind)];
			int numero1 = caracter - '0';
			printf("%d(%d)", sub_ind, numero1);
			if (numero1 > numero_max1)
			{
				numero_max1 = numero1;
				saltar_sub_ind = sub_ind;
			}
			sub_ind++;
		}
		printf("sub_ind_max = %d \n", sub_ind_max);
		sub_ind = saltar_sub_ind +1;
		//printf("sub_ind_salta = ");
		while ((sub_ind) < sub_ind_max) // el n son las lineas de entrada empezando desde el 0
		{
			char caracter = input[ind - (sub_ind_max - sub_ind)];
			int numero2 = caracter - '0';
			//printf(" %d", sub_ind);
			if (numero2 > numero_max2)
				numero_max2 = numero2;
			sub_ind++;
		}
		printf("\n");
		//printf("numero1 = %d \n", numero_max1);
		//printf("numero2 = %d \n", numero_max2);
		numero = numero_max1 * 10 + numero_max2;
		printf("numero = %d \n", numero);
		code = code + numero;
		printf("code = %ld \n", code);
		ind++;
	}

	printf("\n RESULTADO: %ld \n", code);
}
