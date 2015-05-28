#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define MAX_INT 0x7FFFFFFF
int nCity, nRoad, starting, destination;
vector<vector<int> > dist;
vector<vector<int> > cost;
vector<int> minDist;
vector<int> minCost;
vector<int> preCity;      // store pre-city in the path;
void dijkstra(int s)
{
	vector<bool> visited(nCity, 0);
	visited[s] = 1;
	minDist[s] = 0;
	minCost[s] = 0;
	while(s != destination)
	{
		// update the distance and cost
		for (int i = 0; i < nCity; ++i)
		{
			if (!visited[i] && dist[s][i] > 0)
			{
				if (dist[s][i] + minDist[s] < minDist[i])
				{
					minDist[i] = dist[s][i] + minDist[s];
					minCost[i] = minCost[s] + cost[s][i];
					preCity[i] = s;
				}else if (dist[s][i] + minDist[s] == minDist[i] && minCost[s] + cost[s][i] < minCost[i])
				{// same distance but lower cost
					minCost[i] = minCost[s] + cost[s][i];
					preCity[i] = s;
				}
			}
		}
		// choose one city
		int index = 0, min = MAX_INT;
		for (int i = 0; i < nCity; ++i)
		{
			if (!visited[i] && minDist[i] < min)
			{
				min = minDist[i];
				index = i;
			}
		}
		s = index;
		visited[s] = 1;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>nCity>>nRoad>>starting>>destination;
	dist.resize(nCity, vector<int>(nCity, 0));
	cost.resize(nCity, vector<int>(nCity, 0));
	minDist.resize(nCity, MAX_INT);
	minCost.resize(nCity, MAX_INT);
	preCity.resize(nCity, 0);
	int s, t, d, c;
	for (int i = 0; i < nRoad; ++i)
	{
		cin>>s>>t>>d>>c;
		dist[s][t] = d;
		dist[t][s] = d;
		cost[t][s] = c;
		cost[s][t] = c;
	}
	dijkstra(starting);
	// get the path
	vector<int> path;
	int last = destination;
	while(last != starting)
	{
		path.push_back(last);
		last = preCity[last];
	}
	path.push_back(starting);
	for (int i = path.size() - 1; i >= 0; --i)
	{
		cout<<path[i]<<" ";
	}
	cout<<minDist[destination]<<" "<<minCost[destination];
	return 0;
}