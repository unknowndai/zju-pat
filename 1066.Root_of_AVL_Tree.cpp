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
typedef struct TreeNode
{
	int val;
	TreeNode *left, *right;
	int height;                 // the height of leaf node is 0 
	TreeNode(int x) : val(x), left(NULL), right(NULL), height(0){}
}TreeNode;
// get the height of tree
int getHeight(TreeNode *root)
{
	if (root == NULL)
	{
		return -1;
	}else
		return root->height;
}
void adjustLL(TreeNode *&root)
{
	TreeNode *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
	root = tmp;
}
void adjustRR(TreeNode *&root)
{
	TreeNode *tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
	root = tmp;
}
void adjustLR(TreeNode *&root)
{
	adjustRR(root->left);
	adjustLL(root);
}
void adjustRL(TreeNode *&root)
{
	adjustLL(root->right);
	adjustRR(root);
}
void insert(TreeNode *&root, int x)
{
	if (root == NULL)
	{
		root = new TreeNode(x);
		return;
	}
	if (x < root->val) 
	{
		insert(root->left, x);
		if (abs(getHeight(root->left) - getHeight(root->right)) > 1)  // no balance
		{
			if (x > root->left->val)                  // adjust current node
			{
				adjustLR(root);
			}else
				adjustLL(root);
		}
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;  // reset the height of current node
	}else
	{
		insert(root->right, x);
		if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
		{
			if (x > root->right->val)
			{
				adjustRR(root);
			}else
				adjustRL(root);
		}
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num, tmp;
	cin>>num;
	TreeNode *root = NULL;
	for (int i = 0; i < num; ++i)
	{
		cin>>tmp;
		insert(root, tmp);
	}
	cout<<root->val;
	return 0;
}