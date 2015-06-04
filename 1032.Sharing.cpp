#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define MAX 100000
int firstAddr, secondAddr, nodes;
vector<pair<char, int> > list(MAX); 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>firstAddr>>secondAddr>>nodes;
	// construct the two lists
	int addr, next;
	char ch;
	for (int i = 0; i < nodes; ++i)
	{
		cin>>addr>>ch>>next;
		list[addr] = pair<char, int>(ch, next);
	}
	// calculate the length of two lists
	int head = firstAddr, len1 = 0, len2 = 0;
	while(head != -1)
	{
		len1++;
		head = list[head].second;
	}
	head = secondAddr;
	while(head != -1)
	{
		len2++;
		head = list[head].second;
	}
	int diff = len1 - len2;
	// move diff steps in longer list
	if (diff > 0)
	{
		while(diff--)
			firstAddr = list[firstAddr].second;
	}else
	{
		diff = -diff;
		while(diff--)
			secondAddr = list[secondAddr].second;
	}
	// moving together
	while(firstAddr != secondAddr)
	{
		firstAddr = list[firstAddr].second;
		secondAddr = list[secondAddr].second;
	}
	if (firstAddr == -1)
		cout<<"-1";
	else      // do not forget the prefix '0's
		printf("%05d", firstAddr);
	return 0;
}