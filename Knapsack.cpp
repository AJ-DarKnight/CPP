#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int knapsack(int* weight, int* value, int n, int maxWeight)
{
    int dp[2][maxWeight+1];

    memset(dp, 0, sizeof(dp)); 
    //Sets the first num bytes of the block of memory pointed by ptr to the specified value 
    
    int i = 0;
    
    while (i < n)
    {
        int j=0;
        
        if (i%2!=0)
        {
            while (++j<=maxWeight)    
            { 
                if (weight[i] <= j) 
                    dp[1][j] = max(value[i] + dp[0][j-weight[i]], dp[0][j] ); 
                else 
                    dp[1][j] = dp[0][j]; 
            }
        }
       
        else
        {
            while(++j <= maxWeight)
            {
                if (weight[i] <= j) 
                    dp[0][j] = max(value[i] + dp[1][j-weight[i]], dp[1][j]); 
                else 
                    dp[0][j] = dp[1][j]; 
            }
        }
        i++;
    } 
    
    return (n%2 != 0)? dp[0][maxWeight] : dp[1][maxWeight];
}

int main()
{
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++)
	{
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) 
    
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
