#ifndef MATRIX_MULT_JKI
#define MATRIX_MULT_JKI

#include "makezeromatrix.cpp"

double **MatrixMult_jki(double **matrix1, double **matrix2, int n, int m, int p)
{
	double **result = MakeZeroMatrix(n, p);
	for (int j = 0; j < p; j++)
	{
		for (int k = 0; k < m; k++)
		{
			for (int i = 0; i < n; i++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}

#endif
