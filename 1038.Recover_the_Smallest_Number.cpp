#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// decide the string order through the combination of two strings
int cmp(string a, string b)
{
	string ab = a + b;
	string ba = b + a;
	return strcmp(ab.c_str(), ba.c_str()) < 0; 
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	vector<string> segments(num);
	for (int i = 0; i < num; ++i)
	{
		cin>>segments[i];
	}
	sort(segments.begin(), segments.end(), cmp);
	string ret;
	for (int i = 0; i < num; ++i)
	{
		ret += segments[i];
	}
	int len = ret.length(), i = 0;
	// erase the leading 0s
	while(i < len && ret[i] == '0')
		ret.erase(0, 1);
	if (ret.length() == 0)
	{
		cout<<"0";
		return 0;
	}
	cout<<ret;
	return 0;
}