#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
vector<pair<int, int> > treeNodes;   // left_index and right_index
int numNodes;                        // the number of nodes
vector<int> data;                    // input data
vector<int> nodeValues;              // node value
static int cnt = 0;                  // counter
// insert value into tree through in-order traversal
void inOrder(int root)
{
	if (root == -1)
	{
		return;
	}
	inOrder(treeNodes[root].first);
	nodeValues[root] = data[cnt++];
	inOrder(treeNodes[root].second);
}
// print the level order traversal sequence
void printLevel(int root)
{
	queue<int> que;
	que.push(root);
	bool isFirst = true;
	while(!que.empty())
	{
		int sz = que.size();
		while(sz--)
		{
			int tmp = que.front();
			que.pop();
			if (isFirst)
			{
				isFirst = false;
			}else
				cout<<" ";
			cout<<nodeValues[tmp];
			if (treeNodes[tmp].first != -1)        // push the left_index
				que.push(treeNodes[tmp].first);
			if (treeNodes[tmp].second != -1)       // push the right_index
				que.push(treeNodes[tmp].second);
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>numNodes;
	treeNodes.resize(numNodes);
	data.resize(numNodes);
	nodeValues.resize(numNodes);
	for (int i = 0; i < numNodes; i++)
		cin>>treeNodes[i].first>>treeNodes[i].second;
	for (int i = 0; i < numNodes; i++)
		cin>>data[i];
	sort(data.begin(), data.end());         // sort the input data
	inOrder(0);
	printLevel(0); 
	return 0;
}