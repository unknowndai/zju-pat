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
	vector<int> diamonds;
	int num, cost;
	cin>>num>>cost;
	diamonds.resize(num);
	for (int i = 0; i < num; ++i)
	{
		scanf("%d", &diamonds[i]);
	}
	int minCost = 0x7FFFFFFF;
	int pre = 0, post = 0;
	vector<pair<int, int> > ret;
	int sum = diamonds[0];
	while(pre < num)
	{
		if (sum < cost)
		{
			if (++pre >= num)
			{
				break;
			}
			sum += diamonds[pre];
		}else
		{
			if (sum == minCost)
			{
				ret.push_back(pair<int, int>(post, pre));
			}else if (sum < minCost)
			{
				minCost = sum;
				ret.clear();
				ret.push_back(pair<int, int>(post, pre));
			}
			sum -= diamonds[post];
			post++;
		}
	}
	int sz = ret.size();
	for (int i = 0; i < sz; ++i)
	{
		// case 3: output too much to use "cout"
		//cout<<ret[i].first + 1<<"-"<<ret[i].second + 1<<endl;
		printf("%d-%d\n", ret[i].first + 1, ret[i].second + 1);
	}
	return 0;
}