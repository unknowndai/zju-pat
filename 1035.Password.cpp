#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<pair<string, string> > passwords;
bool modify(string &psw)
{
	int len = psw.length();
	bool ret = false;
	for (int i = 0; i < len; ++i)
	{
		switch(psw[i])
		{
			case '1':
				psw[i] = '@';
				ret = true;
				break;
			case '0':
				psw[i] = '%';
				ret = true;
				break;
			case 'l':
				psw[i] = 'L';
				ret = true;
				break;
			case 'O':
				psw[i] = 'o';
				ret = true;
				break;
			default:
				break;
		}
	}
	return ret;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	string name, psw;
	for (int i = 0; i < num; ++i)
	{
		cin>>name>>psw;
		if (modify(psw))
		{
			passwords.push_back(pair<string, string>(name, psw));
		}
	}
	int sz = passwords.size();
	if (sz == 0)
	{
		if (num == 1)
		{
			cout<<"There is 1 account and no account is modified";
		}else
			cout<<"There are "<<num<<" accounts and no account is modified";
	}else
	{
		cout<<sz<<endl;
		for (int i = 0; i < sz; ++i)
		{
			cout<<passwords[i].first<<" "<<passwords[i].second<<endl;
		}
	}
	return 0;
}