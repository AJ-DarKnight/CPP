#include <bits/stdc++.h>
#include<climits>
using namespace std;

int countStepsToOne(int n)
{
    int *dp=new int[n+1];
    
    dp[0]=0;
    dp[1]=0;
    
    int a1,a2,a3;
    
    for(int i=2;i<=n;i++)
    {
        a1=dp[i-1]+1;
        
        if(i%2==0)
            a2=dp[i/2]+1;
        else
            a2=INT_MAX;
        
        if(i%3==0)
            a3=dp[i/3]+1;
        else
            a3=INT_MAX;
        
        dp[i]=min(min(a1,a2),a3);
    }
    
    int a=dp[n];
    
    delete [] dp;
    
    return a;
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
