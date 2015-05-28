#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct testee
{
	string number;
	int score;
	int location;
	int finalRank;
	int localRank;
	testee(string str, int oneScore, int local) : number(str), score(oneScore), location(local){}
}testee;
vector<testee> testees;
int localNum, testeeNum;
int cmp(testee a, testee b)
{
	if (a.score != b.score)
	{
		return a.score > b.score;
	}else
		return strcmp(a.number.c_str(), b.number.c_str()) < 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>localNum;
	int tmpNum, oneScore;
	testeeNum = 0;
	string str;
	for (int i = 0; i < localNum; ++i)
	{
		cin>>tmpNum;
		testeeNum += tmpNum;
		for (int j = 0; j < tmpNum; ++j)
		{
			cin>>str>>oneScore;
			testees.push_back(testee(str, oneScore, i));
		}
	}
	sort(testees.begin(), testees.end(), cmp);
	cout<<testeeNum<<endl;
	vector<int> lastnumber(localNum, -1);   // last testee in location
	vector<int> localNumber(localNum, 0);   // the number of testees in location
	for (int i = 0; i < testeeNum; ++i)
	{
		cout<<testees[i].number;
		// final rank
		if (i == 0 || testees[i].score != testees[i - 1].score)
		{
			testees[i].finalRank = i + 1;
		}else
			testees[i].finalRank = testees[i - 1].finalRank;
		cout<<" "<<testees[i].finalRank<<" "<<testees[i].location + 1;
		// local rank
		if (lastnumber[testees[i].location] == -1 || 
			testees[i].score != testees[lastnumber[testees[i].location]].score)
		{
			testees[i].localRank = localNumber[testees[i].location] + 1;
		}else
		{
			testees[i].localRank = testees[lastnumber[testees[i].location]].localRank;
		}
		localNumber[testees[i].location]++;
		lastnumber[testees[i].location] = i;
		cout<<" "<<testees[i].localRank<<endl;
	}
	return 0;
}