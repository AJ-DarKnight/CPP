#include <iostream>
#include<cmath>
using namespace std;

int balancedBTs(int n)
{
    long dp[n+1];
    
    int p=(int)(pow(10,9)+7);
    
    dp[0]=dp[1]=1;
    
    for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1])*((2*dp[i-2])%p + dp[i-1]%p) %p;
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
