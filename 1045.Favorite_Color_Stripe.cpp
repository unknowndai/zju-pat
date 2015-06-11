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
	int nColor, nFavor, nStripe;
	cin>>nColor>>nFavor;
	vector<int> favor(nFavor);
	for (int i = 0; i < nFavor; ++i)
	{
		cin>>favor[i];
	}
	cin>>nStripe;
	vector<int> stripes(nStripe);
	for (int i = 0; i < nStripe; ++i)
	{
		cin>>stripes[i];
	}
	vector<vector<int> > dp(nFavor + 1, vector<int>(nStripe + 1));
	// init
	for (int i = 0; i <= nFavor; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= nStripe; ++i)
	{
		dp[0][i] = 0;
	}
	// like longest common subsequence
	for (int i = 1; i <= nFavor; ++i)
	{
		for (int j = 1; j <= nStripe; ++j)
		{
			int max = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			if (stripes[j - 1] == favor[i - 1])
				dp[i][j] = max + 1;
			else
				dp[i][j] = max;
		}
	}
	cout<<dp[nFavor][nStripe];
	return 0;
}