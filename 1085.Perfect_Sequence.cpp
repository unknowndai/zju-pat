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
int getUp(vector<int> &seq, int mp, int start, int end)
{
	while(start < end)         // using binary search to save time
	{
		int mid = (start + end) / 2;
		if (seq[mid] <= mp)
		{
			start = mid + 1;
		}else
			end = mid;
	}
	return start;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num, p;
	cin>>num>>p;
	vector<int> seq(num);
	for (int i = 0; i < num; ++i)
	{
		cin>>seq[i];
	}
	sort(seq.begin(), seq.end());    // sort first
	int maxLen = 0;
	for (int i = 0; i < num; ++i)
	{
		long long mp = (long long)seq[i] * p;
		if (mp >= seq[num - 1])     // no more longer sequence
		{
			maxLen = num - i > maxLen ? num - i : maxLen;
			break;
		}
		// get the index of first element bigger than mp
		int index = getUp(seq, mp, i, num); 
		maxLen = index - i > maxLen ? index - i : maxLen;
	}
	cout<<maxLen;
	return 0;
}