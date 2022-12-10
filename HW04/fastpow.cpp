#include <iostream>
#include <vector>
#include <cstdlib>

void printMatrix(const int matrix [], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << matrix[i * n];
        for (size_t j = 1; j < n; j++)
            std::cout << ' ' << matrix[i * n + j];
        std::cout << '\n';
        
    }
}

std::vector<int> &matrixMul(std::vector<int> &mat1, std::vector<int> &mat2)
{
    std::vector<int> result(n * n, 0);
    
}

std::vector<int> &matrixPower(std::vector<int> &matrix, int n)
{
    if (n == 1)
        return matrix;

    if (n & 1)
        return matrixMul(matrix, matrixPower(matrix, n - 1));
    std::vector<int> matrix2(n * n, 0);
    matrix2 = matrixPower(matrix, n / 2);
    return matrixMul(matrix2, matrix2);
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
    int *matrix = new int[nVertex * nVertex];
    for (size_t i = 0; i < nVertex * nVertex; i++)
        matrix[i] = 0;
    
    int x;
    int y;
    while (std::cin >> x >> y)
        matrix[x * nVertex + y] = 1;
    
    std::cout << "A ^ 1\n";
    printMatrix(matrix, nVertex);

    matrixPower(matrix, power);

    std::cout << "A ^ " << power << "\n";
    printMatrix(matrix, nVertex);    
    
    delete [] matrix;
    return 0;
}