#ifndef DELETE_MATRIX
#define DELETE_MATRIX

#include <cstdlib>

void DeleteMatrix(double **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
		delete [] matrix[i];
	delete [] matrix;
}

#endif
