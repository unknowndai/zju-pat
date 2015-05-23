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
	int score[4];
	int rank[4];
}student;
vector<student> stu;
char indexToItem[] = {'A', 'C', 'M', 'E'};
int cmp0(student a, student b)
{
	return a.score[0] > b.score[0];
}
int cmp1(student a, student b)
{
	return a.score[1] > b.score[1];
}
int cmp2(student a, student b)
{
	return a.score[2] > b.score[2];
}
int cmp3(student a, student b)
{
	return a.score[3] > b.score[3];
}
int cmpid(student a, student b)
{
	return a.id < b.id;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nStudent, nQuery;
	cin>>nStudent>>nQuery;
	stu.resize(nStudent);
	for (int i = 0; i < nStudent; ++i)
	{
		cin>>stu[i].id>>stu[i].score[1]>>stu[i].score[2]>>stu[i].score[3];
		stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
	}
	sort(stu.begin(), stu.end(), cmp0);
	for (int i = 0; i < nStudent; ++i)
	{
		if (i != 0 && stu[i].score[0] == stu[i - 1].score[0])
		{
			stu[i].rank[0] = stu[i - 1].rank[0];
		}else
			stu[i].rank[0] = i + 1;
	}
	sort(stu.begin(), stu.end(), cmp1);
	for (int i = 0; i < nStudent; ++i)
	{
		if (i != 0 && stu[i].score[1] == stu[i - 1].score[1])
		{
			stu[i].rank[1] = stu[i - 1].rank[1];
		}else
			stu[i].rank[1] = i + 1;
	}
	sort(stu.begin(), stu.end(), cmp2);
	for (int i = 0; i < nStudent; ++i)
	{
		if (i != 0 && stu[i].score[2] == stu[i - 1].score[2])
		{
			stu[i].rank[2] = stu[i - 1].rank[2];
		}else
			stu[i].rank[2] = i + 1;
	}
	sort(stu.begin(), stu.end(), cmp3);
	for (int i = 0; i < nStudent; ++i)
	{
		if (i != 0 && stu[i].score[3] == stu[i - 1].score[3])
		{
			stu[i].rank[3] = stu[i - 1].rank[3];
		}else
			stu[i].rank[3] = i + 1;
	}
	int tmpID;
	for (int i = 0; i < nQuery; ++i)
	{
		cin>>tmpID;
		int j = 0;
		// no Time Limit Exceeded, no need to use Binary Search
		for (; j < nStudent; ++j)
		{
			if (stu[j].id == tmpID)
			{
				int bestRank = 0;
				for (int k = 1; k < 4; ++k)
				{
					if (stu[j].rank[k] < stu[j].rank[bestRank])
					{
						bestRank = k;
					}
				}
				cout<<stu[j].rank[bestRank]<<' '<<indexToItem[bestRank]<<endl;
				break;
			}
		}
		if (j == nStudent)
		{
			cout<<"N/A"<<endl;
		}
	}
	return 0;
}