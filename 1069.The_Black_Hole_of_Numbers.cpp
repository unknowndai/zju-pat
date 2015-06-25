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
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	int inc, dec;
	//while(num && num != 6174)      case 5: input is 6174
	do
	{
		char str[5];
		sprintf(str, "%04d", num);
		sort(str, str + 4);
		sscanf(str, "%d", &inc);     // non-decreasing
		reverse(str, str + 4);
		sscanf(str, "%d", &dec);     // non-increasing
		num = dec - inc;
		printf("%04d - %04d = %04d\n", dec, inc, num);
	}while(num && num != 6174);
	return 0;
}