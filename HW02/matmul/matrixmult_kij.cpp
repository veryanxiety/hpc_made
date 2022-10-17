#ifndef MATRIX_MULT_KIJ
#define MATRIX_MULT_KIJ

#include "makezeromatrix.cpp"

double **MatrixMult_kij(double **matrix1, double **matrix2, int n, int m, int p)
{
	double **result = MakeZeroMatrix(n, p);
	for (int k = 0; i < m; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < p; j++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}

#endif
