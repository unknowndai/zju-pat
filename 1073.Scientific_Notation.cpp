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
	string str;
	cin>>str;
	string ret;
	int idx = 1;
	while(str[idx] != 'E') idx++;       // E position   
	ret = str.substr(1, idx - 1);
	int exponent;
	sscanf(&str[idx + 2], "%d", &exponent);
	if (str[idx + 1] == '+')
	{
		int len = ret.length() - 2;
		if (len > exponent)
		{
			ret.insert(2 + exponent, 1, '.');
		}else
		{
			ret.append(exponent - len, '0');
		}
		ret.erase(1, 1);            // erase '.'
	}else
	{
		ret.erase(1, 1);
		ret.insert(0, exponent - 1, '0');
		ret.insert(0, "0.");
	}
	if (str[0] == '-')             // negtive number
	{
		cout<<"-";
	}
	cout<<ret;
	return 0;
}