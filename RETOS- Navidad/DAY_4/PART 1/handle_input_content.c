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

void find_numb(char *input)
{
	int row = 0; //x
	int col = 0; //y
	char **matrix;
	write(1, "ENTRA! \n", 8);
	printf("Lo que veo en el archivo: %c%c%c%c-----%c%c%c%c%c%c NADA \n\n", input[0], input[1], input[2],input[3],input[8], input[9], input[10],input[11], input[12],input[13]);
	int ind = 0;
	while (input[ind] != '\0')
	{
		row++;
		while (input[ind] != '\n')
		{
			//printf("-%c", input[ind]);
			col++;
			ind++;
		}
		ind++;
	}
	printf("row %d, col %d", row, col);
	matrix = (char **)malloc(row * sizeof(char *) + 1);
	if (!matrix)
        return;
	ind = 0;
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++) 
		{
			printf("i %d, j %d \n", i, j);
			matrix[i] = (char *)malloc(col * sizeof(char));
			if (!matrix[i])
			{
				while (i-- > 0)
                free(matrix[i]);
        		free(matrix);
        		return;
			}
			matrix[i][j] = input[ind];
			ind++;
		}
		ind++;
	}

	//LEER LA MATRIZ
	printf("matrix[0,0][0,1][0,2] = %c %c %c\n", matrix[0][0], matrix[0][1], matrix[0][2]);
	printf("matrix[0,0][1,0][2,0] = %c %c %c\n", matrix[0][0], matrix[1][0], matrix[2][0]);

	printf("LA MATRIZ COMPLETA\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) 
			printf("%c", matrix[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("\n RESULTADO: UP_TO_YOU \n");
}
