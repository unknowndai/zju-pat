#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef map<string, vector<string> >::iterator AUTO;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	map<string, vector<string> > mLib[5];
	int nBook;
	cin>>nBook;
	string id, title, author, keyWord, publisher, year;
	for (int i = 0; i < nBook; ++i)
	{
		cin>>id;
		getchar();               // get the last line '\n'
		getline(cin, title);     
		getline(cin, author);
		getline(cin, keyWord);
		getline(cin, publisher);
		getline(cin, year);
		// build map
		mLib[0][title].push_back(id);
		mLib[1][author].push_back(id);
		istringstream istr(keyWord);
		while (!istr.eof())
		{
			string word;
			istr>>word;
			mLib[2][word].push_back(id);
		}
		mLib[3][publisher].push_back(id);
		mLib[4][year].push_back(id);
	}
	// sort the map
	for (int i = 0; i < 5; ++i)
	{
		for (AUTO iter = mLib[i].begin(); iter != mLib[i].end(); iter++)
			sort(iter->second.begin(), iter->second.end());
	}
	int nQuery;
	cin>>nQuery;
	getchar();
	for (int i = 0; i < nQuery; ++i)
	{
		string query;
		getline(cin, query);
		cout<<query<<endl;
		int index = query[0] - '1';
		query = query.substr(3);
		AUTO iter = mLib[index].find(query);
		if (iter == mLib[index].end())
			cout<<"Not Found"<<endl;
		else
		{
			int sz = mLib[index][query].size();
			for (int j = 0; j < sz; ++j)
			{
				cout<<mLib[index][query][j]<<endl;
			}
		}
	}
	return 0;
}