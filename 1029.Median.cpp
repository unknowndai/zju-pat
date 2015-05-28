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
	int num1, num2;
	cin>>num1;
	vector<int> data1(num1, 0);
	for (int i = 0; i < num1; ++i)
	{
		// using c-style input to save time
		scanf("%d", &data1[i]);
	}
	cin>>num2;
	vector<int> data2(num2, 0);
	for (int i = 0; i < num2; ++i)
	{
		scanf("%d", &data2[i]);
	}
	int mid = (num1 + num2 - 1) / 2;    // the middle position
	int i = 0, j = 0, index = 0;
	while(i < num1 && j < num2)
	{
		if (index == mid)
			break;
		if (data1[i] < data2[j])
			i++;
		else
			j++;
		index++;
	}
	int ret;
	if (i == num1)
	{
		ret = data2[j + mid - index];
	}else if (j == num2)
	{
		ret = data1[i + mid - index];
	}else
		ret = data1[i] < data2[j] ? data1[i] : data2[j];
	cout<<ret;
	return 0;
}