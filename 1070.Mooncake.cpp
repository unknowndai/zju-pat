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
int cmp(pair<double, double> a, pair<double, double> b)
{
	return a.second > b.second;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	double need;
	cin>>num>>need;
	// case 2 : amounts are float
	vector<pair<double, double> > mooncake(num);         // amount and uint-price
	for (int i = 0; i < num; ++i)
	{
		cin>>mooncake[i].first;
	}
	double price;
	for (int i = 0; i < num; ++i)
	{
		cin>>price;
		mooncake[i].second = price / mooncake[i].first;
	}
	sort(mooncake.begin(), mooncake.end(), cmp);        // sort in uint-price
	double profit = 0;
	int i = 0;
	while(need > 0 && i < num)
	{
		if (need >= mooncake[i].first)
		{
			profit += mooncake[i].second * mooncake[i].first;
			need -= mooncake[i].first;
		}else
		{
			profit += mooncake[i].second * need;
			need = 0;
		}
		i++;
	}
	printf("%.2f", profit);
	return 0;
}