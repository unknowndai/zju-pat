#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> preorder, inorder;      // pre-order and in-order traversal
typedef struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
}TreeNode;
// start and end are indexs in pre-order sequence
// start2 and end2 are indexs in in-order sequence
TreeNode* buildTree(int start, int end, int start2, int end2)
{
	if (start >= end)
	{
		return new TreeNode(preorder[start]);
	}
	int rootVal = preorder[start];
	TreeNode *root = new TreeNode(rootVal);
	int i = start2;
	// find the root position in in-order sequence
	while(inorder[i] != rootVal)
	{
		i++;
	}
	// build the left subtree
	if (i != start2)
	{
		root->left = buildTree(start + 1, start + i - start2, start2, i - 1);
	}
	// build the right subtree
	if (i != end2)
	{
		root->right = buildTree(start + i - start2 + 1, end, i + 1, end2);
	}
	return root;
}	
bool isFirst = true;   // is it first element?
void printPost(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printPost(root->left);
	printPost(root->right);
	if (isFirst)
	{
		isFirst = false;
		printf("%d", root->val);
	}else
		printf(" %d", root->val);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int cnt;
	cin>>cnt;
	stack<int> sta;
	for (int i = 0; i < cnt * 2; ++i)
	{
		string tmp;
		cin>>tmp;
		if (tmp == "Push")
		{
			int data;
			cin>>data;
			preorder.push_back(data);      
			sta.push(data);
		}else
		{
			int data = sta.top();
			sta.pop();
			inorder.push_back(data);
		}
	}
	TreeNode *root = buildTree(0, cnt - 1, 0, cnt -1);
	printPost(root);
	return 0;
}