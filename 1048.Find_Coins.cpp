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
	int num, payment;
	cin>>num>>payment;
	vector<int> coins(num, 0);
	for (int i = 0; i < num; ++i)
	{
		cin>>coins[i];
	}
	sort(coins.begin(), coins.end());
	int i = 0, j = coins.size() - 1, tmp;
	while(i < j)
	{
		tmp = coins[i] + coins[j];
		if (tmp == payment)
		{
			cout<<coins[i]<<' '<<coins[j];
			return 0;
		}else if (tmp > payment)
		{
			j--;
		}else 
			i++;
	}
	cout<<"No Solution";
	return 0;
}