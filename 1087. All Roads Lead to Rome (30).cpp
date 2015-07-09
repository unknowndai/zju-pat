#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;
#define MAXCITY 200
#define MAX_INT 0x7fffffff
map<string, int> nameToIndex;       // city name and index
vector<string> cityName;            // city name
vector<int> happiness;              // happiness per city
int costs[MAXCITY][MAXCITY];        
int nCity, nRoute;                  // the number of cities and routes
vector<int> minCost;
vector<bool> visited;
vector<vector<int> > preCity;       // last city in least cost
int destination;                    // destination index
vector<vector<int> > routes;      // different routes with the least cost
void getRoutes(vector<int> ans, int dest)
{
	ans.push_back(dest);
	if (dest == 0)
	{
		routes.push_back(ans);
	}
	for (int i = 0; i < preCity[dest].size(); ++i)
	{
		getRoutes(ans, preCity[dest][i]);
	}
}
void dijkstra(int startCity)
{
	// init 
	minCost.resize(nCity, MAX_INT);
	minCost[startCity] = 0;
	visited.resize(nCity, 0);
	preCity.resize(nCity);
	for (int i = 0; i < nCity; i++)
	{
		// choose min cost
		int nextCity = 0, min = MAX_INT;
		for (int j = 0; j < nCity; j++)
			if (!visited[j] && minCost[j] < min)
			{
				min = minCost[j];
				nextCity = j;
			}
		visited[nextCity] = 1;
		if (nextCity == destination)   
			break;
		// add the nextCity and update the minCost and preCity
		for (int i = 0; i < nCity; ++i)
		{
			if (visited[i] || costs[nextCity][i] <= 0)
			{
				continue;
			}
			// better route with less cost
			if (costs[nextCity][i] + minCost[nextCity] < minCost[i])
			{
				minCost[i] = costs[nextCity][i] + minCost[nextCity];
				preCity[i].clear();
				preCity[i].push_back(nextCity);
			}else if (costs[nextCity][i] + minCost[nextCity] == minCost[i])
			{
				preCity[i].push_back(nextCity);
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>nCity>>nRoute;
	string name; 
	cin>>name;                           // starting city
	int cnt = 0;
	nameToIndex[name] = cnt++;
	cityName.push_back(name);
	happiness.push_back(0);
	int happy;
	for (int i = 1; i < nCity; ++i)
	{
		cin>>name>>happy;
		cityName.push_back(name);
		nameToIndex[name] = cnt++;
		happiness.push_back(happy);
		if (name == "ROM")               // get the destination index
		{
			destination = cnt - 1;
		}
	}
	string s, t;
	int c;
	// init the costs between pairs of cities
	memset(costs, 0, MAXCITY * MAXCITY * sizeof(int));
	// build the graph
	for (int i = 0; i < nRoute; ++i)
	{
		cin>>s>>t>>c;
		costs[nameToIndex[s]][nameToIndex[t]] = c;
		costs[nameToIndex[t]][nameToIndex[s]] = c;
	}
	dijkstra(0);         // get the least cost
	getRoutes(vector<int>(), destination);        // get all routes with least cost
	cout<<routes.size()<<" "<<minCost[destination];
	int maxHappy = 0, avgHappy = 0, bestChoice;   
	for (int i = 0; i < routes.size(); ++i)
	{
		int numCity = routes[i].size(), tmpMax = 0, tmpAvg;
		for (int j = 0; j < numCity; j++)
		{
			tmpMax += happiness[routes[i][j]];
		}
		if (tmpMax > maxHappy)         // more happiness
		{
			maxHappy = tmpMax;
			avgHappy = tmpMax / (numCity - 1);
			bestChoice = i;
		}else if (tmpMax == maxHappy)
		{
			tmpAvg = tmpMax / (numCity - 1);
			if (tmpAvg > avgHappy)       
			{
				avgHappy = tmpAvg;
				bestChoice = i;
			}
		}
	}
	cout<<" "<<maxHappy<<" "<<avgHappy<<endl;
	// print the route
	for (int i = routes[bestChoice].size() - 1; i >= 0; i--)
	{
		cout<<cityName[routes[bestChoice][i]];
		if (i)
		{
			cout<<"->";
		}
	}
	return 0;
}