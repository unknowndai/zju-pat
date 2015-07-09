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
vector<pair<string, string> > students(101);    // hash table
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	string name, id;
	int grade;
	for (int i = 0; i < num; ++i)
	{
		cin>>name>>id>>grade;
		students[grade].first = name;
		students[grade].second = id;
	}
	int low, high;
	cin>>low>>high;
	bool found = false;           // have students been found?
	for (int i = high; i >= low; --i)
	{
		if (!students[i].first.empty())
		{
			found = true;
			cout<<students[i].first<<' '<<students[i].second<<endl;
		}
	}
	if (!found)
	{
		cout<<"NONE";
	}
	return 0;
}