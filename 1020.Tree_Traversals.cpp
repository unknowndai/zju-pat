#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
}TreeNode;
TreeNode* buildTree(vector<int> &postOrder, vector<int> &inOrder,
	int postBegin, int postEnd, int inBegin, int inEnd)
{
	if (postBegin > postEnd)
		return NULL;
	TreeNode *root = new TreeNode(postOrder[postEnd]);
	// find the root in inorder
	int index = inBegin;
	while(inOrder[index] != postOrder[postEnd])
		index++;
	int numLeft = index - inBegin;    // the number of left nodes
	root->left = buildTree(postOrder, inOrder, postBegin, postBegin + numLeft - 1,
		inBegin, inBegin + numLeft - 1);
	root->right = buildTree(postOrder, inOrder, postBegin + numLeft, postEnd - 1,
		index + 1, inEnd);
	return root;
}
void printLevel(TreeNode *root)
{
	queue<TreeNode*> que;
	que.push(root);
	bool isFirst = true;
	while(!que.empty())
	{
		int sz = que.size();
		while(sz--)
		{
			TreeNode *tmp = que.front();
			que.pop();
			if (isFirst)
			{
				isFirst = false;
				cout<<tmp->val;
			}else
				cout<<" "<<tmp->val;
			if (tmp->left)
				que.push(tmp->left);
			if (tmp->right)
				que.push(tmp->right);
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	vector<int> postOrder(num, 0), inOrder(num, 0);
	for (int i = 0; i < num; ++i)
	{
		cin>>postOrder[i];
	}
	for (int i = 0; i < num; ++i)
	{
		cin>> inOrder[i];
	}
	TreeNode *root = buildTree(postOrder, inOrder, 0, num - 1, 0, num - 1);
	printLevel(root);
	return 0;
}