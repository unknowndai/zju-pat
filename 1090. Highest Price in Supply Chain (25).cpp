#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int> > relation;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	double price, incresment;       // not exceed 10^10; double instead of float
	cin>>num>>price>>incresment;
	relation.resize(num);
	int root;   // root supplier
	for (int i = 0; i < num; ++i)
	{
		int tmp;
		cin>>tmp;
		if (tmp == -1)
		{
			root = i;
			continue;
		}
		relation[tmp].push_back(i);   // build relation tree
	}
	int members = 0, level = -1;
	queue<int> que;
	que.push(root);
	// bfs
	while(!que.empty())
	{
		int sz = que.size();
		members = sz;           // members number in every level
		level++;                // get the height of tree
		while(sz--)
		{
			int tmp = que.front();
			que.pop();
			for(int i = 0; i < relation[tmp].size(); i++)
			{
				que.push(relation[tmp][i]);
			}
		}
	}
	while(level--)
	{
		price += price * incresment / 100;
	}
	printf("%.2f %d", price, members);
	return 0;
}