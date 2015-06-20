#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct LinkList
{
	int addr, val, next;
}LinkList;
LinkList nodes[100000];
int num, head;
int cmp(LinkList a, LinkList b)
{
	return a.val < b.val;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>num>>head;
	int tmpAddr;
	for (int i = 0; i < num; ++i)
	{
		cin>>tmpAddr;
		nodes[tmpAddr].addr = tmpAddr;
		cin>>nodes[tmpAddr].val>>nodes[tmpAddr].next;
	}
	// get the list, maybe some given nodes not in the list...
	vector<LinkList> list;
	while(head != -1)
	{
		list.push_back(nodes[head]);
		head = nodes[head].next;
	}
	sort(list.begin(), list.end(), cmp);
	int sz = list.size();
	cout<<sz;
	// list is null
	if (sz == 0)
	{
		printf(" -1\n");
		return 0;
	}
	printf(" %05d\n", list[0].addr);
	for (int i = 0; i < sz; ++i)
	{
		printf("%05d %d ", list[i].addr, list[i].val);
		if (i == sz - 1)
			printf("-1");
		else
			printf("%05d\n", list[i + 1].addr);
	}
	return 0;
}