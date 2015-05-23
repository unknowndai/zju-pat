#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define EightCLOCK 480
#define FIVECLOCK 1020
typedef struct customer
{
	int serveTime;
	int leaveTime;
}customer;
int nWindow, numPerWin, nCustomer, nQuery;
vector<customer> customers;
vector<queue<int> > windows;   // the customers in line
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>nWindow>>numPerWin>>nCustomer>>nQuery;
	customers.resize(nCustomer);
	windows.resize(nWindow, queue<int>());
	int tolInLine = numPerWin * nWindow;
	for (int i = 0; i < nCustomer; ++i)
	{
		cin>>customers[i].serveTime;
		if (i < tolInLine)
		{
			int tmpWin = i % nWindow;
			int pos = i / nWindow;
			if (pos == 0)
			{
				customers[i].leaveTime = EightCLOCK + customers[i].serveTime;
			}else
				customers[i].leaveTime = customers[windows[tmpWin].back()].leaveTime + customers[i].serveTime;
			windows[tmpWin].push(i);
		}else
		{
			// choose the window had shortest line
			int index = 0, minTime = customers[windows[0].front()].leaveTime;
			for (int j = 1; j < nWindow; j++)
			{
				if (customers[windows[j].front()].leaveTime < minTime)
				{
					minTime = customers[windows[j].front()].leaveTime;
					index = j;
				}
			}
			customers[i].leaveTime = customers[windows[index].back()].leaveTime + customers[i].serveTime;
			windows[index].pop();
			windows[index].push(i);
		}
	}
	int tmp;
	for (int i = 0; i < nQuery; ++i)
	{
		cin>>tmp;
		tmp--;
		if (customers[tmp].leaveTime - customers[tmp].serveTime >= FIVECLOCK)
		{
			puts("Sorry");
		}else
			printf("%02d:%02d\n", customers[tmp].leaveTime / 60, customers[tmp].leaveTime % 60);
	}	
	return 0;
}