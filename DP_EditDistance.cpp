#include <iostream>
#include <cstring>
using namespace std;

int editDistance_mem(string s, string t, int **output)
{
	int m = s.size();
	int n = t.size();
	
	if(s.size() == 0 || t.size() == 0) 
		return max(s.size(), t.size());
    
	if(output[m][n] != -1)
		return output[m][n];

	int ans;
    
	if(s[0] == t[0])
		ans = editDistance_mem(s.substr(1), t.substr(1), output);

	else
    {
		
		int x = editDistance_mem(s.substr(1), t, output) + 1;
		
		int y = editDistance_mem(s, t.substr(1), output) + 1;
		
		int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

		ans =  min(x, min(y, z));
	}

	
	output[m][n] = ans;

	
	return ans;
}

int editDistance(string s1, string s2)
{
    int m = s1.size();
	int n = s2.size();
    
	int **ans = new int*[m+1];
    
	for(int i = 0; i <= m; i++)
    {
		ans[i] = new int[n+1];
        
		for(int j = 0; j <= n; j++)
        {
			ans[i][j] = -1;
		}
	}
	return editDistance_mem(s1, s2, ans);
    
    /*if(s1.length()==0)
        return s2.length();
    
    if(s2.length()==0)
        return s1.length();
    
    int l1=s1.length();
    int l2=s2.length();
    
    int **dp=new int*[l1];
    
    int i,j;
    
    for(i=0;i<l1;i++)
        dp[i]=new int[l2];
    
    bool f;
    
    for(j=0;f=false,j<l2;j++)
    {
        if(s1[l1-1]==s2[l2-1-j])
            f=true;
        
        dp[0][j]=f?j:j+1;
    }
    
    for(i=1;f=false,i<l1;i++)
    {
        if(s1[l1-1-i]==s2[l2-1])
            f=true;
        
        dp[i][0]=f?i:i+1;
    }
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            if(s1[l1-1-i]==s2[l2-1-j])
                dp[i][j]=dp[i-1][j-1];
            
            else
            {
                int a1=dp[i-1][j];
                int a2=dp[i][j-1];
                int a3=dp[i-1][j-1];
                
                dp[i][j]=min(min(a1,a2),a3);
            }
        }
    
    int a=dp[l1-1][l2-1];
    
    for(i=0;i<l1;i++)
        delete [] dp[i];
    
    delete [] dp;
    
    return a;*/
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}
