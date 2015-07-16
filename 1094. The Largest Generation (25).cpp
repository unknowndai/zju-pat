#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
    int numPeo, numParent;
	cin>>numPeo>>numParent;
	vector<vector<int> > child(numPeo + 1);
	// build the pedigree tree
	for (int i = 0; i < numParent; ++i)
	{
		int parent, numChild, c;
		cin>>parent>>numChild;
		for (int j = 0; j < numChild; ++j)
		{
			cin>>c;
			child[parent].push_back(c);
		}
	}
	queue<int> gen;
	gen.push(1);
	int maxLevel = 1, maxPeople = 1, curLevel = 1;
	while(!gen.empty())
	{
		// the number of current generation people
		int num = gen.size();
		if (num > maxPeople)
		{
			maxPeople = num;
			maxLevel = curLevel;
		}
		while(num--)
		{
			int pp = gen.front();
			gen.pop();
			for (int i = 0; i < child[pp].size(); i++)
				gen.push(child[pp][i]);
		}
		curLevel++;
	}
	cout<<maxPeople<<' '<<maxLevel;
	return 0;
}