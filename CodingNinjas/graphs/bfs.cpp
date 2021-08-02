#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int** matrix, int n , bool* visited)
{
    queue<int> m;
    m.push(0);
    visited[0] = true;
    int i = 0;

    while(m.size() != 0)
    {
        int x = m.front();
        cout << m.front();
        visited[x] = true;
        m.pop();
        for(int i = 0; i < n; i++)
        {
        if((matrix[x][i] != 0) && (!visited[i]))
        {
            m.push(matrix[x][i]);
            visited[i] = true;
        }
        

    }
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
    
    bool* visited = new bool[n];
    bfs(matrix, n, visited);

}