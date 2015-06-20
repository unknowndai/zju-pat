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
	int row, col;
	cin>>row>>col;
	int color = -1, cnt = 0;    // the color number
	// the cnt of dominant color will be greater than 0
	int curColor;
	for (int i = 0; i < row * col; ++i)
	{
		cin>>curColor;
		if (curColor == color)
		{
			cnt++;
		}else
		{
			if (cnt > 0)
			{
				cnt--;
			}else
			{
				color = curColor;
				cnt = 1;
			}
		}
	}
	cout<<color;
	return 0;
}