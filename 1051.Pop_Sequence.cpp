#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int capacity, len, nQuery;
	cin>>capacity>>len>>nQuery;
	vector<int> seq(len, 0);
	while(nQuery--)
	{
		stack<int> sta;
		for (int i = 0; i < len; ++i)
		{
			cin>>seq[i];
		}
		int i = 0, data = 1;
		while(i < len)
		{
			while(sta.empty() || sta.top() != seq[i])
			{
				sta.push(data++);
				if (sta.size() > capacity)
				{
					break;
				}
			}
			if (sta.size() > capacity)
			{
				break;
			}
			i++;
			sta.pop();
		}
		if (i == len)
		{
			cout<<"YES"<<endl;
		}else
			cout<<"NO"<<endl;
	}
	return 0;
}