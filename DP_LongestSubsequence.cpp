#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int* arr, int n)
{
    int *dp=new int[n];
    
    dp[0]=1;
    int a=1;
     
    for(int i=1;i<n;i++)
    {
        int max=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i])
            {
                int op=dp[j]+1;
                if(op>max)
                    max=op;
            }
        }
        
        dp[i]=max;
        
        if(max>a)
            a=max;
    }
    
    return a;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
	{
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
