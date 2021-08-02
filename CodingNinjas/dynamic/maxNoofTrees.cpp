#include <iostream>
#include <cmath>
using namespace std;
	
		
	int height(int h, int mod, int (&arr)[h])
	{
		if(h == 0 || h == 1)
			return h;
		if(arr[h] != 0)
			return arr[h];
	
		int h1 = height(h - 1, mod, arr);
		int h2 = height(h -2, mod , arr);
		int h11 = int(long(h1)*h2*2);
		int h22 = int((long)h1*h1);
		int ans = h11 + h22;
		arr[h] = ans;


		return  ans;
	}

      int main()
    {
		int h = 5;
		int arr[h];
		for(int i  = 0; i < h; i++)
			arr[i] = -1;
	
		int mod = 1000000000 % 7;
		
		int c = height(5, mod, arr);
		cout << c;
	}