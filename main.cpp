#include <iostream>
#include <queue>

using namespace std;

int sum_max(int ** mtrx, int n, int m = 0)
{
    int sum = 0, max = 0, num = 0; 
    if(m == 0) m = n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i == j and mtrx[i][j] != 0) sum += 2;  
            else sum += mtrx[i][j];
        }
        if(sum < max) {max = sum; num = i;}
   }
    return num;
}

queue<int>  sum(int ** mtrx, int n, int condition, int r = 0)
{
    int sum = 0; 
    queue<int> Q;
    
    if(r == 0) r = n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<r; j++)
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
    queue<int> Que;
    cout<<"введите количество вершин (целое положительное цисло)"<<endl;
    cin >> m;
    
    

    int **mtrx = new int*[m], **mtrx2 = new int*[m]{0};
    for(int i = 0; i < m; i++) mtrx[i] = new int[m];



    for(int i = 0; i<m; i++)
    {        
        for(int j = i; j<m; j++)
        { 
                int rez = rand()%2;
                mtrx[i][j] = rez;
                mtrx[j][i] = rez;
                tmp += rez;
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
 
    Que = sum(mtrx, m, 0); 
    if(Que.empty()) cout<<"Изолированых вершин нет"<<endl;
    else
    {
        cout<<"Изолировыная/ые вершина/ы под №"<<endl;
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
        }
    }
      
    
    Que = sum(mtrx, m, 1); 
    if(Que.empty()) cout<<"концевых вершин нет"<<endl;
    else
    {
        cout<<"Изолировыная/ые вершина/ы под №"<<endl;
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
        }
    }

    cout<<"Доминирующая вершина под № "<<sum_max(mtrx, m) + 1<<endl;

    cout<<"Матрица инцидентности"<<endl;

    for(int i = 0; i<m;i++)
    {
        for(int j = 0; j<col;j++)
        {
            cout<<"["<<mtrx2[i][j]<<"] ";
        }
        cout<<endl;
    }

    
    Que = sum(mtrx2, m, 0, col); 
    if(Que.empty()) cout<<"Изолированых вершин нет"<<endl;
    else
    {
        cout<<"Изолировыная/ые вершина/ы под №"<<endl;
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
        }
    }

    Que = sum(mtrx2, m, 1, col); 
    if(Que.empty()) cout<<"концевых вершин нет"<<endl;
    else
    {
        cout<<"Концевая/ые вершина/ы под №"<<endl;
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
        }
    }

    cout<<"Доминирующая вершина под № "<<sum_max(mtrx2, m, col) + 1<<endl;
return 0;
}
