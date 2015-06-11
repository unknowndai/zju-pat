#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct student
{
	string name;
	int numCourse;
	vector<int> courses;
}student;
vector<student> stu;
int cmp(student a, student b)
{
	return strcmp(a.name.c_str(), b.name.c_str()) < 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nStu, nCourse;
	cin>>nStu>>nCourse;
	stu.resize(nStu);
	for (int i = 0; i < nStu; ++i)
	{
		cin>>stu[i].name>>stu[i].numCourse;
		stu[i].courses.resize(stu[i].numCourse);
		for (int j = 0; j < stu[i].numCourse; ++j)
		{
			cin>>stu[i].courses[j];
		}
	}
	sort(stu.begin(), stu.end(), cmp);
	vector<vector<string> > courseList(nCourse + 1);
	for (int i = 0; i < nStu; ++i)
	{
		for (int j = 0; j < stu[i].numCourse; j++)
			courseList[stu[i].courses[j]].push_back(stu[i].name);
	}
	// using c-style output to save time...
	for (int i = 1; i <= nCourse; ++i)
	{
		int sz = courseList[i].size();
		printf("%d %d\n", i, sz);
		for (int j = 0; j < sz; j++)
			printf("%s\n", courseList[i][j].c_str());
	}
	return 0;
}