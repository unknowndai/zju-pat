#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	long long cnt = 0;
	int factor = 1, lowNum, hightNum, curNum;
	// the idea from the book "Beauty of programming"
	while(num / factor != 0)
	{
		hightNum = num / factor / 10;
		lowNum = num % factor;
		curNum = num / factor % 10;
		if (curNum == 0)
		{
			cnt += hightNum * factor;
		}else if (curNum == 1)
		{
			cnt += hightNum * factor + lowNum + 1;
		}else
			cnt += (hightNum + 1) * factor;
		factor *= 10;
	}
	cout<<cnt;
	return 0;
}