#include <iostream>
using namespace std;


int dp(int **input, int **output, int m , int n )
{
	//base case 
	// m - 1 n m - 1 n - 1 m - 1 end y all are 1
	output[m - 1][n - 1] = input[n-1][m -1];

	for(int i = m - 2; i >=0 ; i--)
	{
		output[i][n - 1] = output[i + 1][m - 1] + input[i][n - 1];
	}

	for(int j = n - 2; j >= 0; j--)
	{
		output[m -1][j] = output[m - 1][j + 1] + input[m - 1][j];
	}

	for(int i = m - 2; i >= 0; i--)
	{
		for(int j = n - 2; j >= 0 ; j --)
		{
			output[i][j] = min(output[i+1][j], min(output[i][j + 1], output[i + 1][j + 1])) + input[i][j];
		}
	}

	return output[0][0];


	
}
  
int memoiz(int m, int n, int **mini,int i, int j, int **output)
{
	if((i == m - 1) && (j == n - 1))
	    return mini[i][j];

	if((i >= m) || (j >= n))
	    return INT_MAX;

	if(output[i][j] != 0)
	    return output[i][j];

	int p1 = memoiz(m, n, mini, i + 1, j, output ) ;
	int p2 = memoiz(m, n, mini, i, j + 1, output) ;
	int p3 =  memoiz(m, n, mini, i + 1, j + 1, output) ;
	//cout << " p1 : " << p1 << " p2 : " << p2 << " p3 : "  << p3 << endl;
    int a = min(p1, min(p2, p3)) + mini[i][j];
	
	output[i][j]  = a;
	return a ;
}


int count(int m, int n, int **mini,int i, int j)
{
	if((i == m - 1) && (j == n - 1))
	    return mini[i][j];


	if((i >= m) || (j >= n))
	    return INT_MAX;

	int p1 = count(m, n, mini, i + 1, j ) ;
	int p3 = count(m, n, mini, i + 1, j + 1) ;
	int p2 = count(m, n, mini, i, j + 1) ;
	
	int ans =  min(p1, min(p2, p3))  + mini[i][j];
	return ans;
}

int main(){
	int n , m;
	cin >> m;
	cin >> n;
	int **array = new int*[m];
	for(int i = 0; i < m; i++)
	{
		array[i] = new int[n];
		for(int j = 0; j < n ; j++)
		{
			int x; 
			cin >> x;
			array[i][j] = x;
		}
	}

	int **output = new int*[m];
	for(int i = 0; i < m; i++)
	{
		output[i] = new int[n];
		for(int j = 0; j < n ; j++)
		{
		    output[i][j] = 0;
			
		}
	}

	cout << count(m, n , array, 0 , 0) << endl;
	cout << memoiz(m, n , array, 0 , 0, output) << endl;
	cout << dp(array, output, m , n) ;
	
	// each index position has a weight

}