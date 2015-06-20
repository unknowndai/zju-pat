#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int sig;
	string str[2];
	cin>>sig>>str[0]>>str[1];
	int exp[2];
	for (int i = 0; i < 2; ++i)
	{
		int tmp = str[i].find('.');
		exp[i] = tmp == -1 ? str[i].length() : tmp;
		if (tmp != -1)
		{
			str[i].erase(tmp, 1);     // erase the '.'
		}
		str[i].insert(0, "0.");
		while(str[i].length() > 2 && str[i][2] == '0') // erase the leading '0' eg: 0.0001
		{
			str[i].erase(2, 1);
			exp[i]--;
		}
		if (str[i].length() == 2)         // the last case   eg: 0.0000
		{
			exp[i] = 0;
		}
		if (str[i].length() > sig + 2)    // get the given significant digits
		{
			str[i] = str[i].substr(0, sig + 2);
		}else
			str[i].append(sig + 2 - str[i].length(), '0');
	}
	if (exp[0] == exp[1] && str[0].compare(str[1]) == 0)
	{
		printf("YES %s*10^%d", str[0].c_str(), exp[0]);
	}else
		printf("NO %s*10^%d %s*10^%d", str[0].c_str(), exp[0], str[1].c_str(), exp[1]);
	return 0;
}