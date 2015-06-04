#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define MAXSTU 175760    // 26 * 26 * 26 * 10
#define getIndex ((name[0] - 'A') * pown[0] + (name[1] - 'A') * pown[1] + \ 
				(name[2] - 'A') * pown[2] + (name[3] - '0'))
vector<vector<int> > stu(MAXSTU);
int pown[4] = {6760, 260, 10};
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int nQuery, nCourse;
	cin>>nQuery>>nCourse;
	int courseNum, nstu;
	char name[5];            // do not use string
	for (int i = 0; i < nCourse; ++i)
	{
		scanf("%d%d", &courseNum, &nstu);
		for (int j = 0; j < nstu; ++j)
		{
			scanf("%s", name);
			stu[getIndex].push_back(courseNum);
		}
	}
	int index, sz;
	for (int i = 0; i < nQuery; ++i)
	{
		scanf("%s", name);
		index = getIndex;
		sz = stu[index].size();
		printf("%s %d", name, sz);
		sort(stu[index].begin(), stu[index].end());
		for (int j = 0; j < sz; ++j)
		{
			printf(" %d", stu[index][j]);
		}
		printf("\n");	
	}
	return 0;
}