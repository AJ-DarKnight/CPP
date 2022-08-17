#include <iostream>
#include <string>
using namespace std;

int solve(string s, string v)
{
    int n = s.size(), m = v.size();
    
    int dp[n+1][m+1], next[n+1][m+1];
    
    int i,j,prev;
    
    for(i = 0; i < n; i++)
    {
        prev = -1;
        for(j = 0;j < m; j++)
        { 
            if(s[i] == v[j]) 
                prev = j;
            next[i+1][j+1] = prev;
        }
    }
    
    for(i = 1; i <= n; i++)
        dp[i][0] = 1;
    
    for(i = 0; i <= m; i++)
        dp[0][i] = 1e9;
    
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(next[i][j] == -1)
                dp[i][j] = 1;
            else 
                dp[i][j] = min(dp[i-1][j],1 + dp[i-1][next[i][j]]); 
        }
    }
    
    return dp[n][m];
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
