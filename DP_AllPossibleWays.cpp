#include <iostream>
using namespace std;

int power(int a, int b)
{
	if(b == 0)
	return 1;
	
	if(b == 1)
	return a;
	
	int ans = power(a, b/2);
	
	return ans*ans*power(a, b%2);
}

int getHelp(int a, int b, int curNum, int curSum)
{
	int res = 0;
	int p = power(curNum, b);
	
	while(p + curSum < a)
	{
		res += getHelp(a, b, curNum+1, p+curSum);
		curNum++;
		p = power(curNum, b);
	}
	
	if(p + curSum == a)
	res++;
	
	return res;
}

int getAllWays(int a, int b)
{
	return getHelp(a, b, 1, 0);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}
