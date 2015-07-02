#include<iostream>     // the sample is wrong, 3.2 instead of 3.3
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
using namespace std;
#define M 1020
#define MAXDIST 0x7fffffff
int nstation, nhouse, serveDist;
int graph[M][M];
int dist[M];
void dijkstra(int start)
{
	// init
	int npoints = nstation + nhouse;
	for (int i = 1; i <= npoints; ++i)
	{
		if (graph[start][i])
		{
			dist[i] = graph[start][i];
		}else
			dist[i] = MAXDIST;
	}
	bool visited[M];
	memset(visited, 0, M);
	visited[start] = 1;
	for (int i = 0; i < npoints - 1; ++i)
	{
		// choose
		int mindist = MAXDIST, index = 1;
		for (int j = 1; j <= npoints; j++)
		{
			if (!visited[j] && dist[j] < mindist)
			{
				mindist = dist[j];
				index = j;
			}
		}
		visited[index] = 1;
		// update the dist
		for (int j = 1; j <= npoints; j++)
		{
			if (graph[index][j] != 0 && dist[index] + graph[index][j] <  dist[j])
			{
				dist[j] = dist[index] + graph[index][j];
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nroad;
	cin>>nhouse>>nstation>>nroad>>serveDist;
	memset(graph, 0, M * M * sizeof(int));
	string str;
	int a, b, c;
	for (int i = 0; i < nroad; ++i)             // build the graph
	{
		cin>>str;
		if (str[0] == 'G')                      // gas station index behind the houses
		{
			sscanf(&str[1], "%d", &a);
			a += nhouse;
		}else
			sscanf(&str[0], "%d", &a);
		cin>>str;
		if (str[0] == 'G')
		{
			sscanf(&str[1], "%d", &b);
			b += nhouse;
		}else
			sscanf(&str[0], "%d", &b);
		cin>>c;
		graph[a][b] = graph[b][a] = c;
	}
	int minstation = 0, tolDist = MAXDIST, choice = 0;
	for (int i = 1; i <= nstation; ++i)
	{
		dijkstra(nhouse + i);
		int mintmp = MAXDIST, toltmp = 0;
		bool canServe = true;
		for (int j = 1; j <= nhouse; ++j)
		{
			if (dist[j] > serveDist)         // is not in service range
			{
				canServe = false;
				break;
			}
			mintmp = dist[j] < mintmp ? dist[j] : mintmp;    // the minmum distance to house
			toltmp += dist[j];                               // total distance
		}
		if (!canServe)
		{
			continue;
		}
		// this station is better
		if (mintmp > minstation || (mintmp == minstation && toltmp < tolDist))
		{
			choice = i;
			minstation = mintmp;
			tolDist = toltmp;
		}
	}
	if (choice == 0)
	{
		cout<<"No Solution";
	}else
	{
		cout<<'G'<<choice<<endl;
		printf("%.1f %.1f", minstation * 1.0, (float)tolDist / nhouse);
	}
	return 0;
}