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
void lowercase(string &str)
{
	int len = str.length();
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	string str;
	getline(cin, str);
	lowercase(str);
	str.append(1, '$');              // add flag indicated the end of string
	map<string, int> mWord2Cnt;
	int len = str.length();
	int start = 0, maxCnt = 0;
	string ans = "z";
	for (int i = 0; i < len; ++i)
	{
		if (isalnum(str[i]))
		{
			continue;
		}else
		{
			if (i > start)
			{
				string word = str.substr(start, i - start);   // get the word
				auto iter = mWord2Cnt.find(word);
				if (iter != mWord2Cnt.end())
				{
					mWord2Cnt[word]++;
					if (mWord2Cnt[word] > maxCnt || (mWord2Cnt[word] == maxCnt && 
						word.compare(ans) < 0))
					{
						ans = word;
						maxCnt = mWord2Cnt[word];
					}
				}else
				{
					mWord2Cnt[word] = 1;
					if (1 > maxCnt || (1 == maxCnt && word.compare(ans) < 0))
					{
						maxCnt = 1;
						ans = word;
					}
				}
			}
			start = i + 1;          
		}
	}
	cout<<ans<<" "<<maxCnt;
	return 0;
}