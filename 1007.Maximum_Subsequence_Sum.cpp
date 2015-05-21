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
	vector<int> data(num, 0);
	int maxi, maxj, tmpi, tmpj, maxSum = -1;
	int sum = 0;
	for (int i = 0; i < num; ++i)
	{
		cin>>data[i];
		if (sum > 0)
		{
			sum += data[i];
			tmpj = i;
		}else
		{
			sum = data[i];
			tmpi = i;
			tmpj = i;
		}
		if (sum > maxSum)
		{
			maxSum = sum;
			maxi = tmpi;
			maxj = tmpj;
		}
	}
	if (maxSum < 0)
	{
		printf("0 %d %d", data[0], data[num - 1]);
	}else
		printf("%d %d %d", maxSum, data[maxi], data[maxj]);
	return 0;
}