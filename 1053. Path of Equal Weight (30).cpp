#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > res;
vector<vector<int> > treeNode(101, vector<int>()); 
vector<int> weight(101, 0);
void helper(vector<int> path, int curNode, int curWeight, int val)
{
	if (treeNode[curNode].size() == 0)    // left node
	{
		if (curWeight + weight[curNode] != val)
		{
			return;
		}
		path.push_back(weight[curNode]);
		res.push_back(path);
		return;
	}
	if (curWeight > val)
	{
		return;
	}
	curWeight += weight[curNode];
	path.push_back(weight[curNode]);
	for (int i = 0; i < treeNode[curNode].size(); ++i)
	{
		helper(path, treeNode[curNode][i], curWeight, val);
	}
	path.pop_back();
	return;
}
int cmp(int a, int b)
{
	return weight[a] > weight[b];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nodeNum, nonLeafNum, val;
	cin>>nodeNum>>nonLeafNum>>val;
	for (int i = 0; i < nodeNum; ++i)
	{
		cin>>weight[i];
	}
	
	for (int i = 0; i < nonLeafNum; ++i)
	{
		int root, cnt, tmp;
		cin>>root>>cnt;
		for (int j = 0; j < cnt; ++j)
		{
			cin>>tmp;
			treeNode[root].push_back(tmp);
		}
		// sort the weight
		sort(treeNode[root].begin(), treeNode[root].end(), cmp);
	}
	vector<int> path;
	helper(path, 0, 0, val);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			if (j == 0)
			{
				cout<<res[i][j];
			}else
				cout<<' '<<res[i][j];
		}
		cout<<endl;
	}
	return 0;
}