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
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string beads, pattern;
	cin>>beads>>pattern;
	int numBead[256] = {0};          // count the number of every bead in pattern
	int patternLen = pattern.length();
	for (int i = 0; i < patternLen; i++)
		numBead[pattern[i]]++;
	int beadsLen = beads.length();
	int foundCnt = 0;
	for (int i = 0; i < beadsLen; i++)
	{
		if (numBead[beads[i]])       // is it in pattern?
		{
			foundCnt++;
			numBead[beads[i]]--;
		}
	}
	if (foundCnt == patternLen)
		cout<<"Yes "<<beadsLen - foundCnt;
	else
		cout<<"No "<<patternLen - foundCnt;
	return 0;
}