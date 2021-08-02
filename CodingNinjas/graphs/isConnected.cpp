#include <iostream>
#include <queue>
#include <vector>
using namespace std;

 void isConnected(int** matrix, int s, int n,bool* &visited)
{
    visited[s] = true;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            isConnected(matrix, i, n , visited);
    }



}

 vector<int> BFS(int** matrix, int s, int n, bool*& visited)
 {
     queue<int> x ;
     vector<int> ans;
     visited[s]= true;
     x.push(s);
     while(!x.empty())
     {
        int temp = x.front();
        x.push(temp);
        x.pop();
        for(int i = 0 ; i < n ; i++)
        {
            if((matrix[s][i] == 1) && visited[i] != true)
            {
                visited[i] = true;
                x.push(i);
            }
        }
     }

     for(int i = 0 ; i < n; i++)
     {
         if(visited[i] == true)
         {
             ans.push_back(i);
             visited[i] = false;
         }  

     }
     return ans;
     
 }

int main(){
    cout << "Enter size of matrix :";
    int edges, vertices ;
    int n;
    cin >> n;
    int** matrix = new int*[n];
    for(int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
              matrix[i][j] = 0;
        }
    }

    cout << "Enter all the edges to be marked";
    
    
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a;
        cin >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    bool* visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    /*isConnected(matrix, 1, n, visited);
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            cout << " The graph is disconnected";
            return 0;
        }
    }

    cout << "The graph is connected";*/
    vector<vector<int>> final;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int> x = BFS(matrix, 0, n, visited);
            final.push_back(x);
        }
    }

    //print function for final ans

    return 0;



}