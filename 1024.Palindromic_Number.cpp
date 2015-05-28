#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindromic(string str)
{
	int sz = str.length();
	for (int i = 0, j = sz - 1; i < sz / 2; ++i, --j)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}
string addStr(string a, string b)
{
	// a and b have same length
	int overFlow = 0;
	string ret;
	for (int i = a.length() - 1; i >= 0; --i)
	{
		int tmp = a[i] - '0' + b[i] - '0' + overFlow;
		ret.insert(0, 1, tmp % 10 + '0');
		overFlow =  tmp / 10;
	}
	if (overFlow)
	{
		ret.insert(0, 1, overFlow + '0');
	}
	return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str, rstr;
	int k;
	cin>>str>>k;
	int i = 0;
	while(i < k)
	{
		if (isPalindromic(str))
		{
			break;
		}
		rstr.assign(str.rbegin(), str.rend());
		str = addStr(str, rstr);
		i++;
	}
	cout<<str<<endl<<i;
	return 0;
}