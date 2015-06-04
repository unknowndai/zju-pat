#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 2000     // <= 1000 calls, so the maximum people is 2000
int times[MAX];      // total time 
bool visited[MAX];
map<string, int> nameToIndex;
vector<string> indexToName;
vector<pair<string, int> > gangs;
int nCall, threshold, nPeople;
int call[MAX][MAX];
int cmp(pair<string, int> a, pair<string, int> b)
{
	return strcmp(a.first.c_str(), b.first.c_str()) < 0;
}
void bfs(int s, int &gangIndex, int &num)
{
	queue<int> que;
	que.push(s);
	visited[s] = 1;
	int gangTime = 0;
	int gangNum = 0;
	int maxTime = 0;
	while(!que.empty())
	{
		gangNum++;
		int tmp = que.front();
		que.pop();
		gangTime += times[tmp];
		if (times[tmp] > maxTime)
		{
			maxTime = times[tmp];
			gangIndex = tmp;
		}
		for (int i = 0; i < nPeople; ++i)
		{
			if (!visited[i] && call[tmp][i] > 0)
			{
				visited[i] = 1;
				que.push(i);
			}
		}
	}
	gangTime /= 2; 
	if (gangNum > 2 && gangTime > threshold)
	{
		num = gangNum;
	}else
		gangIndex = -1;      // no gang...
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	memset(times, 0, MAX * sizeof(int));
	memset(call, 0, MAX * MAX * sizeof(int));
	memset(visited, 0, MAX);
	cin>>nCall>>threshold;
	nPeople = 0;
	string a, b;
	int t;
	int index1, index2;
	map<string, int>::iterator iter;
	for (int i = 0; i < nCall; ++i)
	{
		cin>>a>>b>>t;
		iter = nameToIndex.find(a);
		if (iter != nameToIndex.end())
			index1 = iter->second;
		else
		{
			index1 = nPeople++;
			nameToIndex[a] = index1;
			indexToName.push_back(a);
		}
		iter = nameToIndex.find(b);
		if (iter != nameToIndex.end())
			index2 = iter->second;
		else
		{
			index2 = nPeople++;
			nameToIndex[b] = index2;
			indexToName.push_back(b);
		}
		times[index1] += t;
		times[index2] += t;
		call[index1][index2] += t;
		call[index2][index1] += t;
	}
	int gangIndex = -1, num = 0;
	for (int i = 0; i < nPeople; ++i)
	{
		if (!visited[i])
		{
			bfs(i, gangIndex, num);
			if (gangIndex != -1)
			{
				gangs.push_back(pair<string, int>(indexToName[gangIndex], num));
			}
		}
	}
	cout<<gangs.size()<<endl;
	sort(gangs.begin(), gangs.end(), cmp);    // sort the gang name
	for (int i = 0; i < gangs.size(); ++i)
	{
		cout<<gangs[i].first<<" "<<gangs[i].second<<endl;
	}
	return 0;
}