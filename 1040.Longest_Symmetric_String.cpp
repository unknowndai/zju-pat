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
	string str;
	getline(cin, str);
	int strLen = str.length();
	int maxLen = 0, tmpLen = 0;
	for (int i = 0; i < strLen; ++i)
	{
		int left = i, right = i + 1;
		tmpLen = 0;       // aa
		while(left >= 0 && right < strLen && str[left--] == str[right++])
			tmpLen += 2;
		maxLen = tmpLen > maxLen ? tmpLen : maxLen;
		left = i - 1; right = i + 1;    // aba
		tmpLen = 1;
		while(left >= 0 && right < strLen && str[left--] == str[right++])
			tmpLen += 2;
		maxLen = tmpLen > maxLen ? tmpLen : maxLen;
	}
	cout<<maxLen;
	return 0;
}