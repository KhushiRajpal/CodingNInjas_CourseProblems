#include <iostream>
#include <algorithm>
using namespace std;

class edge{
    public:
    int source;
    int destination;
    int weight;
    edge(){
        source = 0;
        destination = 0;
        weight = 0;
    }

};

edge* takeinput(edge* &input, int n)
{
   
    for(int i = 0; i < n ; i++)
    {
        int source, dest, motu;
        cout << endl << "Enter source : ";
        cin >> source;
        cout << endl << "Enter destination : ";
        cin >> dest;
        cout << endl << "Enter weight : ";
        cin >> motu;
        input[i].source = source;
        input[i].destination = dest;
        input[i].weight = motu;
    }
    return input;
    
}

int findIndex(int v, int* &parent)
{
    if(parent[v] == v)
        return v;
    return findIndex(parent[v] , parent);
}

 bool comparefunc(edge a1, edge a2)
    {
      return a1.weight > a2.weight;
    }

edge* kruskal(edge* &input, int n, int e)
{
    //find min at each point 
    //create a check cycle function using union algo and call it 
    //make changes to parent
    //store these in seperate ans , keep going till n - 1
      //sort the edges from min to max based on weight
      sort(input, input+e , comparefunc);
      edge* final = new edge[n - 1];
      int* parent = new int[n];
      for(int i = 0; i < n; i++)
      {
          parent[i] = i;
      }
      
          int count = 0;
          int i = 0;
          while(count != n-1)
          {
          //take input[i].source and input[i].dest 
          //make changes in parent 
          int sourceInd = findIndex(input[i].source, parent);
          int destInd = findIndex(input[i].destination, parent);

          if(sourceInd != destInd)
          {
              //make finalans and add each edge to that
              final[count].source = input[i].source;
              final[count].destination = input[i].destination;
              final[count].weight = input[i].weight;
              parent[input[i].source] = input[i].destination;
              count++;
          }
          i++;    
          }

          for(int i = 0; i < n - 1; i++)
          {
              if(final[i].source > final[i].destination)
                cout << final[i].source << " " << final[i].destination << " " << final[i].weight;
              else
                  cout << final[i].destination << " " << final[i].source << " " << final[i].weight;
          }
    
}



int main()
{
    cout << "Enter the number of vertices";
    int n;
    cin >> n;
    cout << "Enter the number of edges : ";
    int e;
    cin >> e;
    edge* input= new edge[n];
    takeinput(input, n);
    //pass edge to kruskal's algo
    kruskal(input, n, e);

}

void print()
{
   //TODO
}

