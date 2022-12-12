#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <omp.h>

int fastintsqrt(int n)
{
    int left = 0;
    int right = n;
    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if ((long long int) mid * mid < n)
            left = mid;
        else
            right = mid;
    }
    return right;
}

void printMatrix(std::vector<double> &matrix)
{
    int n = fastintsqrt(matrix.size());

    for (size_t i = 0; i < n; i++)
    {
        std::cout << matrix[i * n];
        for (size_t j = 1; j < n; j++)
            std::cout << ' ' << matrix[i * n + j];
        std::cout << '\n';
        
    }
}

void matrixMultMatrix(std::vector<double> &mat1, std::vector<double> &mat2, std::vector<double> &result)
{
    int n = fastintsqrt(mat1.size());

    int i, j, k;
    #pragma omp parallel for private(i, j, k)
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				result[i * n + j] += mat1[i * n + k] * mat2[k * n + j];
			}
		}
	}
}

void matrixPower(std::vector<double> &matrix, int n, std::vector<double> &result)
{
    if (n == 1)
    {
        result = matrix;
        return;
    }

    int size = fastintsqrt(matrix.size());

    if (n & 1)
    {
        std::vector<double> temp1(size * size, 0.0);
        std::vector<double> temp2(size * size, 0.0);
        matrixPower(matrix, n - 1, temp1);       
        matrixMultMatrix(matrix, temp1, temp2);
        result = temp2;
        return;
    }

    std::vector<double> matrix2(size * size, 0.0);
    matrixPower(matrix, n / 2, matrix2);
    std::vector<double> temp(size * size, 0.0);
    matrixMultMatrix(matrix2, matrix2, temp);
    result = temp;
}

void matrixMultScalar(std::vector<double> &matrix, double k)
{
    int n = matrix.size();
    int i;

    #pragma omp parallel for private(i)
    for (i = 0; i < n; i++)
        matrix[i] *= k;

}

void matrixAddScalar(std::vector<double> &matrix, double k)
{
    int n = matrix.size();
    int i;

    #pragma omp parallel for private(i)
    for (i = 0; i < n; i++)
        matrix[i] += k;

}

void matrixMultVector(std::vector<double> &matrix, std::vector<double> &vector, std::vector<double> &result)
{
    int n = fastintsqrt(matrix.size());
    int i, j;

    #pragma omp parallel for private(i, j)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result[i] += matrix[i * n + j] * vector[j];
}

void matrixNormalize(std::vector<double> &matrix)
{
    int nElems = matrix.size();
    int n = fastintsqrt(nElems);
    std::vector<double> totalCol(n, 0.0);
    int i;

    #pragma omp parallel for private(i)
    for (i = 0; i < nElems; i++)
        totalCol[i % n] += matrix[i];

    #pragma omp parallel for private(i)
    for (i = 0; i < nElems; i++)
        matrix[i] /= totalCol[i % n];
}

void matrixSumColumns(std::vector<double> &matrix, std::vector<double> &result)
{
    int nElems = matrix.size();
    int n = fastintsqrt(nElems);
    int i;

    #pragma omp parallel for private(i)
    for (i = 0; i < nElems; i++)
        result[i % n] += matrix[i];
}

int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const double D = 0.95;
    const int NITERS = 250;

    int nStations;
    std::unordered_map<int, std::string> stations;
    std::unordered_map<int, int> mapNumId;
     std::unordered_map<int, int> mapIdNum;   
    std::cin >> nStations;
    for (int i = 0; i < nStations; i++)
    {
        std::string s;
        int id;
        std::cin >> id >> s;
        stations[id] = s;
        mapIdNum[id] = i;
        mapNumId[i] = id;
    }

    std::vector<double> matrix(nStations * nStations, 0.0);
    int from, to;
    while (std::cin >> from >> to)
    {
        int x = mapIdNum[from];
        int y = mapIdNum[to];
        matrix[x * nStations + y] = 1.0;
        matrix[y * nStations + x] = 1.0;
    }
    std::vector<double> naive(nStations, 0.0);
    matrixSumColumns(matrix, naive);

    matrixNormalize(matrix);
    matrixMultScalar(matrix, D);
    matrixAddScalar(matrix, (1.0 - D) / (double) nStations);
    std::vector<double> matrixn(nStations * nStations, 0.0);
    matrixPower(matrix, NITERS, matrixn);

    std::vector<double> ones(nStations, 0.0);
    matrixAddScalar(ones, 1.0 / nStations);
    std::vector<double> pagerank(nStations, 0.0);
    matrixMultVector(matrixn, ones, pagerank);

    std::cout << "Pagerank results vs naive\n";
    for (int i = 0; i < nStations; i++)
        std::cout << stations[mapNumId[i]] << ": PR is " << pagerank[i] << " vs Naive is " << naive[i] << '\n';

    std::vector<std::pair<double, std::string> > rating(nStations);
    for (int i = 0; i < nStations; i++)
    {
        auto p = std::make_pair(pagerank[i], stations[mapNumId[i]]);
        rating[i] = p;
    }
    std::sort(rating.begin(), rating.end());

    const int TOPN = 20;
    std::cout << "TOP" << TOPN << " pagerank\n";
    for (int i = 0; i < TOPN; i++)
        std::cout << i + 1 << ". " << rating[nStations - 1 - i].second << " PR is " << rating[nStations - 1 - i].first << '\n';

    std::vector<std::pair<double, std::string> > naiverating(nStations);
    for (int i = 0; i < nStations; i++)
    {
        auto p = std::make_pair(naive[i], stations[mapNumId[i]]);
        naiverating[i] = p;
    }
    std::sort(naiverating.begin(), naiverating.end());

    std::cout << "TOP" << TOPN << " naive\n";
    for (int i = 0; i < TOPN; i++)
        std::cout << i + 1 << ". " << naiverating[nStations - 1 - i].second << " PR is " << naiverating[nStations - 1 - i].first << '\n';

    return 0;
}