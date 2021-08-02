#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int A[] = { 10 , 12, 6, 7 ,9};
    int k = 3;
    priority_queue<int> pq;
    // if i have a k sorted
    // consider a temp with b elements of array
    
    for(int i = 0 ; i < k ; i++)
    {
        pq.push(A[i]);
    }
    int size = sizeof(A)/ sizeof(A[0]);
   
    for(int i = 0 ; i < size; i++)
    {
        A[i] = pq.top();
        pq.pop();
        if(k+i < size)
            pq.push(A[k+i]);
    }

    for(int i = 0 ; i < 5 ; i++)
    {
        cout << A[i];
    }

}