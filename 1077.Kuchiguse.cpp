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
	vector<string> str(num);
	vector<int> len(num);       // the length of all strings
	getchar();                  // get the space
	for (int i = 0; i < num; ++i)
	{
		getline(cin, str[i]);
		len[i] = str[i].length();
	}
	string ret;
	int i = 0;
	while(1)
	{
		i++;
		char ch = str[0][len[0] - i];
		bool isSame = true;
		for (int j = 1; j < num; ++j)
		{
			if (i > len[j] || ch != str[j][len[j] - i])
			{
				isSame = false;
				break;
			}
		}
		if (isSame)
		{
			ret.insert(0, 1, ch);
		}else
			break;
	}
	if (ret.empty())
	{
		cout<<"nai";
	}else
		cout<<ret;
	return 0;
}