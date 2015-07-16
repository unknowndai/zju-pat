#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str;
	cin>>str;
	int len = str.length();
	long long *numP = new long long[len], *numT = new long long[len];
	// calculate the number P from front to back
	numP[0] = str[0] == 'P' ? 1 : 0;
	for (int i = 1; i < len; ++i)
		numP[i] = str[i] == 'P' ? numP[i - 1] + 1 : numP[i - 1];
	// calculate the number T from back to front
	numT[len - 1] = str[len - 1] == 'T' ? 1 : 0;
	for (int i = len - 2; i >= 0; --i)
		numT[i] = str[i] == 'T' ? numT[i + 1] + 1 : numT[i + 1];
	long long ret = 0;
	for (int i = 0; i < len; ++i)
		if (str[i] == 'A')
			ret += numP[i] * numT[i];
	cout<<ret % 1000000007;
	return 0;
}