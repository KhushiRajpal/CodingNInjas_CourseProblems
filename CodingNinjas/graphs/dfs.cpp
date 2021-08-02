#include <iostream>
#include <queue>
using namespace std;

void dfsprinter(int** matrix, int n ,int sv, bool* checker)
{
    cout << sv << endl;
    checker[sv] = true;

    for(int i = 0; i < n ; i++)
    {
        cout << i;
        if(i == sv)
            continue;
        if(matrix[sv][i])
        {
            if(!checker[sv])
                dfsprinter(matrix, n , i , checker);
        }

        
    }

}

void bfsPrinter(int** matrix, int n , int sv, bool* visited)
{
    //go to one sv store matrix[sv][i] in queue 
     queue<int> temp;
     temp.push(sv);
     while(temp.size() != 0)
     {
         cout << temp.front();
         temp.pop();
         for(int i = 0; i < n; i++)
         {
             if(matrix[sv][i] == 1)
             {
                 if(!visited[i])
                 {
                 temp.push(i);
                 visited[i] = true;
                 }
             }
            
                  
                
         }
     }

     
}

void dfs(int** matrix, int n)
{
    bool* checker = new bool[n];
    for(int i = 0; i < n; i++)
    {
        if(!checker[i])
        {
            dfsprinter(matrix, n, i, checker);
        }
    }

}
    
void bfs(int** matrix, int n)
{
    bool* checker = new bool[n];
    for(int i = 0; i < n; i++)
    {
        checker[i]= false;
    }
    for(int i = 0; i < n; i++)
    {
        if(!checker[i])
        {
            dfsprinter(matrix, n, 0, checker);
        }
    }

}

bool haspath(int** matrix, int n, int s, int e)
{
    bool* checker = new bool[n];
    for(int i = 0; i < n; i++)
    {
        checker[i]= false;
    }
    //if there's a path from start to end
    //  
    for(int i = 0 ; i < n ; i++)
    {
        if(matrix[i][s] == e)
            return true;
        for(int j = 0; j < n;j++)
        {
            if(matrix[i][j] == 1)
                haspath(matrix, n, s, e);
        }
        
    }
    return false;

}


int main()
{
    int n;
    int a, b;
    cin >> n;
    int** matrix  = new int*[n];
  
    
    for(int i = 0; i < n ; i++)
    {
        matrix[i] = new int[n];
        for(int j = 0; j < n ; j++)
        {
            matrix[i][j] = 0;
        }


    }
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        cout << "The value of a is :" << a;
        cout << "The value of B is : " << b << endl;

        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    bool* checker = new bool[n];
    dfs(matrix , n);
    bfs(matrix , n);

}