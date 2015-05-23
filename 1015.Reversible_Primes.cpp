#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int reverseNum(int num, int radix)
{
	stack<int> sta;
	while (num)
	{
		sta.push(num % radix);
		num /= radix;
	}
	int factor = 1, ret = 0;
	while(!sta.empty())
	{
		ret += sta.top() * factor;
		factor *= radix;
		sta.pop();
	}
	return ret;
	return ret;
}
bool isPrime(int num)
{
	if (num == 0 || num == 1)
	{
		return false;
	}
	int stop = (int)sqrt(num * 1.0);
	for (int i = 2; i <= stop; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num, radix;
	while(cin>>num && num >= 0)
	{
		cin>>radix;
		if (isPrime(num) && isPrime(reverseNum(num, radix)))
		{
			puts("Yes");
		}else
			puts("No");
	}
	return 0;
}