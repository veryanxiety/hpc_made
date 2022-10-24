#ifndef COMPARE_ALGORITHMS
#define COMPARE_ALGORITHMS

#include <functional>
#include <string>
#include "calcexectime.cpp"
#include "algorithmslist.h"

void CompareAlgorithms(int **tests)
{
	struct algorithms
	{
		FuncMatrixMul algo;
		std::string name;
	} algos [] = 
	{
		{MatrixMult_ijk, "ijk"},
		{MatrixMult_kij, "kij"},
		{MatrixMult_jki, "jki"}
	};

	
}

#endif
