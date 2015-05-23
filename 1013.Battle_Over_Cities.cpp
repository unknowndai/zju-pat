#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<vector<bool> > roads;
int numCity, city;
vector<bool> visited;
void dfs(int start)
{
	visited[start] = 1;
	for (int i = 1; i <= numCity; ++i)
	{
		if (roads[start][i] && !visited[i] && i != city)
		{
			dfs(i);
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nRoad, nQuery;
	cin>>numCity>>nRoad>>nQuery;
	roads.resize(numCity + 1, vector<bool>(numCity + 1, 0));
	int a, b;
	for (int i = 0; i < nRoad; ++i)
	{
		cin>>a>>b;
		roads[a][b] = 1;
		roads[b][a] = 1;
	}
	for (int i = 0; i < nQuery; ++i)
	{
		cin>>city;
		int part = 0;
		visited.clear();
		visited.resize(numCity + 1, 0);
		for (int j = 1; j <= numCity ; ++j)
		{
			if (!visited[j] && j != city)    // ignore it when visiting the lost city
			{
				dfs(j);
				part++;
			}
		}
		cout<<part - 1<<endl;
	}
	return 0;
}