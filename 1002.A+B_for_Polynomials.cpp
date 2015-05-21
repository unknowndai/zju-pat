#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
float a[1001], b[1001];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	memset(a, 0, 1001 * sizeof(float));
	memset(b, 0, 1001 * sizeof(float));
	int k, tmp;
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		cin>>tmp;
		cin>>a[tmp];
	}
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		cin>>tmp;
		cin>>b[tmp];
	}
	int cnt = 0;
	for (int i = 0; i < 1001; ++i)
	{
		a[i] += b[i];
		if (a[i] != 0)
		{
			cnt++;
		}
	}
	cout<<cnt;
	for (int i = 1001; i >= 0; --i)
	{
		if (a[i] != 0)
			printf(" %d %.1f", i, a[i]);
	}
	return 0;
}