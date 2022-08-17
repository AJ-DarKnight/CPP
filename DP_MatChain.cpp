#include <iostream>
#include<climits>
using namespace std;

int matrixChainMultiplication(int* arr, int n)
{
    n++;
    
    int a[n][n];
    
    int i,j,k,c,t;
    
    for(i=1;i<n;i++)
        a[i][i]=0;
    
    for(i=2;i<n;i++)
    {
        for(j=1;j<n-i+1;j++)
        {
            c=i+j-1;
            
            a[j][c]=INT_MAX;
            
            for(k=j;k<=c-1;k++)
            {
                t=a[j][k]+a[k+1][c]+arr[j-1]*arr[k]*arr[c];
                
                if(t<a[j][c])
                    a[j][c]=t;
            }
        }
    }
    
    return a[1][n-1];
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
