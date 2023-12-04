#include <iostream>
#include <queue>

using namespace std;


queue<int>  sum(int ** mtrx, int n, int condition)
{
    int sum = 0; 
    bool flag = 0;
    queue<int> Q;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum += mtrx[i][j];
        }
        if(sum == condition) Q.push(i);
   }
    return Q;
}

int main()
{
    int m, tmp=0, col = 0;
    std::cin >> m;
    
    

    int **mtrx = new int*[m], **mtrx2 = new int*[m]{0};
    for(int i = 0; i < m; i++) mtrx[i] = new int[m];



    for(int i = 0; i<m; i++)
    {        
        for(int j = i; j<m; j++)
        {
            //if(mtrx[i][j] != 1)
            {
                int rez = rand()%2;
                mtrx[i][j] = rez;
                mtrx[j][i] = rez;
                tmp += rez;
            }
        }
    }
    
    for(int i = 0; i < m; i++) mtrx2[i] = new int[tmp]{0};


    for(int i = 0; i < m; i++)
        for(int j = i; j < m; j++)
        {
            if(mtrx[i][j] == 1)
            {
                mtrx2[i][col] = 1;
                mtrx2[j][col] = 1;
                col++;
                cout<<col<<endl;
            }
        }

    for(int i = 0; i<m;i++)
    {
        for(int j = 0; j<col;j++)
        {
            cout<<"["<<mtrx2[i][j]<<"] ";
        }
        cout<<endl;
    }

    /*for(int i=0; i<m; i++)
        delete [] mtrx[i];
    delete [] mtrx;*/
 
return 0;
}
