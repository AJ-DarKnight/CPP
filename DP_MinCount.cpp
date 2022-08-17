#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    if(n<=3)
        return n;
    
    int dp[n+1];
    
    for(int i=0;i<=3;i++)
        dp[i]=i;
    
    for(int i=4;i<=n;i++)
    {
        int a=i;
        
        for(int j=1;j<=i/2;j++)
        {
            int k=i-(j*j);
            
            if(k>=0)
                a=min(a,dp[k]+1);
        }
        dp[i]=a;
    }
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
