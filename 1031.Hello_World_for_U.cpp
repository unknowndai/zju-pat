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
	cin>>str;
	int len = str.length();
	// calculate the n1, n2, n3
	int n1 = (len + 2) / 3, n2 = n1, n3 = len + 2 - 2 * n2;
	for (int i = 0; i < n1 - 1; ++i)
	{
		cout<<str[i];
		for (int j = 0; j < n3 - 2; ++j)
			cout<<" ";
		cout<<str[len - i - 1]<<endl;
	}
	// the last row
	cout<<str.substr(n1 - 1, n3);
	return 0;
}