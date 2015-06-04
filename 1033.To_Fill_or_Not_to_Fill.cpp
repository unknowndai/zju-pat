#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct gasStation
{
	float distance;
	float price;
}gasStation;
gasStation station[501];
int cmp(gasStation a, gasStation b)
{
	return a.distance < b.distance;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	float capacity, totalDis, perDis;
	int nStation;
	cin>>capacity>>totalDis>>perDis>>nStation;
	for (int i = 0; i < nStation; ++i)
	{
		cin>>station[i].price>>station[i].distance;
	}
	sort(station, station + nStation, cmp);
	station[nStation].distance = totalDis;     // insert the destination
	station[nStation].price = 0.0;
	float cost = 0.0;
	float maxDis = perDis * capacity;

	if (station[0].distance > 0)
	{
		cout<<"The maximum travel distance = 0.00";
		return 0;	
	}
	float curDis = 0.0;
	for (int i = 0; i <= nStation; ++i)
	{
		if (i != 0 && station[i].distance - station[i - 1].distance > maxDis)
		{
			cout<<"The maximum travel distance = ";
			printf("%.2f", station[i - 1].distance + maxDis);
			return 0;
		}
		if (i != 0 && curDis > 0)
		{
			curDis -= (station[i].distance - station[i - 1].distance);
		}
		int index = i + 1;
		while(index <= nStation && station[index].distance - station[i].distance <= maxDis && station[index].price >= station[i].price)
			index++;
		if (index == nStation + 1)  // destination
		{
			cost += (station[index - 1].distance - station[i].distance - curDis) * station[i].price;
			break;
		}else if (station[index].distance - station[i].distance > maxDis) // full
		{
			cost += (maxDis - curDis) * station[i].price;
			curDis = maxDis;
		}else if (station[index].price < station[i].price)    // more cheap
		{
			int tmp = station[index].distance - station[i].distance - curDis;
			if (tmp > 0)  // need to charge
			{
				cost += tmp * station[i].price;
				curDis += tmp;
			}
		}
	}
	printf("%.2f", cost / perDis);
	return 0;
}