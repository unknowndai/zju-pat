#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
typedef struct user
{
	int id;
	int score[6];
	int tolScore;              // total scores
	int perfect;			   // the number of perfectly solved problems
	bool pass;                 // true if pass at least one problem
	user():id(0), tolScore(0), perfect(0), pass(0){
		for (int i = 0; i < 6; ++i)
		{
			score[i] = -2;     // -2 means no submittion
		}
	}
}user;
int nProblem, nUser, nSubmittion;
vector<user> users;
int scorePerPro[6];           // score per problem
int cmp(user a, user b)
{
	if (a.tolScore != b.tolScore)
	{
		return a.tolScore > b.tolScore;
	}else if (a.perfect != b.perfect)
		return a.perfect > b.perfect;
	else if (a.pass != b.pass)
		return a.pass > b.pass;
	else
		return a.id < b.id;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>nUser>>nProblem>>nSubmittion;
	users.resize(nUser + 1, user());
	for (int i = 1; i <= nProblem; ++i)
	{
		cin>>scorePerPro[i];
	}
	int tmpID, tmpProblem, tmpScore;
	for (int i = 0; i < nSubmittion; ++i)
	{
		scanf("%d%d%d", &tmpID, &tmpProblem, &tmpScore);
		users[tmpID].id = tmpID;
		users[tmpID].pass |= tmpScore >= 0;
		tmpScore = tmpScore == -1 ? 0 : tmpScore;
		// choose the highest score
		tmpScore = tmpScore > users[tmpID].score[tmpProblem] ? tmpScore : users[tmpID].score[tmpProblem];
		users[tmpID].score[tmpProblem] = tmpScore;
	}
	for (int i = 1; i <= nUser; ++i)
	{
		for (int j = 1; j <= nProblem; ++j)
		{
			if (users[i].score[j] > 0)
				users[i].tolScore += users[i].score[j];
			if (users[i].score[j] == scorePerPro[j])
				users[i].perfect++;
		}
	}
	sort(users.begin(), users.end(), cmp);
	int curRank = 1, i = 0;
	while(i <= nUser && users[i].pass)
	{
		// change the rank
		if (i != 0 && users[i].tolScore != users[i - 1].tolScore)
		{
			curRank = i + 1;
		}
		// output
		printf("%d %05d %d", curRank, users[i].id, users[i].tolScore);
		for (int j = 1; j <= nProblem; j++)
		{
			if (users[i].score[j] == -2)
			{
				printf(" -");
			}else
				printf(" %d", users[i].score[j]);
		}
		cout<<endl;
		i++;
	}
	return 0;
}