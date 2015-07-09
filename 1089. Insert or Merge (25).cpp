#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXNUM 100              // maximum number
int num;
// original data, partial result, temporary result
int data[MAXNUM], ret[MAXNUM], tmp[MAXNUM];
bool isMerge;
// compare the temporary result and partial result
bool cmp()
{
	for (int i = 0; i < num; ++i)
	{
		if (ret[i] != tmp[i])
		{
			return false;
		}
	}
	return true;
}
// print the next iteration result
void print()
{
	for (int i = 0; i < num; ++i)
	{
		if (i != 0)
			printf(" ");
		printf("%d", tmp[i]);
	}	
}
// merge two sublist
void merge(int i, int mid, int j)
{
	int sz = j - i + 1;
	int *aux = new int[sz];
	int left = i, right = mid + 1;
	for (int k = 0; k < sz; ++k)
	{
		if (left <= mid && right <= j)
		{
			if (tmp[left] < tmp[right])
			{
				aux[k] = tmp[left++];
			}else
				aux[k] = tmp[right++];
		}else if (left <= mid)
		{
			aux[k] = tmp[left++];
		}else
			aux[k] = tmp[right++];
	}
	memcpy(tmp + i, aux, sz * sizeof(int));
}
void mergeSort(int i, int j)
{
	int factor = 2;
	while(factor <= num)
	{
		for (int i = 0; i < num; i += factor)
		{
			int j = i + factor - 1;
			if (j > num - 1)
			{
				j = num - 1;
			}
			//int mid = (i + j) / 2;         this is wrong when last sublist if using merge function
			int mid = i + factor / 2 - 1;
			//sort(tmp + i, tmp + j + 1);    it is a lazy way    
			merge(i, mid, j);
		}
		factor *= 2;
		if (isMerge && cmp())        // for getting next iteration
		{
			continue;
		}
		if (isMerge)
		{
			printf("%s\n", "Merge Sort");
			print();
			return;
		}
		if (cmp())
		{
			isMerge = true;
		}
	}
	
}
void swap(int i, int j)
{
	int temp = tmp[i];
	tmp[i] = tmp[j];
	tmp[j] = temp;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	cin>>num;
	for (int i = 0; i < num; ++i)
	{
		cin>>data[i];
	}
	for (int i = 0; i < num; ++i)
	{
		cin>>ret[i];
	}
	// insert sort
	memcpy(tmp, data, num * sizeof(int));
	bool isInsert = false, isNext = false;
	for (int i = 1; i < num; ++i)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (tmp[j] > tmp[j+1])
			{
				swap(j+1, j);
			}
		}
		if (isInsert && !cmp())          // for getting next iteration
		{
			break;
		}
		if (cmp())
		{
			isInsert = true;
		}
	}
	if (isInsert)                        // print and return
	{
		printf("%s\n", "Insertion Sort");
		print();
		return 0;
	}
	// must be merge sort
	memcpy(tmp, data, num * sizeof(int));
	isMerge = false;
	mergeSort(0, num - 1);
	return 0;
}	