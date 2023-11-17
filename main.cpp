#include <iostream>
 
int main()
{
    int m, n;
    std::cin >> m >> n;
 
    int **mtrx = new int*[m];
    for(int i=0; i<m; i++)
    {
        mtrx[i] = new int [n];
        for(int j=0; j<n; j++)
        {
            mtrx[i][j] = rand()%2;
            std::cout << mtrx[i][j];
        }
        std::cout << "\n";
    }
 
    for(int i=0; i<m; i++)
        delete [] mtrx[i];
    delete [] mtrx;
 
return 0;
}
