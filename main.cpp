#include <iostream>
#include <queue>

using namespace std;


queue<int>  sum(int ** mtrx, int n, int condition, int r = 0)
{
    int sum = 0; 
    queue<int> Q;
    
    if(r == 0) r = n;

    for(int i=0; i<n; i++)
    {
        sum = 0;
        for(int j=0; j<r; j++)
        {
            sum += mtrx[i][j];
        }
        if(sum == condition) Q.push(i+1);
   }
    return Q;
}

int main()
{
    srand(time(NULL));
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
            if(i != j)
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
        cout<<"Изолировыная/ые вершина/ы под № ";
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
            cout<<", ";
        }
        cout<<endl;
    }
      
    
    Que = sum(mtrx, m, 1); 
    if(Que.empty()) cout<<"концевых вершин нет"<<endl;
    else
    {
        cout<<"Концевая/ые вершина/ы под № ";
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
            cout<<", ";
        }
        cout<<endl;
    }

    
    Que = sum(mtrx, m, m-1); 
    if(Que.empty()) cout<<"доминирующих вершин нет"<<endl;
    else
    {
        cout<<"Доминирующая/ие вершина/ы под № ";
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
            cout<<", ";
        }
        cout<<endl;
    }

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
        cout<<"Изолировыная/ые вершина/ы под № ";
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
            cout<<", ";
        }
        cout<<endl;
    }

    Que = sum(mtrx2, m, 1, col); 
    if(Que.empty()) cout<<"концевых вершин нет"<<endl;
    else
    {
        cout<<"Концевая/ые вершина/ы под № ";
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
            cout<<", ";
        }
        cout<<endl;
    }

    
    Que = sum(mtrx2, m, m-1, col); 
    if(Que.empty()) cout<<"доминирующих вершин нет"<<endl;
    else
    {
        cout<<"Доминирующая/ие вершина/ы под № ";
        while(1)
        {
            if(Que.empty()) break;
            cout<<Que.front();
            Que.pop();
            cout<<", ";
        }
        cout<<endl;
    }
return 0;
}
