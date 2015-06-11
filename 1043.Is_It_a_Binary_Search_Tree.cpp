#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;
vector<int> preTree;
int num;
bool isMirror;        // is it mirror?
bool isBST(int s, int e)
{
	if (s >= e)
	{
		return true;
	}
	if (!isMirror)    // BST
	{
		int i = s + 1;
		while(i <= e && preTree[i] < preTree[s])
			i++;
		bool bLeft = isBST(s + 1, i - 1);     // left subtree
		int j = i;
		while(i <= e && preTree[i] >= preTree[s])
			i++;
		if (i <= e)
		{
			return false;
		}
		return bLeft && isBST(j, e);
	}else             // mirror BST
	{
		int i = s + 1;
		while(i <= e && preTree[i] >= preTree[s])
			i++;
		bool bLeft = isBST(s + 1, i - 1);
		int j = i;
		while(i <= e && preTree[i] < preTree[s])
			i++;
		if (i <= e)
		{
			return false;
		}
		return bLeft && isBST(j, e);

	}
}
stack<int> postOrder;
void getPost(int s, int e)
{
	if (s > e)                     // empty tree
	{
		return;
	}
	postOrder.push(preTree[s]);    // push the root into stack
	if (!isMirror)
	{
		int mid = s + 1;
		while(mid <= e && preTree[mid] < preTree[s])
			mid++;
		getPost(mid, e);          // push right subtree into stack
		getPost(s + 1, mid - 1);  // then push left subtree
	}else
	{
		int mid = s + 1;
		while(mid <= e && preTree[mid] >= preTree[s])
			mid++;
		getPost(mid, e);
		getPost(s + 1, mid - 1);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>num;
	preTree.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin>>preTree[i];
	}
	isMirror = false;
	int k = 2;
	while(k--)
	{
		if (isBST(0, num - 1))
		{
			cout<<"YES"<<endl;
			getPost(0, num - 1);
			cout<<postOrder.top();    // get the post order
			postOrder.pop();
			while(!postOrder.empty())
			{
				cout<<" "<<postOrder.top();
				postOrder.pop();
			}
			return 0;
		}
		isMirror = !isMirror;
	}
	cout<<"NO";
	return 0;
}