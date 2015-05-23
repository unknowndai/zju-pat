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
	int num, radix;
	cin>>num>>radix;
	if (num == 0)
	{
		cout<<"Yes"<<endl;
		cout<<"0";
		return 0;
	}
	vector<int> digits;
	while(num)
	{
		digits.push_back(num % radix);
		num /= radix;
	}
	int halfSize = digits.size()/2;
	int i = 0;
	for (int j = digits.size() - 1; i < halfSize; ++i, --j)
	{
		if (digits[i] != digits[j])
		{
			cout<<"No"<<endl;
			break;
		}
	}
	if (i == halfSize)
	{
		cout<<"Yes"<<endl;
	}
	for (int i = digits.size() - 1; i >= 0; --i)
	{
		cout<<digits[i];
		if (i != 0)
		{
			cout<<" ";
		}
	}
	return 0;
}