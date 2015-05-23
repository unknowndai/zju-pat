#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
char indexToChar[] = {'W', 'T', 'L'};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	float tol = 1.0;
	float odd[3];
	int index = 0;
	for (int i = 0; i < 3; ++i)
	{
		index = 0;
		for (int j = 0; j < 3; ++j)
		{

			cin>>odd[j];
			if (odd[j] > odd[index])
			{
				index = j;
			}
		}
		if (i != 0)
		{
			cout<<' ';
		}
		cout<<indexToChar[index];
		tol *= odd[index];
	}
	cout<<' ';
	printf("%.2f", (tol * 0.65 - 1) * 2);
	return 0;
}