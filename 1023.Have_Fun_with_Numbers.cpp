#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str;
	cin>>str;
	int overFlow = 0;
	string doubleStr;
	// double it
	for (int i = str.length() - 1 ; i >= 0; --i)
	{
		int tmp = (str[i] - '0') * 2 + overFlow;
		doubleStr.insert(0, 1, tmp % 10 + '0');
		overFlow = tmp / 10;
	}
	// different length
	if (overFlow)
	{
		cout<<"No"<<endl;
		doubleStr.insert(0, 1, overFlow + '0');
		cout<<doubleStr;
		return 0;
	}
	int cnt[10] = {0};         // the digit count
	for (int i = 0; i < str.length(); ++i)
	{
		cnt[str[i] - '0']++;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (cnt[doubleStr[i] - '0'] == 0)
		{
			cout<<"No"<<endl;
			cout<<doubleStr;
			return 0;
		}else
			cnt[doubleStr[i] - '0']--;
	}
	cout<<"Yes"<<endl;
	cout<<doubleStr;
	return 0;
}