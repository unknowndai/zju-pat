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
	int nExits, d;
	cin>>nExits;
	vector<int> dist(1, 0);   // using first exit as starting point
	for (int i = 0; i < nExits; ++i)
	{
		cin>>d;
		dist.push_back(dist.back() + d);
	}
	int nQuery, s, e;
	cin>>nQuery;
	for (int i = 0; i < nQuery; ++i)
	{
		cin>>s>>e;
		int tmp = dist[s - 1] - dist[e - 1];
		tmp = tmp < 0 ? -tmp : tmp;         // reverse order
		cout<<(tmp > dist[nExits] - tmp ? dist[nExits] - tmp : tmp)<<endl;;
	}
	return 0;
}