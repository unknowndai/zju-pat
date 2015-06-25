#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	vector<int> keys(num, 0);
	for (int i = 0; i < num; ++i)
	{
	 	cin>>keys[i];
	}
	sort(keys.begin(), keys.end());
	queue<pair<int, int> > que;
	que.push(pair<int, int>(0, num - 1));
	bool isFirst = true;
	while(!que.empty())
	{
		pair<int, int> tmp = que.front();   // the index range of current tree
		que.pop();
		int n = tmp.second - tmp.first + 1;     // the number of tree nodes
		int height = (int)(log(n) / log(2)) + 1;   // the height of tree
		int lastLevel = pow(2, height - 1);        // the maximum nodes number of bottom level
		int preLevel = lastLevel - 1;              // the nodes number except the bottom level
		// the nodes number of left subtree according to the nodes number of bottom level
		int leftNodes = preLevel / 2 + (n - preLevel >= lastLevel / 2 ? lastLevel / 2 : n - preLevel); 
		int rootIndex = tmp.first + leftNodes;     // root of current tree
		if (isFirst)
		{
			isFirst = false;
		}else
			cout<<" ";
		cout<<keys[rootIndex];                     // access the root
		if (rootIndex > tmp.first)                 // left subtree
		{
			que.push(pair<int, int>(tmp.first, rootIndex - 1));
		}
		if (rootIndex < tmp.second)                // right subtree
		{
			que.push(pair<int, int>(rootIndex + 1, tmp.second));
		}
	} 
	return 0;
}