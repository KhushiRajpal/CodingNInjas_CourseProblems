#include <iostream>
#include <algorithm>

using namespace std;

int Find_min(int* weights, bool* visited, int n)
{
    int min_value = 0;
    for(int i = 0 ; i < n; i++)
    {
        if((visited[min_value] == false) && ( weights[i] < weights[min_value]))
            min_value = i;
        
    }
    return min_value;

    
}

int main(){
    // visited edges parent
    int n,e;
    cout << "Enter the no of vertices :" << endl;
    cin >> n ;
    cout << "Enter the no of edges : " << endl;
    cin >> e ;

    int** matrix = new int*[n];
    for(int i = 0; i< n; i++)
    {
        matrix[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < n ; i++)
    {
        int a = 0;
        int b = 0;
        int wei = 0;
        cout << endl << "Enter edges : " ;
        cin >> a >> b;
        cout << endl << "Enter weight for the edge";
        cin >> wei;
        matrix[a][b] = wei;
        matrix[b][a] = wei;
    }

    bool* visited = new bool[n];
    int* weights = new int[n];
    int* parent = new int[n];
    int* vertex = new int[n];
    
    for(int i= 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(matrix[i][j] != 0)
                vertex[i] = i;
        }
        weights[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    weights[0] = INT_MAX;
    // Prim's Algorithm 
    /*
    for(int i = 0 ; i < n ; i++)
    {
        int min_value = Find_min(weights, visited, n);
        visited[min_value] = true;
        for(int j = 0; j < n; j++)
        {
            if(matrix[min_value][j] != 0)
            {
                if((!visited[j]) && (matrix[min_value][j] < weights[j]))
                {
                    weights[j] = matrix[min_value][j];
                    parent[j] = min_value;
                }
            }
        }
    }
    */

   for(int i = 0; i < n; i++)
   {
       int min_value  = Find_min(weights, visited, n);
       visited[min_value] = true;
       for(int j = 0; j < n ; j++)
       {
           if((matrix[min_value][j] != 0) && (!visited[j]))
           {
               weights[j] = matrix[min_value][j] + weights[min_value];
              
           }
       }
   }

   for(int i = 0; i < n; i++)
   {
       cout << i << " " << weights[i] << endl;
   }
   delete [] visited;
   delete [] weights;
    
    // pick vertice with min weight
    // same as picking edge with min weight
    

   
    
    
    
    


    }
    

