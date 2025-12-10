/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lestrada <lestrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:30:16 by lestrada          #+#    #+#             */
/*   Updated: 2025/12/02 15:06:54 by lestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void find_numb(char *input)
{
	int code = 50;
	long count = 0;
	int numero = 0;
	int code_ant = 50;
	int neg = 1;
	int dig = 1;

	int ind = 0;
	int sub_ind = 0;
	write(1, "ENTRA! \n\n", 11);
	while (input[ind] != '\0')
	{
		sub_ind = 0;
		neg = 1;
		dig = 1;
		numero = 0;
		while (input[ind] != '\n' /*|| input[ind] != '\0'*/)
		{
			sub_ind++;
			ind++;
		}
		
		if (input[ind - sub_ind] == 'L')
			neg = -1;
		//printf("es neg? %d \n", neg);
		//printf("sub_ind = %d \n", sub_ind);
		//printf("ind = %d \n", ind);
		int contar = 1;
		while (sub_ind - 1 != 0)
		{
			char caracter = input[ind - contar];
			int num = caracter - '0';
			numero = numero + (num)*dig;
			dig = 10 * dig;
			sub_ind--;
			contar++;
		}
		numero = numero * neg;
		printf("numero = %d \n", numero);
		code = code + numero;
		printf("code ant = %d \n", code_ant);
		int flag = 0;
		while (code > 99 || code < 0)// (code !=0)
		{
			if (code > 99)
				code -= 100;
			if (code < 0)
				code += 100;
			/* SEGUNDO EJERCICIO */
			if((flag==0 && code_ant==0) || code==0)
			{
				flag=1; //para evitar este bucle
				printf(" code_ant==0 o se va a subar luego code==0\n");
			}else
			{
				printf(" === CUENTA 0 === \n");
				count++;
			}
		}
		/* PRIMER EJERCICIO */
		if(code == 0)
		{
			count++;
			printf(" === CUENTA 0 cuando pasa por el cero === \n");
			if(flag==1)
			count++;
		}
		/* SEGUNDO EJERCICIO */
		code_ant = code;
		printf("code = %d \n", code);
		ind++;

		printf("\n COUNT RONDA: %ld \n", count);
	}

	printf("\n RESULTADO: %ld \n", count);

	printf("\n RESULTADO: FIN OK\n");
	
}
