#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<pair<int, float> > a, b;
float ret[2001];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	memset(ret, 0, 2001 * sizeof(float));
	int aSize, bSize;
	cin>>aSize;
	int exponent;
	float coefficient;
	for (int i = 0; i < aSize; ++i)
	{
		cin>>exponent>>coefficient;
		a.push_back(pair<int, float>(exponent, coefficient));
	}
	cin>>bSize;
	for (int i = 0; i < bSize; ++i)
	{
		cin>>exponent>>coefficient;
		b.push_back(pair<int, float>(exponent, coefficient));
	}
	int cnt = 0;
	for (int i = 0; i < aSize; ++i)
		for (int j = 0; j < bSize; ++j)
		{
			if (ret[a[i].first + b[j].first] == 0)
			{
				cnt++;
			}
			ret[a[i].first + b[j].first] += a[i].second * b[j].second;
			if (ret[a[i].first + b[j].first] == 0)
			{
				cnt--;
			}
		}
	cout<<cnt;
	for (int i = 2000; i >= 0; --i)
	{
		if (ret[i] != 0)
		{
			printf(" %d %.1f", i, ret[i]);
		}
	}
	return 0;
}