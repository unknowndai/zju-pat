#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct student
{
	char id[16];
	int inTime;
	int outTime;
	student(char str[], int in, int out) : inTime(in), outTime(out)
	{
		strcpy(id, str);
	}
}student;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	vector<student> stu;
	int num;
	cin>>num;
	int inID = 0, outID = 0;
	char str[16];
	int h, m, s, in, out;
	for (int i = 0; i < num; ++i)
	{
		scanf("%s", str);
		scanf("%d:%d:%d", &h, &m, &s);
		in = h * 3600 + m * 60 + s;
		scanf("%d:%d:%d", &h, &m, &s);
		out = h * 3600 + m * 60 + s;
		stu.push_back(student(str, in, out));
		if (i == 0)
		{
			continue;
		}else
		{
			if (in < stu[inID].inTime)
			{
				inID = i;
			}
			if (out > stu[outID].outTime)
			{
				outID = i;
			}
		}
	}
	printf("%s %s", stu[inID].id, stu[outID].id);
	return 0;
}