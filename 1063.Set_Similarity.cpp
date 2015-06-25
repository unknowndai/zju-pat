#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nSet, st;
	cin>>nSet;
	vector<vector<int> > vSet(nSet);
	for (int i = 0; i < nSet; ++i)
	{
		cin>>st;
		vSet[i].resize(st);
		for (int j = 0; j < st; ++j)
		{
			cin>>vSet[i][j];
		}
		// sort first
		sort(vSet[i].begin(), vSet[i].end());
	}
	int nQuery, a, b;
	cin>>nQuery;
	while (nQuery--)
	{
		cin>>a>>b;
		a--;b--;
		int nc = 0, nt = 0, i = 0, j = 0;
		int st_a = vSet[a].size(), st_b = vSet[b].size();
		while (i < st_a && j < st_b)
		{
			// same with former element
			if (i != 0 && vSet[a][i] == vSet[a][i - 1])
			{
				i++;
				continue;
			}
			if (j != 0 && vSet[b][j] == vSet[b][j - 1])
			{
				j++;
				continue;
			}
			// common number
			if (vSet[a][i] == vSet[b][j])
			{
				nc++;nt++;i++;j++;
			}else if (vSet[a][i] < vSet[b][j])
			{
				i++;nt++;
			}else
			{
				j++;nt++;
			}
		}
		// the rest numbers
		while(i < st_a)
		{
			if (vSet[a][i] != vSet[a][i - 1])
			{
				nt++;
			}
			i++;
		}
		while(j < st_b)
		{
			if (vSet[b][j] != vSet[b][j - 1])
			{
				nt++;
			}
			j++;
		}
		double sim = (double)nc / nt * 100;
		printf("%.1f%%\n", sim);
	}
	return 0;
}