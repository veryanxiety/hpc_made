#ifndef CALC_EXEC_TIME
#define CALC_EXEC_TIME

#include <stdio.h>
#include <functional>
#include <time.h>
#include "makerandommatrix.cpp"
#include "deletematrix.cpp"

using FuncMatrixMul = std::function<double** (double**, double**, int, int, int)>;	

double CalcExecTime(FuncMatrixMul f, int n, int m, int k, int nRuns)
{
	double total_time = 0;
	for (int run = 0; run < nRuns; run++)
	{
		double **matrix1 = MakeRandomMatrix(n, m);
		double **matrix2 = MakeRandomMatrix(m, k);
		clock_t start = clock();

		double **result = f(matrix1, matrix2, n, m, k);
		
		clock_t end = clock();
		
		total_time += ((end - start) / (double)CLOCKS_PER_SEC);

		DeleteMatrix(matrix1, n, m);
		DeleteMatrix(matrix2, m, k);
		DeleteMatrix(result, n, k);
	}
	
	return total_time / nRuns;
}
#endif
