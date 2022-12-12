#include <iostream>
#include <vector>
#include <cstdlib>

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

void printMatrix(std::vector<int> &matrix)
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

void matrixMul(std::vector<int> &mat1, std::vector<int> &mat2, std::vector<int> &result)
{
    int n = fastintsqrt(mat1.size());

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

void matrixPower(std::vector<int> &matrix, int n, std::vector<int> &result)
{
    if (n == 1)
    {
        result = matrix;
        return;
    }

    int size = fastintsqrt(matrix.size());

    if (n & 1)
    {
        std::vector<int> temp1(size * size, 0);
        std::vector<int> temp2(size * size, 0);
        matrixPower(matrix, n - 1, temp1);  

        matrixMul(matrix, temp1, temp2);

        result = temp2;
        return;
    }
    std::vector<int> matrix2(size * size, 0);
    matrixPower(matrix, n / 2, matrix2);
    std::vector<int> temp(size * size, 0);
    matrixMul(matrix2, matrix2, temp);
    result = temp;
}

int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (argc <= 1)
    {
		std::cout << "usage " << argv[0] << " power!\n";
		return 0;
    }
    int power = atoi(argv[1]);

    int nVertex;
    std::cin >> nVertex;
    std::vector<int> matrix(nVertex * nVertex, 0);
    std::vector<int> matrixn(nVertex * nVertex, 0);
    
    int x;
    int y;
    while (std::cin >> x >> y)
        matrix[x * nVertex + y] = 1;
    
    std::cout << "A ^ 1\n";
    printMatrix(matrix);

    matrixPower(matrix, power, matrixn);

    std::cout << "A ^ " << power << "\n";
    printMatrix(matrixn);    

    return 0;
}