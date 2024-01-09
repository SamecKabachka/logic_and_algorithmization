#include <iostream>
#include <queue>

using namespace std;


void fc (int **mtrx, int n, bool *mas)
{    
    queue <int> q;
    mas[0] = 1;
    q.push(1);
    for(int i = 0; i < n; i++)
        
        for(int j = 0; j < n; j++)
        {
            if(mtrx[i][j] == 1 and  mas[j] != 1)
            {
                ;
                mas[j] = 1;
            }
        }
}

int main()
{
    int m, tmp=0, col = 0;
    queue<int> Que;
    cout<<"введите количество вершин (целое положительное цисло)"<<endl;
    cin >> m;
    
    

    int **mtrx = new int*[m], **mtrx2 = new int*[m]{0};
    for(int i = 0; i < m; i++) mtrx[i] = new int[m];



    for(int i = 0; i<m; i++)
    {        
        for(int j = i; j<m; j++)
        { 
            if(j != i)
            {
                int rez = rand()%2;
                mtrx[i][j] = rez;
                mtrx[j][i] = rez;
                tmp += rez;
            }
        }
    }
    
    for(int i = 0; i < m; i++) mtrx2[i] = new int[tmp]{0};

    bool *mas = new bool[tmp]{false};


    for(int i = 0; i < m; i++)
        for(int j = i; j < m; j++)
        {
            if(mtrx[i][j] == 1)
            {
                mtrx2[i][col] = 1;
                mtrx2[j][col] = 1;
                col++;
            }
        }

cout<<"матрица смежности"<<endl;

    for(int i = 0; i<m;i++)
    {
        for(int j = 0; j<m;j++)
        {
            cout<<"["<<mtrx[i][j]<<"] ";
        }
        cout<<endl;
    }
 
    
cout<<"матрица инцидентности"<<endl;      
    
    for(int i = 0; i<m;i++)
    {
        for(int j = 0; j<col;j++)
        {
            cout<<"["<<mtrx2[i][j]<<"] ";
        }
        cout<<endl;
    }

    fc(mtrx, m, mas);
    cout<<endl;

return 0;
}
