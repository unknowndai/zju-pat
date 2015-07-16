#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
using namespace std;
struct data
{
	int val;
	int next;
}list[100000];        // linked list
bool isFirst[10001];  // absolute value no more then 10000
// print the linked list
void printList(int head)
{
	while(head != -1)
	{
		printf("%05d %d ", head, list[head].val);
		if (list[head].next == -1)
		{
			printf("-1\n");
		}else
			printf("%05d\n", list[head].next);
		head = list[head].next;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	//init
	memset(isFirst, 0, 10001 * sizeof(bool));
	int firstAddress, num;
	cin>>firstAddress>>num;
	int addr, val, next;
	for (int i = 0; i < num; ++i)       // input the linked list
	{
		cin>>addr>>val>>next;
		list[addr].val = val;
		list[addr].next = next;
	}
	int list1 = firstAddress;       // the head of resulting linked list
	int preNode1 = firstAddress;        // for linking the list
	bool hasDuplication = false;    
	int list2, preNode2;                // the head of removed linked list
	isFirst[abs(list[firstAddress].val)] = true;
	int curNode = firstAddress;
	int nextNode = list[firstAddress].next;
	list[curNode].next = -1;
	while(nextNode != -1)
	{
		int tmp = abs(list[nextNode].val);
		// resulting linked list
		if (!isFirst[tmp])
		{
			isFirst[tmp] = true;
			list[preNode1].next = nextNode;
			preNode1 = nextNode;
		}else  
		{   // the head of removed linked list
			if (!hasDuplication)
			{
				hasDuplication = true;
				list2 = nextNode;
				preNode2 = nextNode;
			}else
			{
				list[preNode2].next = nextNode;
				preNode2 = nextNode;
			}
		}
		curNode = nextNode;
		nextNode = list[nextNode].next;
		list[curNode].next = -1;         // end the list
	}
	// output the resluting linked list
	printList(list1);
	// output the removed linked list
	if (hasDuplication)
	{
		printList(list2);	
	}
	return 0;
}