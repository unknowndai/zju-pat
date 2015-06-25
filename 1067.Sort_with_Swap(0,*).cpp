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
	int num;
	cin>>num;
	vector<int> data(num, 0);
	for (int i = 0; i < num; ++i)
	{
		//cin>>data[i];
		scanf("%d", &data[i]);
	}
	int minStep = 0;
	int pos = 1;
	while(1)
	{
		if (data[0] == 0)
		{
			int i = pos;       // the numbers before pos are in right position
			while(i < num)
			{
				if (data[i] != i)
					break;
				i++;
			}
			if (i == num)      // all numbers are in right position
			{
				break;
			}else
				swap(data[0], data[i]);
			pos = i;          
		}else
			swap(data[0], data[data[0]]);
		minStep++;
	}
	cout<<minStep;
	return 0;
}