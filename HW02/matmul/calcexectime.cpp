#ifndef CALC_EXEC_TIME
#define CALC_EXEC_TIME

#include <stdio.h>
#include <functional>
#include <time.h>


void CalcExecTime(int n, int m, int k, int nRuns)
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
