#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
typedef struct carInfo{
	char number[8];      // plate_number
	int time;			 // the in/out time
	bool isIn;           // true : in
}carInfo;
vector<carInfo> cars;     // input data
vector<int> carCnt;
int numCar, numQuery;    // the number of cars and queries 
// binary search for finding first time bigger than t
int findHigh(int t)      //case 4
{
	if (t < cars[0].time)
	{
		return 0;
	}else if (t >= cars[numCar - 1].time)
	{
		return numCar;
	}
	int l = 0, r = numCar - 1, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if (cars[mid].time <= t)
		{
			l = mid + 1;
		}else
			r = mid;
	}
	return r;
}
// sort in plate_number
int cmp(carInfo a, carInfo b)
{
	if (strcmp(a.number, b.number) == 0)
	{
		return a.time < b.time;
	}else
		return strcmp(a.number, b.number) < 0;
}
// sort in in/out time
int cmp2(carInfo a, carInfo b)
{
	return a.time < b.time;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>numCar>>numQuery;
	int h, m, s;
	string status;
	// input data
	for (int i = 0; i < numCar; ++i)
	{
		carInfo tmp;
		scanf("%s", tmp.number);
		scanf("%d:%d:%d", &h, &m, &s);
		tmp.time = h * 3600 + m * 60 + s;
		cin>>status;
		if (status == "in")
		{
			tmp.isIn = 1;
		}else
			tmp.isIn = 0;
		cars.push_back(tmp);
	}
	sort(cars.begin(), cars.end(), cmp);
	int maxTime = 0;
	vector<string> longCar;     // the cars parked longest time
	string preCar;              // the plate_number of last car
	int parkingTime;            // record the parking time
	for (auto it = cars.begin(); it != cars.end();)
	{
		// erase the useless data
		if ((*it).isIn != 1 || strcmp((*it).number, (*(it + 1)).number) != 0 || (*(it + 1)).isIn == 1)
		{
			it = cars.erase(it);
			numCar--;
			continue;
		}
		// is it same with last car?
		if (strcmp((*it).number, preCar.c_str()) != 0)
		{
			preCar = string((*it).number);
			parkingTime = (*(it + 1)).time - (*it).time;
		}else
			parkingTime += (*(it + 1)).time - (*it).time;
		if (parkingTime > maxTime)
		{
			maxTime = parkingTime;
			longCar.clear();
			longCar.push_back(preCar);
		}else if (parkingTime == maxTime)
		{
			longCar.push_back(preCar);
		}
		it += 2;
	}
	sort(cars.begin(), cars.end(), cmp2);
	int cnt = 0;
	// record the car count in all in/out time
	for (int i = 0; i < numCar; ++i)
	{
		if (cars[i].isIn)
		{
			cnt++;
		}else
			cnt--;
		carCnt.push_back(cnt);
	}
	for (int i = 0; i < numQuery; ++i)
	{
		scanf("%d:%d:%d", &h, &m, &s);
		int t = h * 3600 + m * 60 + s;
		int j = findHigh(t);
		if (j == 0)
		{
			cout<<'0'<<endl;
		}else
			cout<<carCnt[j - 1]<<endl;
	}
	for (int i = 0; i < longCar.size(); ++i)
	{
		cout<<longCar[i]<<' ';
	}
	printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	return 0;
}