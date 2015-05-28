#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct student
{
	int id;
	char name[9];
	int grade;
	student(int oneid, char *onename, int onegrade) : id(oneid), grade(onegrade)
	{
		strcpy(name, onename);
	}
}student;
vector<student> stu;
vector<student> stuPerGrade[101];
int cmpid(student a, student b)
{
	return a.id < b.id;
}
int cmpname(student a, student b)
{
	if (strcmp(a.name, b.name) == 0)
	{
		return a.id < b.id;
	}else
		return strcmp(a.name, b.name) < 0;
}
int cmpgrade(student a, student b)
{
	if (a.grade != b.grade)
	{
		return a.grade < b.grade;
	}else
		return a.id < b.id;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num, column;
	cin>>num>>column;
	int oneid, onegrade;
	char onename[9];
	for (int i = 0; i < num; ++i)
	{
		// do not use cin or cout in this program   "case 6"
		scanf("%d%s%d", &oneid, onename, &onegrade);
		stu.push_back(student(oneid, onename, onegrade));
	}
	if (column == 1)
		sort(stu.begin(), stu.end(), cmpid);
	else if (column == 2)
		sort(stu.begin(), stu.end(), cmpname);
	else
		sort(stu.begin(), stu.end(), cmpgrade);
	for (int i = 0; i < num; ++i)
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}