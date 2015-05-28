#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
string convert(int val)
{
	string ret;
	for (int i = 0; i < 2; ++i)
	{
		int tmp = val % 13;
		val /= 13;
		if (tmp > 9)
		{
			ret.insert(0, 1, tmp - 10 + 'A');
		}else
			ret.insert(0, 1, tmp + '0');
	}
	return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int rgb[3];
	cin>>rgb[0]>>rgb[1]>>rgb[2];
	cout<<"#";
	for (int i = 0; i < 3; i++)
	{
		cout<<convert(rgb[i]);
	}
	return 0;
}