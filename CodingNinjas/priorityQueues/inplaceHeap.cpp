#include <iostream>
#include <vector>
using namespace std;

vector<int> insert(int* arr)
{
     vector<int> heap;
     int size = sizeof(arr)/sizeof(arr[0]);
     heap.push_back(arr[0]);
     for(int i = 1; i < size; i++)
     {
         heap.push_back(arr[i]);
         int parent = (i - 1) / 2 ;
         int child = i;
         while(child < size)
         {
             int temp = arr[child];
             arr[child] = arr[parent];
             arr[parent] = temp;
             if(arr[child] > arr[parent])
                 break;
             child  = parent;

         }
     }
   
}
int main(){
    int arr[] = {1, 4, 6, 10, 3, 21, 7};
    //build heap out of array
    //insert and delete function
    vector<int> heap;
    heap = insert(arr);
}