#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
// using binary indexed tree
#define MAX 100010
int BIT[MAX];
stack<int> sta;
int lowBit(int x)
{
	return x & (x ^ (x - 1));
}
void insert(int x, int val)
{
	while(x < MAX)
	{
		BIT[x] += val;
		x += lowBit(x);
	}
}
int getSum(int x)     // sum of BIT[1...x]
{
	int sum = 0;
	while(x > 0)
	{
		sum += BIT[x];
		x -= lowBit(x);
	}
	return sum;
}
int find(int x)        // binary search to find first x
{
	int low = 0, high = MAX - 1, mid;
	while(low < high)
	{
		mid = (low + high) / 2;
		int sum = getSum(mid);
		if (sum >= x)
		{
			high = mid;
		}else
			low = mid + 1;
	}
	return high;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	memset(BIT, 0, MAX * sizeof(int));
	int num = 0, nCmd, tmp;
	cin>>nCmd;
	char cmd[11];
	for (int i = 0; i < nCmd; ++i)
	{
		// use c-style input
		scanf("%s", cmd);
		switch (cmd[1])
		{
			case 'u':      // push
				scanf("%d", &tmp);
				sta.push(tmp);
				insert(tmp, 1);
				num++;
				break;
			case 'o':      // pop
				if (num <= 0) printf("Invalid\n");
				else
				{
					printf("%d\n", sta.top());
					insert(sta.top(), -1);
					sta.pop();
					num--;
				}
				break;
			case 'e':      // peekMedian
				if (num <= 0) printf("Invalid\n");
				else
				{
					printf("%d\n", find((num + 1) / 2));
				}
				break;
		}
	}
	return 0;
}