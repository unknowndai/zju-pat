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
	cout<<num<<"=";
	if (num == 1)       // case 3
	{
		printf("1");
		return 0;
	}
	vector<pair<int, int> > primes;
	for (int i = 2; num != 1; ++i)
	{
		if (num % i == 0)
		{
			int cnt = 0;
			while(num % i == 0)
			{
				num /= i;
				cnt++;
			}
			primes.push_back(pair<int, int>(i, cnt));
		}
	}
	int sz = primes.size();
	for (int i = 0; i < sz; ++i)
	{
		if (i)
		{
			printf("*");
		}
		printf("%d", primes[i].first);
		if (primes[i].second > 1)
		{
			printf("^%d", primes[i].second);
		}
	}
	return 0;
}