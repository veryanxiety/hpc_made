#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_set>

const int MAXRAND = 1000001;
const double THRASHOLD = 0.6;
int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    if (argc <= 1)
    {
		std::cout << "usage " << argv[0] << "MatrixSize [DenseFactor (nEdges / maxPossibleEdges = n * (n-1))]!";
		return 0;
    }

    std::srand(std::time(nullptr));
    int nVertex = atoi(argv[1]);
    double df = (double) (std::rand() % MAXRAND) / MAXRAND;
    if (argc >= 3)
        df = atof(argv[2]);

    //std::cout << df << ' ' << int(nVertex * (nVertex - 1) * df) << '\n';
    std::cout << nVertex << '\n';
    if (df < THRASHOLD)
    {
        int nEdges = int(nVertex * (nVertex - 1) * df);
        std::unordered_set<int> checkEdges;

        for (size_t i = 0; i < nEdges; i++)
        {
            int x = std::rand() % nVertex;
            int y = std::rand() % nVertex;
            while (x == y || checkEdges.find(x * nVertex + y) != checkEdges.end())
            {
                x = std::rand() % nVertex;
                y = std::rand() % nVertex;                
            }
            std::cout << x << ' ' << y << '\n';
            checkEdges.insert(x * nVertex + y);
        }
    }
    else
    {
        for (size_t i = 0; i < nVertex; i++)
        {
            for (size_t j = 0; j < nVertex; j++)
            {
                double p = (double) (std::rand() % MAXRAND) / MAXRAND;
                if (i != j && p < df)
                    std::cout << i << ' ' << j << '\n';
            }
        }
    }

    return 0;
}