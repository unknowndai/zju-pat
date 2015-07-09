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
bool hashTable[256] = {0};
void toUpper(string &str)
{
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] += ('A' - 'a');
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string originalStr, outStr;
	cin>>originalStr>>outStr;
	toUpper(originalStr);
	toUpper(outStr);
	int i = 0, j = 0;
	int originalLen = originalStr.length(), outLen = outStr.length();
	while(i < originalLen && j < outLen)
	{
		if (originalStr[i] == outStr[j])
		{
			i++;j++;
			continue;
		}else
		{
			if (!hashTable[originalStr[i]])
			{
				hashTable[originalStr[i]] = 1;
				cout<<originalStr[i];
			}
			i++;
		}
	}
	while (i < originalLen)               // the left original string
	{
		if (!hashTable[originalStr[i]])
		{
			hashTable[originalStr[i]] = 1;
			cout<<originalStr[i];
		}
		i++;
	}
	return 0;
}