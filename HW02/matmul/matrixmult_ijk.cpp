#ifndef MATRIX_MULT_IJK
#define MATRIX_MULT_IJK

#include "makezeromatrix.cpp"

double **MatrixMult_ijk(double **matrix1, double **matrix2, int n, int m, int p)
{
	double **result = MakeZeroMatrix(n, p);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p; j++)
		{
			for (int k = 0; k < m; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}

#endif
