#include <iostream>
using namespace std;

      int main()
    {
        
       int n = 11;
       int* arr = new int[n+1];
      
       arr[0] = 0;
       arr[1] = 0;
       for(int i = 2; i <= n; i++)
       {
           int a = -1, b = -1;
           if(i % 2 == 0)
                a = arr[i/2];
            if(i % 3 == 0)
               b = arr[i/3];
            int c  = arr[i - 1];
            
            if(a != -1 && b == -1)
                arr[i] = min(a,c) + 1;
                
            else if(b != -1 && a == -1)
                arr[i] = min(b,c) + 1;
                
            else if(a == -1 && b == -1)
                arr[i] = c + 1;
                
            else 
            arr[i] = min(a , min(b,c));
            
            
            
            
           
       }

       cout << arr[n];
    }