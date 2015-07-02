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
vector<pair<int, int> > lists(100001);  // value, next
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int firstAddr, tol, k;
	cin>>firstAddr>>tol>>k;
	int node;
	for (int i = 0; i < tol; ++i)
	{
		cin>>node;
		cin>>lists[node].first>>lists[node].second;
	}
	lists[100000].second = firstAddr;         // pesudo head
	int pesudoHead = 100000;
	int pre = pesudoHead;
	while(1)
	{
		int cnt = 0;
		int tail = pre;
		while(tail != -1 && cnt < k)          // find the current tail of reversing list
		{
			cnt++;
			tail = lists[tail].second;
		}
		if (tail == -1)      				  // end reversing
		{
			break;
		}
		int nextPre = lists[pre].second;      // pre pointer to insert the list node
		int post = lists[lists[pre].second].second;
		int nextHead = lists[tail].second;    // next round of reversing list head
		while(post != nextHead)               // reversing the part of list
		{
			lists[nextPre].second = lists[post].second;
			lists[post].second = lists[pre].second;
			lists[pre].second = post;
			post = lists[nextPre].second;
		}
		pre = nextPre;
	}
	firstAddr = lists[pesudoHead].second;
	while(firstAddr != -1)
	{
		printf("%05d %d ", firstAddr, lists[firstAddr].first, lists[firstAddr].second);
		firstAddr = lists[firstAddr].second;
		if (firstAddr == -1)
		{
			cout<<"-1";
		}else
			printf("%05d\n", firstAddr);
	}
	return 0;
}