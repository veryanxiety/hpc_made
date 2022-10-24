#ifndef ALGORITHMSLIST_H
#define ALGORITHMSLIST_H

double **MatrixMult_ijk(double **matrix1, double **matrix2, int n, int m, int p);

double **MatrixMult_kij(double **matrix1, double **matrix2, int n, int m, int p);

double **MatrixMult_jki(double **matrix1, double **matrix2, int n, int m, int p);

using FuncMatrixMul = std::function<double** (double**, double**, int, int, int)>;


#endif
