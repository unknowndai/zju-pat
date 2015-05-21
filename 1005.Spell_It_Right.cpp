#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
string eng[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str;
	cin>>str;
	int ret = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		ret += str[i] - '0';
	}
	stack<int> sta;
	if (ret == 0)
	{
		sta.push(0);
	}
	while(ret)
	{
		sta.push(ret % 10);
		ret /= 10;
	}
	bool isFirst = true;
	while(!sta.empty())
	{
		if (isFirst)
		{
			isFirst = false;
		}else
			cout<<" ";
		cout<<eng[sta.top()];
		sta.pop();
	}
	return 0;
}