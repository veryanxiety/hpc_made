#include <cstdlib>
#include <stdio.h>
#include "comparealgorithms.cpp"
#include "deletematrix.cpp"

int main(int argc, char **argv)
{
	const int NDIMENSIONS = 3;
	if (argc <= 1)
	{
		printf("usage %s N1 N2 ... Nk");
		return 0;
	}

	int n = argc - 1;
	int **tests = new int* [n];
	for (int i = 0; i < n; i++)
	{
		int k = atoi(argv[i + 1]);
		tests[i] = new int[NDIMENSIONS];
		for (int j = 0; j < NDIMENSIONS; j++)
			tests[i][j] = k;
	}

	CompareAlgorithms(tests);

	DeleteMatrix(tests, n, NDIMENSIONS);
	return 0;
}
