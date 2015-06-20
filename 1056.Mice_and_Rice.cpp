#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int> weight;
int cmp(int a, int b)
{
	return weight[a] > weight[b];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int np, ng;
	cin>>np>>ng;
	weight.resize(np);
	vector<int> order(np, 0);
	vector<int> rank(np, 0);
	for (int i = 0; i < np; ++i)
	{
		cin>>weight[i];
	}
	for (int i = 0; i < np; ++i)
	{
		cin>>order[i];
	}
	vector<int> winers;        // all winers in every round
	while(!order.empty())
	{
		winers.clear();
		int sz = order.size();
		// if (sz <= ng)           // last round
		// {
		// 	sort(order.begin(), order.end(), cmp);  // sort in weight
		// 	for (int i = 0; i < sz; ++i)
		// 	{
		// 		rank[order[i]] = i + 1;
		// 	}
		// 	break;
		// }
		if (sz == 1)              // last one mouse
		{
			rank[order[0]] = 1;
			break;
		}
		int curRank = sz / ng + (sz % ng != 0) + 1;   
		for (int i = 0; i < curRank - 1; ++i)
		{
			int start = i * ng;
			int winer = order[start];         // the winer in one group
			int j = 1;
			while(j < ng && start + j < sz)
			{
				if (weight[order[start + j]] > weight[winer])
				{
					rank[winer] = curRank;
					winer = order[start + j];
				}else
					rank[order[start + j]] = curRank;
				j++;
			}
			winers.push_back(winer);
		}
		order = winers;            // for next round
	}
	for (int i = 0; i < np; ++i)
	{
		if (i != 0)
			cout<<" ";
		cout<<rank[i];
	}
	return 0;
}