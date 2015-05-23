#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int rate[24];
typedef struct phoneRecord
{
	char name[21];    // up to 20 characters
	int mouth, day, hour, minute;
	bool onoff;       // 1 : on    0 : off
}phoneRecord;
vector<phoneRecord> record;
int cmp(phoneRecord a, phoneRecord b)
{
	if (strcmp(a.name, b.name) != 0)
	{
		return strcmp(a.name, b.name) < 0;
	}else if (a.day != b.day)
	{
		return a.day < b.day;
	}else if (a.hour != b.hour)
	{
		return a.hour < b.hour;
	}else 	
	{
		return a.minute < b.minute;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	for (int i = 0; i < 24; ++i)
	{
		cin>>rate[i];
	}
	int num;
	cin>>num;
	record.resize(num);
	char onoroff[10];
	for (int i = 0; i < num; ++i)
	{
		scanf("%s%d:%d:%d:%d%s", record[i].name, &record[i].mouth, &record[i].day,
			&record[i].hour, &record[i].minute, onoroff);
		if (onoroff[1] == 'n')   // on-line
		{
			record[i].onoff = 1;
		}else
			record[i].onoff = 0;
	}
	sort(record.begin(), record.end(), cmp);
	char curName[21];
	float tol = 0;
	for (int i = 0; i < num; )
	{
		strcpy(curName, record[i].name);
		i++;
		tol = 0;
		//printf("%s %02d\n", curName, record[i].mouth);
		bool hasBill = false;
		while(i < num && strcmp(curName, record[i].name) == 0)
		{
			// only deal with the off-line record
			if (record[i].onoff == 0 && record[i - 1].onoff == 1)
			{
				//case 2 and case 3
				// only print the customer had bill... I did not see where it said..
				if (!hasBill)
				{
					hasBill = true;
					printf("%s %02d\n", curName, record[i].mouth);
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d ", record[i - 1].day, record[i - 1].hour,
					record[i - 1].minute, record[i].day, record[i].hour, record[i].minute);
				// convert day to hour for avoiding to discuss different situations
				int beginHour = record[i - 1].day * 24 + record[i - 1].hour;
				int beginMinute = record[i - 1].minute;
				int endHour = record[i].day * 24 + record[i].hour;
				int tolMinute = 0;
				float tmpMoney = 0;
				while(beginHour < endHour)
				{
					tolMinute += (60 - beginMinute);
					tmpMoney += (60 - beginMinute) * rate[beginHour % 24];
					beginMinute = 0;
					beginHour++;
				}
				tolMinute += (record[i].minute - beginMinute);
				tmpMoney += (record[i].minute - beginMinute) * rate[endHour % 24];
				printf("%d $%.2f\n", tolMinute, tmpMoney / 100);
				tol += tmpMoney;
			}
			i++;
		}
		if (hasBill)
			printf("Total amount: $%.2f\n", tol / 100);
	}
	return 0;
}