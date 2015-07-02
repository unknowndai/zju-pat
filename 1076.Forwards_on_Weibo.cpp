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
#define MAX_USERS 1000
vector<vector<int> > followers;
bool visited[MAX_USERS];
int nUsers, nLevels;
int bfs(int start)   
{
	visited[start] = 1;
	int count = 0, level = 0;
	queue<int> que;
	que.push(start);
	while(level < nLevels)
	{
		int st = que.size();
		while(st--)
		{
			int cur = que.front();
			que.pop();
			for (int i = 0; i < followers[cur].size(); ++i)
			{
				if (!visited[followers[cur][i]])
				{
					visited[followers[cur][i]] = 1;
					count++;
					que.push(followers[cur][i]);
				}
			}
		}
		level++;
	}
	return count;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>nUsers>>nLevels;
	followers.resize(nUsers);
	int cnt, tmp;
	for (int i = 0; i < nUsers; ++i)
	{
		cin>>cnt;
		for (int j = 0; j < cnt; j++)
		{
			cin>>tmp;
			followers[tmp - 1].push_back(i);     // build the relations
		}
	}
	int nQuerys;
	cin>>nQuerys;
	for (int i = 0; i < nQuerys; ++i)
	{
		cin>>tmp;
		memset(visited, 0, MAX_USERS);         // reset flags
		cout<<bfs(tmp - 1)<<endl;
	}
	return 0;
}