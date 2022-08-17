#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    int i,j;
    
    for(j=1;j<n;j++)
        input[0][j]=input[0][j]+input[0][j-1];
    
    for(i=1;i<m;i++)
        input[i][0]=input[i][0]+input[i-1][0];
    
    for(i=1;i<m;i++)
        for(j=1;j<n;j++)
            input[i][j]=input[i][j]+min(min(input[i-1][j],input[i][j-1]),input[i-1][j-1]);
    
    return input[m-1][n-1];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
