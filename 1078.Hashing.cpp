#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
bool isPrime(int data)
{
	if (data == 1)             // case 1 
	{
		return false;
	}
	int end = sqrt(data);
	for (int i = 2; i <= end; ++i)
	{
		if (data % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int size, num;
	cin>>size>>num;
	while(!isPrime(size))       // get the table size
		size++;
	vector<int> table(size, 0);
	int data, pos;
	for (int i = 0; i < num; ++i)
	{
		cin>>data;
		pos = data % size;
		bool isFailed = false;
		if (table[pos])    // collisions
		{
			int j = 1;
			while(table[pos] && j < size)   // quadratic probing
			{
				pos = (data + j * j) % size;
				j++;
			}
			if (j == size)
			{
				isFailed = true;
			}
		}
		if (isFailed)     // can not insert
		{
			if (i != 0)
				cout<<" ";
			cout<<'-';
		}else
		{
			table[pos] = data;
			if (i != 0)
				cout<<" ";
			cout<<pos;
		}
	}
	return 0;
}