#ifndef PRINT_MATRIX
#define PRINT_MATRIX

#include <stdio.h>

void PrintMatrix(double **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		printf("%f", matrix[i][0]);
		for (int j = 1; j < m; j++)
		{
			printf(" %f", matrix[i][j]);
		}
		printf("\n");
	}
}

#endif
