#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define MAXNUM 10001
int cnt[MAXNUM];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	memset(cnt, 0, MAXNUM * sizeof(int));
	int num;
	cin>>num;
	vector<int> data(num, 0);
	for (int i = 0; i < num; ++i)
	{
		cin>>data[i];
		cnt[data[i]]++;
	}
	for (int i = 0; i < num; ++i)
	{
		if (cnt[data[i]] == 1)
		{
			cout<<data[i];
			return 0;
		}
	}
	cout<<"None";
	return 0;
}