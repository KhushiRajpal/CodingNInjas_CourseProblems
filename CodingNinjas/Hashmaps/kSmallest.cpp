#include <iostream>
#include <queue>

using namespace std;
int main()
{
priority_queue<int> pq;
int  k = 4;
int min = A[0];
for(int i = 0 ; i < k ; i++)
{
   pq.push(A[i]);
   if(A[i] < min)
       min = A{i};
}

//what is maximum out of all that 
//also maintain a minimum

for(int i = k; i < size; i++)
{
    if(A[i] >=  pq.top())
        continue;

    pq.pop();
    pq.push(A[i]);

}

for(int i = 0; i < k ; i++)
{
    cout << "The min array is : " << endl;
}
}

