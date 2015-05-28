#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int numNode;
// case 3 will exceed the time limit if using Adjacency Matrix
//vector<vector<bool> > graph;
vector<vector<int> > graph;
bool visited[10001];
int bfs(int s)
{
	queue<int> que;
	que.push(s);
	visited[s] = 1;
	int nLevel = 0;
	while(!que.empty())
	{
		nLevel++;
		int sz = que.size();
		while(sz--)
		{
			int tmp = que.front();
			que.pop();
			for (int i = 0; i < graph[tmp].size(); ++i)
			{
				if (!visited[graph[tmp][i]])
				{
					visited[graph[tmp][i]] = 1;
					que.push(graph[tmp][i]);
				}
			}		
		}
	}
	return nLevel;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>numNode;
	//graph.resize(numNode + 1, vector<bool>(numNode + 1, 0));
	graph.resize(numNode + 1, vector<int>());
	int a, b;
	for (int i = 0; i < numNode - 1; ++i)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	memset(visited, 0, numNode + 1);
	int nParts = 0;
	for (int i = 1; i <= numNode; ++i)
	{
		if (!visited[i])
		{
			bfs(i);
			nParts++;
		}
	}
	if (nParts > 1)
	{
		cout<<"Error: "<<nParts<<" components";
		return 0;
	}
	vector<int> ret;
	int maxHeight = 0, tmpHeight;
	for (int i = 1; i <= numNode; ++i)
	{
		memset(visited, 0, numNode + 1);
		tmpHeight = bfs(i);
		if (tmpHeight > maxHeight)
		{
			ret.clear();
			ret.push_back(i);
			maxHeight = tmpHeight;
		}else if (tmpHeight == maxHeight)
		{
			ret.push_back(i);
		}
	}
	for (int i = 0; i < ret.size(); ++i)
	{
		cout<<ret[i]<<endl;
	}
	return 0;
}