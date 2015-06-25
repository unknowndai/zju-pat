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
	int nCoins, payment;
	cin>>nCoins>>payment;
	vector<int> coins(nCoins, 0);
	for (int i = 0; i < nCoins; ++i)
	{
		cin>>coins[i];
	}
	sort(coins.begin(), coins.end(), greater<int>());
	vector<vector<int> > dp(nCoins + 1, vector<int>(payment + 1, 0));
	// knapsack
	for (int i = 1; i <= nCoins; ++i)
	{
		for (int j = 1; j <= payment; ++j)
		{
			if (coins[i - 1] <= j)
			{
				dp[i][j] = max(coins[i - 1] + dp[i - 1][j - coins[i - 1]], dp[i - 1][j]);
			}
		}
	}
	if (dp[nCoins][payment] != payment)
	{
		cout<<"No Solution";
		return 0;
	}
	//output the smallest sequence
	int i = nCoins, j = payment;
	bool isFirst = true;
	while(i >= 1 && dp[i][j] != 0)
	{
		// need the current coin
		if (dp[i - 1][j - coins[i - 1]] + coins[i - 1] == j)
		{
			if (isFirst)
			{
				isFirst = false;
			}else
				cout<<" ";
			cout<<coins[i - 1];
			j -= coins[i - 1];
		}
		i--;
	}
	return 0;
}