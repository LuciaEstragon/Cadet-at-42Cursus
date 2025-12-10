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
#include <stdlib.h>
#include <string.h>

int init_numbers(char *input, int *start_num, int *end_num)
{
	int i = 0;
	while (input[i] != '-')
		i++;
	start_num = (int *)malloc(i);
	i++;
	while (input[i] != ',')
		i++;
	end_num = (int *)malloc(i);
	i++;
	return (i);
}  // en esta funcion alloco los numeros de entradas

void find_numb(char *input)
{
	int *start_num;
	int *end_num;

	int ind = 0;
	int sub_ind = 0;
	int sub_ind2 = 0;
	write(1, "ENTRA! \n\n", 8);
	while (input[ind] != 'p')
	{
		int i = 0;
		while (input[i] != '-')
			i++;
		start_num = (int *)malloc(i);
		i++;
		while (input[i] != ',')
			i++;
		end_num = (int *)malloc(i);
		i++;
		/// compruebo que hasta aqui todo bien
		printf("%d%d", start_num[0], start_num[1]);
		printf("%d%d", end_num[0], end_num[1]);
	/*
		ind = init_numbers(input,start_num, end_num);
		/// compruebo que hasta aqui todo bien
		//printf("%d%d", start_num[0], start_num[1]);
		//printf("%d%d", end_num[0], end_num[1]);
		sub_ind = sizeof(start_num);
		int i = 0;
		while(sub_ind > i)
		{
			printf("%d", start_num[i]);
			i++;
		}
		sub_ind2 = sizeof(end_num);
		i = 0;
		while(sub_ind2 > i)
		{
			printf("%d", end_num[i]);
			i++;
		}
		///////////
	*/
	}

	printf("\n RESULTADO: \n");
}
