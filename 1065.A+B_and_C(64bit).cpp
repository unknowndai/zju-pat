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
// I think the number range [-2^63, 2^63] is not appropriate in the description
// maybe is [-2^63, 2^63 - 1]
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	long long a, b, c, res;
	bool flag;
	for (int i = 0; i < num; ++i)
	{
		cin>>a>>b>>c;
		res = a + b;
		if (a > 0 && b > 0 && res <= 0)       // positive overflow
		{
			flag = true;
		}else if (a < 0 && b < 0 && res >= 0) // negtive overflow
		{
			flag = false;
		}else if (res > c)
		{
			flag = true;
		}else
			flag = false;
		cout<<"Case #"<<i + 1<<": "<<(flag ? "true" : "false")<<endl;
	}
	return 0;
}