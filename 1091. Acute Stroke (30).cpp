#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
bool slice[1286][128][60];
int row, col, height, volume;
typedef struct point
{
	int x, y, z;
	point(int x, int y, int z) : x(x), y(y), z(z){}
}point;
// segment fault, maybe too much recursion
void dfs(int i, int j, int k, int &cnt)
{
	slice[i][j][k] = 0;
	cnt++;
	if (i > 0 && slice[i - 1][j][k])
	{
		dfs(i - 1, j, k, cnt);
	}
	if (i + 1 < row && slice[i + 1][j][k])
	{
		dfs(i + 1, j, k, cnt);
	}
	if (j > 0 && slice[i][j - 1][k])
	{
		dfs(i, j - 1, k, cnt);
	}
	if (j + 1 < col && slice[i][j + 1][k])
	{
		dfs(i, j + 1, k, cnt);
	}
	if (k > 0 && slice[i][j][k - 1])
	{
		dfs(i, j, k - 1, cnt);
	}
	if (k + 1 < height && slice[i][j][k + 1])
	{
		dfs(i, j, k + 1, cnt);
	}
}
int bfs(int i, int j, int k)
{
	int cnt = 0;
	queue<point> que;
	que.push(point(i, j, k));
	slice[i][j][k] = 0;
	while(!que.empty())
	{
		point p = que.front();
		i = p.x; j = p.y; k = p.z;
		que.pop();
		cnt++;
		// left
		if (i > 0 && slice[i - 1][j][k])
		{
			slice[i - 1][j][k] = 0;
			que.push(point(i - 1, j, k));
		}
		// right
		if (i + 1 < row && slice[i + 1][j][k])
		{
			slice[i + 1][j][k] = 0;
			que.push(point(i + 1, j, k));
		}
		// back
		if (j > 0 && slice[i][j - 1][k])
		{
			slice[i][j - 1][k] = 0;
			que.push(point(i, j - 1, k));
		}
		// front
		if (j + 1 < col && slice[i][j + 1][k])
		{
			slice[i][j + 1][k] = 0;
			que.push(point(i, j + 1, k));
		}
		// up
		if (k > 0 && slice[i][j][k - 1])
		{
			slice[i][j][k - 1] = 0;
			que.push(point(i, j, k - 1));
		}
		// down
		if (k + 1 < height && slice[i][j][k + 1])
		{
			slice[i][j][k + 1] = 0;
			que.push(point(i, j, k + 1));
		}
	}
	return cnt;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>row>>col>>height>>volume;
	// input
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				cin>>slice[j][k][i];
	int cnt = 0, ret = 0;            // cnt : the number of connected pixels
	for (int k = 0; k < height; k++)
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (slice[i][j][k])
				{
					//cnt = 0;
					//dfs(i, j, k, cnt);
					cnt = bfs(i, j, k);
					if (cnt >= volume)
					{
						ret += cnt;
					}
				}
			}
	cout<<ret;
	return 0;
}
