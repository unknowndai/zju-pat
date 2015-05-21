#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
long long convertDecimal(string &str1, long long radix)
{
	long long ret = 0;
	long long factor = 1;
	for (int i = str1.length() -  1; i >= 0 ; --i)
	{
		if (str1[i] >= '0' && str1[i] <= '9')
		{
			ret += factor * (str1[i] - '0');
		}else
			ret += factor * (str1[i] - 'a' + 10);
		factor *= radix;
		if (ret > 0xFFFFFFFF)    // avoid overflow
		{
			return 0xFFFFFFFF;
		}
	}
	return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str1, str2;
	int tag, radix;
	cin>>str1>>str2>>tag>>radix;
	if (tag == 2)
	{
		string tmp= str1;
		str1 = str2;
		str2 = tmp;
	}
	long long num1 = convertDecimal(str1, radix);
	// find minimum radix
	int minRadix = 1;
	for (int i = 0; i < str2.length(); ++i)
	{
		if (str2[i] >= '0' && str2[i] <= '9')
		{
			if (str2[i] - '0' >= minRadix)
				minRadix = str2[i] - '0' + 1;
		}else
			if (str2[i] - 'a' + 10 >= minRadix)
			{
				minRadix = str2[i] - 'a' + 11;
			}
	}
	// case 10 : output the given radix when same input
	// If the solution is not unique, output the smallest possible radix.
	// I think this case is so suck!!!
	if (str1 == str2)
	{
		cout<<radix;
		return 0;
	}
	if (num1 == convertDecimal(str2, minRadix))
	{
		cout<<minRadix;
		return 0;
	}
	// case 7 : Time Limit Exceeded
	long long maxRadix = 0xFFFFFFFF, mid, midVal;
	while(minRadix <= maxRadix)
	{
		mid = minRadix + (maxRadix - minRadix)/2;
		midVal = convertDecimal(str2, mid);
		if (midVal == num1)
		{
			cout<<mid;
			return 0;
		}
		if (midVal < num1)
		{
			minRadix = mid + 1;
		}else
			maxRadix = mid - 1;
	}
	cout<<"Impossible";
	return 0;
}