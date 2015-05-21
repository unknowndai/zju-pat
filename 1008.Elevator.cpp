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
	int nFloors;
	cin>>nFloors;
	int tolTime = 0, tmp, pre = 0;
	for (int i = 0; i < nFloors; ++i)
	{
		cin>>tmp;
		if (tmp > pre)
		{
			tolTime += (tmp - pre) * 6;
		}else if (tmp < pre)
		{
			tolTime += (pre - tmp) * 4;
		}
		tolTime += 5;
		pre = tmp;
	}
	cout<<tolTime;
	return 0;
}