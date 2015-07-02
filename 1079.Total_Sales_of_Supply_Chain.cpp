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
// using double instead of float
typedef struct member
{
	int nNodes;              // retailer if it is 0
	vector<int> subNodes;    // retailers or distributors from this supplier
	double price;
	double amount;            // the total amount of retailer
}member;
vector<member> members;
int num;
double originalPrice, increment;
void calculatePrice(int cur, double curprice)     
{
	if (members[cur].nNodes == 0)
	{
		return;
	}
	double tmp = curprice * (1 + increment * 0.01);
	for (int i = 0; i < members[cur].nNodes; ++i)
	{
		members[members[cur].subNodes[i]].price = tmp;
		calculatePrice(members[cur].subNodes[i], tmp);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>num>>originalPrice>>increment;
	members.resize(num);
	int n;
	for (int i = 0; i < num; ++i)
	{
		cin>>n;
		members[i].nNodes = n;
		if (n)      // distributors
		{
			members[i].subNodes.resize(n);
			for (int j = 0; j < n; ++j)
			{
				cin>>members[i].subNodes[j];
			}
		}else       // retailer
		{
			cin>>members[i].amount;
		}
		
	}
	members[0].price = originalPrice;
	calculatePrice(0, originalPrice);
	double tol = 0.0;
	for (int i = 0; i < num; ++i)
	{
		if (members[i].nNodes == 0)
		{
			tol += members[i].price * members[i].amount;
		}
	}
	printf("%.1lf", tol);
	return 0;
}