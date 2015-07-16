#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int cnt, data[100], ret[100], tmp[100];
// compare the resulting array and temporary array
bool isSame()
{
	return !memcmp(ret, tmp, cnt * sizeof(int));
}
// print temporary array
void print()
{
	for (int i = 0; i < cnt; ++i)
	{
		if (i != 0)
			printf(" ");
		printf("%d", tmp[i]);
	}
}
bool isInsertion()
{
	bool res = false;
	int i = 1;
	while(i < cnt)
	{
		sort(tmp, tmp + i + 1);
		if (res && !isSame())          // next round
		{
			cout<<"Insertion Sort"<<endl;
			print();
			return true;
		}
		i++;
		if (isSame())
			res = true;
	}
	return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>cnt;
	for (int i = 0; i < cnt; ++i)
		cin>>data[i];
	for (int i = 0; i < cnt; ++i)
		cin>>ret[i];
	memcpy(tmp, data, cnt * sizeof(int));
	if (isInsertion())     // insertion sort and return
	{
		return 0;
	}
	memcpy(tmp, ret, cnt * sizeof(int));
	cout<<"Heap Sort"<<endl;
	int end = cnt - 1;
	// find unsorted region
	while(end >= 0 && ret[end] >= ret[0])
	{
		end--;
	}
	swap(tmp[0], tmp[end]);
	make_heap(tmp, tmp + end);
	print();
	return 0;
}