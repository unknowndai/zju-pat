#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str[4];
	cin>>str[0]>>str[1]>>str[2]>>str[3];
	int len1 = str[0].length(), len2 = str[1].length();
	int j = 0;
	while(j < len1 && j < len2)
	{
		// first common capital English letter 'A' to 'G'
		if (str[0][j] == str[1][j] && str[0][j] >= 'A' && str[0][j] <= 'G')
		{
			break;
		}
		j++;
	}
	cout<<day[str[0][j] - 'A']<<" ";
	j++;
	while(j < len1 && j < len2)
	{
		// 'A' to 'N' and digit
		if (str[0][j] == str[1][j] && ((str[0][j] >= 'A' && str[0][j] <= 'N') || 
			(str[0][j] >= '0' && str[0][j] <= '9')))
		{
			break;
		}
		j++;
	}
	if (str[0][j] >= '0' && str[0][j] <= '9')
	{
		printf("%02d:", str[0][j] - '0');
	}else
		printf("%d:", str[0][j] - 'A' + 10);
	len1 = str[2].length();
	len2 = str[3].length();
	j = 0;
	while(j < len1 && j < len2)
	{
		// first common english letter
		if (str[2][j] == str[3][j] && isalpha(str[2][j]))
		{
			break;
		}
		j++;
	}
	printf("%02d", j);
	return 0;
}