#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str1, str2, str3;
	getline(cin, str1);
	getline(cin, str2);
	bool isExist[256] = {0};
	for (int i = 0; i < str2.length(); ++i)
	{
		isExist[str2[i]] = 1;
	}
	for (int i = str1.length() - 1; i >= 0; --i)
	{
		if (!isExist[str1[i]])
		{
			str3.insert(0, 1, str1[i]);
		}
	}
	cout<<str3;
	return 0;
}