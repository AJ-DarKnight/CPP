#include <iostream>
#include<cmath>
using namespace std;

int balancedBTs(int n)
{
    
    if(n<=1)
        return 1;
    
    int p=(int)(pow(10,9)+7);
    
    long *dp= new long[n+1];
    
    dp[0]=dp[1]=1;
    
    for (int i=2;i<=n;i++)
    {
        long a = (dp[i-1]*dp[i-1]) % p;
        long b = (2*dp[i-1]*dp[i-2]) % p;
        
        dp[i] = (a + b) % p;
    }

    int ans=(int)dp[n];
    
    delete [] dp;
    
    return ans;
    /*if(n<=1)
        return 1;
    
    long dp[n+1];
    int p=(int)(pow(10,9)+7);
    
    int a1=balancedBTs(n-1);
    int a2=balancedBTs(n-2);
    
    int a=(a1*a1)%p;
    int b=(a1*a2)%p;
    
    return (a + (2*b)%p)%p;*/
    
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
