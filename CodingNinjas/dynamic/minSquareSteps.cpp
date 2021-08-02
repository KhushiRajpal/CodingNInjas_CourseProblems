#include <iostream>
#include <math.h>
using namespace std;
 

int getMinSquares(unsigned int n)
{
 
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;
 
    int res = n;
 
    for (int x = 1; x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
            res = min(res, 1 + getMinSquares
                                  (n - temp));
    }
    return res;
}
 
// Driver code
int main()
{
    //cout << getMinSquares(6);
    int n = 65;
    int res = 65;
    int arr[n];
    for(int i  = 0; i <= n; i++)
    {
        if(i <=3)
           arr[i] = i;
        else
        arr[i] = -1;
    }
    if(sqrt(n) == floor(sqrt(n)))
    {
        int x = sqrt(n);
        arr[x] = 1;
    }

    for(int i = 4; i <= n; i++)
    {
        if(sqrt(i) == floor(sqrt(i)))
        {
            arr[i] = 1;
            continue;
        }

        int curr_sqrt = floor(sqrt(i));
        int sum = pow(curr_sqrt ,2);
        int count = 1;
        while(sum != i)
        {
            if(sum + pow(curr_sqrt, 2) <= i)
            {
                 sum += pow(curr_sqrt , 2);
                 count = count + arr[curr_sqrt];
            }
               
            else
                curr_sqrt--;
        }

        arr[i] = min(res, count);
        
        // find the min steps

    

    }
    cout<< arr[n];

    


    return 0;
}