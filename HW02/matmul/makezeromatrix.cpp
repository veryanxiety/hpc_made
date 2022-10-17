#ifndef MAKE_ZERO_MATRIX
#define MAKE_ZERO_MATRIX

double **MakeZeroMatrix(int n, int m)
{
	double **matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}

#endif
