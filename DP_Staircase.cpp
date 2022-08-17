#include <iostream>
using namespace std;

long staircase(int n)
{
    long dp[n+1];
    
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
