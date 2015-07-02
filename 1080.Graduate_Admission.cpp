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
typedef struct applicant
{
	int id, ge, gi, tol, rank;
	int choice[5];
}applicant;
vector<applicant> applicants;
int numApplicants, numSchools, numChoices;
vector<int> qutoas, lastRank;        // lastRank means the lowest rank of schools
vector<vector<int> > admissions;
int cmp(applicant a, applicant b)
{
	if (a.tol != b.tol)
		return a.tol > b.tol;
	else
		return a.ge > b.ge;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>numApplicants>>numSchools>>numChoices;
	applicants.resize(numApplicants);
	qutoas.resize(numSchools);
	lastRank.resize(numSchools, -1);
	admissions.resize(numSchools);
	for (int i = 0; i < numSchools; ++i)
	{
		cin>>qutoas[i];
	}
	for (int i = 0; i < numApplicants; ++i)
	{
		cin>>applicants[i].ge>>applicants[i].gi;
		applicants[i].tol = applicants[i].ge + applicants[i].gi;  // calculate total score
		for (int j = 0; j < numChoices; ++j)
			cin>>applicants[i].choice[j];
		applicants[i].id = i;
	}
	// sort the applicants according to score
	sort(applicants.begin(), applicants.end(), cmp);
	// set the rank and admit applicants
	for (int i = 0; i < numApplicants; ++i)
	{
		if (i != 0 && applicants[i].tol == applicants[i - 1].tol 
			&& applicants[i].ge == applicants[i - 1].ge)
			applicants[i].rank = applicants[i - 1].rank;
		else
			applicants[i].rank = i + 1;
		for (int j = 0; j < numChoices; ++j)
		{
			// which school in choices
			int which = applicants[i].choice[j];
			if (qutoas[which])
			{
				qutoas[which]--;
				admissions[which].push_back(applicants[i].id);
				lastRank[which] = applicants[i].rank;
				break;
			}else if (applicants[i].rank == lastRank[which])
			{
				// same rank even if its quota will be exceeded
				admissions[which].push_back(applicants[i].id);
				break;
			}
		}
	}
	for (int i = 0; i < numSchools; ++i)
	{
		sort(admissions[i].begin(), admissions[i].end());
		for (int j = 0; j < admissions[i].size(); ++j)
		{
			if (j != 0)
				cout<<" ";
			cout<<admissions[i][j];
		}
		cout<<endl;
	}
	return 0;
}