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
	int a, b, c, a1, b1, c1;
	scanf("%d.%d.%d%d.%d.%d", &a, &b, &c, &a1, &b1, &c1);
	int a2, b2, c2;
	int carry = 0;
	c2 = (c + c1) % 29;
	carry = (c + c1) / 29;
	b2 = (b + b1 + carry) % 17;
	carry = (b + b1 + carry) / 17;
	a2 = (a + a1 + carry);
	printf("%d.%d.%d", a2, b2, c2);
	return 0;
}