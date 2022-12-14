#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    int **dp=new int*[n];
    
    int i,j;
    
    for(i=0;i<n;i++)
        dp[i]=new int[m];
    
    for(i=0;i<n;i++)
        dp[i][0]=arr[i][0]==1? 0 : 1;
    
    for(j=1;j<m;j++)
        dp[0][j]=arr[0][j]==1? 0 : 1;
    
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(arr[i][j]==0)
                dp[i][j]=1+min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            else
                dp[i][j]=0;
        }
    }
    
    int max=0;
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(dp[i][j]>max)
                max=dp[i][j];
    
    return max;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
