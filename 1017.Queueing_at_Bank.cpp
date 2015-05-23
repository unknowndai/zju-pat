#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define EIGHTCLOCK 28800   // eight clock in second
#define FIVECLOCK 54000
vector<int> windows;
vector<pair<int, int> > customers;    // arriving time and processing time
int cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nCustomer, nWindow, h, m, s, processTime, tmp;
	cin>>nCustomer>>nWindow;
	windows.resize(nWindow, EIGHTCLOCK);
	int nDelete = 0;
	for (int i = 0; i < nCustomer; ++i)
	{
		scanf("%d:%d:%d%d", &h, &m, &s, &processTime);
		tmp = h * 3600 + m * 60 + s;
		if (tmp > FIVECLOCK)
		{
			nDelete++;   // "nCustomer--" at first, so stupid
			continue;
		}
		processTime = processTime > 60 ? 60 : processTime;
		customers.push_back(pair<int, int>(tmp, processTime));
	}
	nCustomer -= nDelete;
	sort(customers.begin(), customers.end(), cmp);
	int waitTime = 0;
	for (int i = 0; i < nCustomer; ++i)
	{
		// choose one window
		int index = 0, minTime = windows[0];
		for (int j = 1; j < nWindow; j++)
			if (windows[j] < minTime)
			{
				index = j;
				minTime = windows[j];
			}
		// update the window 
		waitTime += (customers[i].first > minTime ? 0 : minTime - customers[i].first);
		windows[index] = (customers[i].first > minTime ? customers[i].first + customers[i].second * 60
			: windows[index] + customers[i].second * 60);
	}
	printf("%.1f", (float)waitTime / nCustomer / 60.0);
	return 0;
}