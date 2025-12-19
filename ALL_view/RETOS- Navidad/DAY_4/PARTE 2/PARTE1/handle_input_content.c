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
	int numero_max[12];
	int saltar_sub_ind;
	int ind_j = 12;

	int ind = 0;
	int sub_ind_max = 0;
	int sub_ind = 0;


	unsigned long long int  numero1 = 0;
	unsigned long long int  numero2 = 0;
	unsigned long long int  numero3 = 0;
	unsigned long long int  numero4 = 0;
	unsigned long long int  numero5 = 0;
	unsigned long long int  numero6 = 0;
	unsigned long long int  numero7 = 0;
	unsigned long long int  numero8 = 0;
	unsigned long long int  numero9 = 0;
	unsigned long long int  numero10 = 0;
	unsigned long long int  numero11 = 0;
	unsigned long long int  numero12 = 0;

	write(1, "ENTRA! \n\n", 10);
	printf("Lo que veo en el archivo: %c%c%c%c NADA \n", input[ind], input[ind+1], input[ind+2],input[ind+3]);
	while (input[ind] != 'p')
	{
		sub_ind = 0;
		sub_ind_max = 0;
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
		ind_j = 12;
		while (ind_j > 0)
		{
			ind_j--;
			printf("ind_j = %d \n", ind_j);
			int num_max = 0;
		while ((sub_ind) < (sub_ind_max - ind_j)) // el n son las lineas de entrada empezando desde el 0, -1
		{
			//printf("Num de vuelta = %d \n", sub_ind_max - sub_ind - 2);
			char caracter = input[(ind - sub_ind_max) + sub_ind];
			int num = caracter - '0';
			printf("%d(%d)", sub_ind, num);
			if (num > num_max)
			{
				num_max = num;
				saltar_sub_ind = sub_ind;
			}
			sub_ind++;
		}
		numero_max[ind_j] = num_max;
		printf("Num que lleva = %d \n", numero_max[ind_j]);
		sub_ind = 0;
		sub_ind = saltar_sub_ind +1;
	    }
		printf("\n");
		//printf("numero11 = %d \n", numero_max[11]);
		//printf("numero10 = %d \n", numero_max[10]);
		/*numero = numero_max[11] * 100000000000 +
				 numero_max[10] * 10000000000 +
				 numero_max[9]  * 1000000000 +
				 numero_max[8]  * 100000000 +
				 numero_max[7]  * 10000000 +
				 numero_max[6]  * 1000000 +
				 numero_max[5]  * 100000 +
				 numero_max[4]  * 10000 +
				 numero_max[3]  * 1000 +
				 numero_max[2]  * 100 +
				 numero_max[1]  * 10 +
				 numero_max[0]  * 1;
	*/
	/*	unsigned long long int  numero1 = numero_max[11] * 100000000000;
		unsigned long long int  numero2 = numero_max[10] * 10000000000;
		unsigned long long int  numero3 = numero_max[9]  * 1000000000;
		unsigned long long int  numero4 = numero_max[8]  * 100000000;
		unsigned long long int  numero5 = numero_max[7]  * 10000000;
		unsigned long long int  numero6 = numero_max[6]  * 1000000;
		unsigned long long int  numero7 = numero_max[5]  * 100000;
		unsigned long long int  numero8 = numero_max[4]  * 10000;
		unsigned long long int  numero9 = numero_max[3]  * 1000;
		unsigned long long int  numero10 = numero_max[2]  * 100;
		unsigned long long int  numero11 = numero_max[1]  * 10;
		unsigned long long int  numero12 = numero_max[0]  * 1;
		numero = numero1+numero2+numero3+numero4+numero5+numero6+numero7+numero8+numero9+numero10+numero11+numero12;
		printf("numero = %lld \n", numero);*/

		numero1 += numero_max[11];
		numero2 += numero_max[10];
		numero3 += numero_max[9];
		numero4 += numero_max[8];
		numero5 += numero_max[7];
		numero6 += numero_max[6];
		numero7 += numero_max[5];
		numero8 += numero_max[4];
		numero9 += numero_max[3];
		numero10 += numero_max[2];
		numero11 += numero_max[1];
		numero12 += numero_max[0];

		ind++;
	}

	printf("numero1 = %lld \n", numero1);
	printf("numero2 = %lld \n", numero2);
	printf("numero3 = %lld \n", numero3);
	printf("numero4 = %lld \n", numero4);
	printf("numero5 = %lld \n", numero5);
	printf("numero6 = %lld \n", numero6);
	printf("numero7 = %lld \n", numero7);
	printf("numero8 = %lld \n", numero8);
	printf("numero9 = %lld \n", numero9);
	printf("numero10 = %lld \n", numero10);
	printf("numero11 = %lld \n", numero11);
	printf("numero12 = %lld \n", numero12);
	//para saber el resultado hacer una suma cOn acarreos

	//	code = code + numero;
	//	printf("code = %lld \n", code);
	printf("\n RESULTADO: UP_TO_YOU \n");
}
