#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
string cards[54];
string color[] = {"S", "H", "C", "D", "J"};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	// init the cards
	for (int i = 0; i < 54; ++i)
	{
		char tmp[3];
		sprintf(tmp, "%d", i % 13 + 1);
		cards[i] = color[i / 13] + tmp;
	}
	vector<int> origin(54, 0), rule(54);
	int nLoop;
	cin>>nLoop;
	for (int i = 0; i < 54; ++i)
	{
		origin[i] = i + 1;
		cin>>rule[i];
	}
	vector<int> result(54);
	while(nLoop--)
	{
		for (int i = 0; i < 54; ++i)
		{
			result[rule[i] - 1] = origin[i];
		}
		origin = result;
	}
	for (int i = 0; i < 54; ++i)
	{
		if (i != 0)
			cout<<" ";
		cout<<cards[origin[i] - 1];
	}
	return 0;
}