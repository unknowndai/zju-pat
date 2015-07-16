#include<iostream>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	int maxLen = 0, start = 2;
	for (long long i = 2; i * i <= num; i++)
	{
		int tmp = num;
		for (long long j = i; j < num; j++)
		{
			if (tmp % j == 0)
			{
				tmp /= j;
			}else
			{
				if (j - i > maxLen)
				{
					maxLen = j - i;
					start = i;
				}
				break;
			}
		}
	}
	if (maxLen == 0)       // prime number
	{
		cout<<'1'<<endl<<num;
		return 0;
	}
	cout<<maxLen<<endl;    // output
	for (int i = 0; i < maxLen; ++i)
	{
		if (i != 0)
			cout<<"*";
		cout<<start++;
	}
	return 0;
}
