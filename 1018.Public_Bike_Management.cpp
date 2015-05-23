#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<vector<int> > roads;
vector<int> path;
vector<int> bikes;
vector<int> ret;
vector<bool> visited;
int nStation, maxBike, endStation, nRoad, halfBike;
int minTime, minSent, minBack;
void dfs(int start, vector<int> &onePath, int tmpTime, int tmpSent, int tmpBack)
{
	if (start == endStation)
	{
		if (tmpTime < minTime || (tmpTime == minTime && (tmpSent < minSent || (
			tmpSent == minSent && tmpBack < minBack))))
		{
			path = onePath;
			minTime = tmpTime;
			minSent = tmpSent;
			minBack = tmpBack;
		}
		return ;
	}
	for (int i = 1; i <= nStation; i++)
	{
		if (roads[start][i] >= 0 && !visited[i])
		{
			visited[i] = 1;
			onePath.push_back(i);
			int sentCopy = tmpSent, backCopy = tmpBack;
			// more than half bikes
			if (bikes[i] >= halfBike)
			{
				backCopy += bikes[i] - halfBike;
			}else
			{
				// collecting from pre-station can fix this station
				if (backCopy >= halfBike - bikes[i])
				{
					backCopy -= halfBike - bikes[i];
				}else
				{
					sentCopy += (halfBike - bikes[i] - tmpBack);
					backCopy = 0;
				}
			}
			dfs(i, onePath, tmpTime + roads[start][i], sentCopy, backCopy);
			// backtracing
			visited[i] = 0;
			onePath.pop_back();
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>maxBike>>nStation>>endStation>>nRoad;
	halfBike = maxBike / 2;
	bikes.resize(nStation + 1);
	roads.resize(nStation + 1, vector<int>(nStation + 1, -1));
	visited.resize(nStation + 1, 0);
	for (int i = 0; i < nStation; ++i)
	{
		cin>>bikes[i + 1];
	}
	int a, b, c;
	for (int i = 0; i < nRoad; ++i)
	{
		cin>>a>>b>>c;
		roads[a][b] = c;
		roads[b][a] = c;
	}
	visited[0] = 1;
	minTime = minSent = minBack = 0x7FFFFFFF;
	vector<int> onePath;
	onePath.push_back(0);
	dfs(0, onePath, 0, 0, 0);
	cout<<minSent<<' ';
	for (int i = 0; i < path.size(); ++i)
	{
		if (i != 0)
			cout<<"->";
		cout<<path[i];
	}
	cout<<" "<<minBack;
	return 0;
}