#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct people
{
	int id, talent, virtue, tol, type;
	people(int id, int talent, int virtue, int tol, int type) : id(id),  \
		talent(talent), virtue(virtue), tol(tol), type(type){}
}people;
int lowLine, highLine, num;
vector<people> peo;
int cmp(people a, people b)
{
	if (a.type != b.type)
	{
		return a.type < b.type;
	}else if (a.tol != b.tol)
	{
		return a.tol > b.tol;
	}else if (a.virtue != b.virtue)
	{
		return a.virtue > b.virtue;
	}else
		return a.id < b.id;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>num>>lowLine>>highLine;
	int tmpid, tmptalent, tmpvirtue, tmptype;
	int nPeo = 0;
	for (int i = 0; i < num; ++i)
	{
		cin>>tmpid>>tmpvirtue>>tmptalent;
		if (tmpvirtue < lowLine || tmptalent < lowLine)
		{
			continue;
		}
		if (tmpvirtue >= highLine && tmptalent >= highLine)    // sagas
		{
			tmptype = 0;
		}else if (tmpvirtue >= highLine)                       // noblemen
		{
			tmptype = 1;
		}else if (tmpvirtue >= tmptalent)                      // fool men
		{
			tmptype = 2;
		}else
			tmptype = 3;                                      // small men
		peo.push_back(people(tmpid, tmptalent, tmpvirtue, tmptalent + tmpvirtue, tmptype));
		nPeo++;
	}
	cout<<nPeo<<endl;
	sort(peo.begin(), peo.end(), cmp);
	for (int i = 0; i < nPeo; ++i)
	{
		printf("%08d %d %d\n", peo[i].id, peo[i].virtue, peo[i].talent);
	}
	return 0;
}