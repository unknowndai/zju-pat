#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
// bfs
void printLeavesCnt(vector<vector<int> > & nodes, int n)
{
	queue<int> que;
	que.push(1);
	bool isFirst = true;
	while(!que.empty())
	{
		int sz = que.size();
		int cnt = 0;
		while(sz--)
		{
			int node = que.front();
			que.pop();
			if (nodes[node].empty())
			{
				cnt++;
				continue;
			}
			for (int i = 0; i < nodes[node].size(); ++i)
			{
				que.push(nodes[node][i]);
			}
		}
		if (isFirst)
		{
			isFirst = false;
			printf("%d", cnt);
		}else
			printf(" %d", cnt);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int n, m;
	cin>>n>>m;
	vector<vector<int> > nodes(n + 1, vector<int>());
	for (int i = 0; i < m; ++i)
	{
		int parent, k, tmp;
		cin>>parent>>k;
		for (int j = 0; j < k; j++)
		{
			cin>>tmp;
			nodes[parent].push_back(tmp);
		}
	}
	printLeavesCnt(nodes, n);
	return 0;
}