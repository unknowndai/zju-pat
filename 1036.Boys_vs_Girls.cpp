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
	string boyName, boyID, girlName, girlID;
	int boyGrade = 101, girlGrade = -1, num;
	cin>>num;
	string tmpName, tmpID;
	int tmpGrade;
	char gender;
	for (int i = 0; i < num; ++i)
	{
		cin>>tmpName>>gender>>tmpID>>tmpGrade;
		if (gender == 'M' && tmpGrade < boyGrade)
		{
			boyName = tmpName;
			boyID = tmpID;
			boyGrade = tmpGrade;
			continue;
		}
		if (gender == 'F' && tmpGrade > girlGrade)
		{
			girlGrade = tmpGrade;
			girlID = tmpID;
			girlName = tmpName;
		}
	}
	if (girlName.length() == 0)
	{
		cout<<"Absent"<<endl;
	}else
		cout<<girlName<<' '<<girlID<<endl;
	if (boyName.length() == 0)
	{
		cout<<"Absent"<<endl;
	}else
		cout<<boyName<<' '<<boyID<<endl;
	if (girlName.length() == 0 || boyName.length() == 0)
	{
		cout<<"NA";
	}else
		cout<<girlGrade - boyGrade;
	return 0;
}