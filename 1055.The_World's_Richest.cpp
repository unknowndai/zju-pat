#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct people
{
	char name[10];
	int age;
	int net;
}people;
int nPeople, nQuery;
vector<people> peo;
int cmp(people a, people b)
{
	if (a.net != b.net)
	{
		return a.net > b.net;
	}else if (a.age != b.age)
	{
		return a.age < b.age;
	}else
		return strcmp(a.name, b.name) < 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>nPeople>>nQuery;
	peo.resize(nPeople);
	for (int i = 0; i < nPeople; ++i)
	{
		scanf("%s%d%d", peo[i].name, &peo[i].age, &peo[i].net);
	}
	int cnt = 1;
	sort(peo.begin(), peo.end(), cmp);
	int minAge, maxAge, tol;
	while (cnt <= nQuery)
	{
		printf("Case #%d:\n", cnt);
		scanf("%d%d%d", &tol, &minAge, &maxAge);
		int tmp = 0;
		for (int i = 0; i < nPeople; ++i)
		{
			if (peo[i].age >= minAge && peo[i].age <= maxAge)
			{
				printf("%s %d %d\n", peo[i].name, peo[i].age, peo[i].net);
				tmp++;
				if (tmp >= tol)
				{
					break;
				}
			}
		}
		if (tmp == 0)
		{
			printf("None\n");
		}
		cnt++;
	}
	return 0;
}