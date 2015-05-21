#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define CITY 500
#define MAX 0x7FFFFFFF
int roads[CITY][CITY];
int dist[CITY];
int npath[CITY];
bool visited[CITY];
int teams[CITY];
int maxTeam[CITY];
int ncity, nroad, startCity, endCity;
void dijkstra()
{
	memset(visited, 0, CITY);
	// init
	for (int i = 0; i < ncity; ++i)
	{
		if (roads[startCity][i])
		{
			dist[i] = roads[startCity][i];
			maxTeam[i] = teams[startCity] + teams[i];
			npath[i] = 1;
		}else
		{
			dist[i] = MAX;
			maxTeam[i] = 0;
			npath[i] = 0;
		}
	}
	// case 1 : startCity == endCity
	dist[startCity] = 0;
	npath[startCity] = 1;
	maxTeam[startCity] = teams[startCity];
	visited[startCity] = 1;
	for (int i = 0; i < ncity - 1; ++i)
	{
		// choose the shortest road
		int index = 0, minRoad = MAX;
		for (int j = 0; j < ncity; ++j)
		{
			if (!visited[j] && dist[j] < minRoad)
			{
				minRoad = dist[j];
				index = j;
			}
		}
		visited[index] = 1;
		if (index == endCity)
		{
			return ;
		}
		// update the distance and maxTeam
		int tmp;
		for (int j = 0; j < ncity; ++j)
		{
			if (roads[index][j] != 0 && !visited[j])
			{
				tmp = dist[index] + roads[index][j];
				if (tmp < dist[j])
				{
					dist[j] = tmp;
					npath[j] = npath[index];
					maxTeam[j] = maxTeam[index] + teams[j];
				}else if (tmp == dist[j])
				{
					npath[j] += npath[index];
					maxTeam[j] = max(maxTeam[index] + teams[j], maxTeam[j]);
				}
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>ncity>>nroad>>startCity>>endCity;
	for (int i = 0; i < ncity; ++i)
	{
		cin>>teams[i];
	}
	int s, t, l;
	memset(roads, 0, CITY * CITY * sizeof(int));
	for (int i = 0; i < nroad; ++i)
	{
		cin>>s>>t>>l;
		roads[s][t] = l;
		roads[t][s] = l;
	}
	dijkstra();
	cout<<npath[endCity]<<" "<<maxTeam[endCity];
	return 0;
}