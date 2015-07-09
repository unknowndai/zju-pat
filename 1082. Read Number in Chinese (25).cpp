#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
string number[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string yiwan[] = {"Yi", "Wan", ""};
string qianbai[] = {"Qian", "Bai", "Shi", ""};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	if (num == 0)            // case 3 : input is 0
	{
		cout<<number[0];
		return 0;
	}
	bool isFirst = true;     // is it first output?
	if (num < 0)
	{
		isFirst = false;
		cout<<"Fu";
		num *= -1;
	}
	int factor = 100000000;
	bool isFirstDigit = true;
	bool isPreZero = false;       // pre-zero to avoid the unnecessary ling
	for (int i = 0; i < 3; ++i)
	{
		if (num / factor != 0)
		{
			int cur = num / factor;
			int tmpFactor = 1000;
			isPreZero = false;
			for (int j = 0; j < 4 && cur != 0; ++j)
			{
				if (cur / tmpFactor != 0)
				{
					if (!isFirst)
					{
						cout<<' ';
					}
					isFirst = false;
					isFirstDigit = false;
					cout<<number[cur / tmpFactor];
					if (j < 3)            // qian, bai or shi
					{
						cout<<' '<<qianbai[j];
					}
					isPreZero = false;
				}else if (!isFirstDigit && !isPreZero)  // insert ling
				{
					cout<<' '<<number[0];
					isPreZero = true;
				}
				cur %= tmpFactor;
				tmpFactor /= 10;
			}
			if (i < 2)            // yi or wan
			{
				cout<<' '<<yiwan[i];
			}
		}
		num %= factor;
		factor /= 10000;
	}
	return 0;
}