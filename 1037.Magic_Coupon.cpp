#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	vector<int> coupons, products;
	int nc, np;
	cin>>nc;
	coupons.resize(nc);
	for (int i = 0; i < nc; ++i)
	{
		cin>>coupons[i];
	}
	cin>>np;
	products.resize(np);
	for (int i = 0; i < np; ++i)
	{
		cin>>products[i];
	}
	sort(coupons.begin(), coupons.end());
	sort(products.begin(), products.end());
	int index = 0;
	long long ret = 0;
	while(index < nc && index < np && coupons[index] < 0 && products[index] < 0)
		ret += coupons[index] * products[index++];
	int indexc = nc - 1, indexp = np - 1;
	while(indexc >= 0 && indexp >= 0 && coupons[indexc] > 0 && products[indexp] > 0)
		ret += coupons[indexc--] * products[indexp--];
	cout<<ret;
	return 0;
}