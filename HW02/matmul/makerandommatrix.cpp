#ifndef MAKE_RANDOM_MATRIX
#define MAKE_RANDOM_MATRIX


#include <cstdlib>
#include <ctime>

double **MakeRandomMatrix(int n, int m)
{
	std::srand(std::time(nullptr));

	double **matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			matrix[i][j] = std::rand() / RAND_MAX;
		}
	}

	return matrix;
}

#endif
