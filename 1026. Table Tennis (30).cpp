#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
typedef struct player
{
	int comeTime;        // arriving time
	int playTime;        
	int serveTime;       
	player(int ct, int pt) : comeTime(ct), playTime(pt), serveTime(0){}
}player;
int ordinaryNum, vipNum, tableNum;
vector<player> ordinaryPlayer;
vector<player> vipPlayer;
#define MAXTABLE 101
#define EIGHTCLOCK 28800       // eight clock in second
#define NIGHTCLOCK 75600
int table[MAXTABLE];
int serveNum[MAXTABLE];
bool isVIPTable[MAXTABLE];
int cmp(player a, player b)
{
	return a.comeTime < b.comeTime;
}
int chooseFirst()
{
	// choose one empty table
	int emptyTable = 1, minTime = table[1];
	for (int k = 2; k <= tableNum; ++k)
	{
		if (table[k] < minTime)
		{
			emptyTable = k;
			minTime = table[k];
		}
	}
	return emptyTable;
}
int chooseVIP()
{
	// choose one empty table
	int emptyTable = -1, minTime = NIGHTCLOCK;
	for (int k = 1; k <= tableNum; ++k)
	{
		if (isVIPTable[k] && table[k] < minTime)
		{
			emptyTable = k;
			minTime = table[k];
		}
	}
	return emptyTable;
}
void print(player p)
{
	int ch = p.comeTime / 3600;
	int cm = (p.comeTime % 3600) / 60;
	int cs = p.comeTime % 60;
	int sh = p.serveTime / 3600;
	int sm = (p.serveTime % 3600) / 60;
	int ss = p.serveTime % 60;
	int wt = (p.serveTime - p.comeTime + 30) / 60;   // add 30s to round up
	printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",ch, cm, cs, sh, sm, ss, wt);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int num;
	cin>>num;
	int h, m, s, p, t;
	for (int i = 0; i < num; ++i)
	{
		scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &t);
		p = p > 120 ? 120 : p;      // case 4   :  over two hours
		player onePlayer(h * 3600 + m * 60 + s, p);
		t == 0 ? ordinaryPlayer.push_back(onePlayer) : vipPlayer.push_back(onePlayer);
	}
	ordinaryNum = ordinaryPlayer.size();
	vipNum = vipPlayer.size();
	cin>>tableNum;
	for (int i = 1; i <= tableNum; ++i)
	{
		table[i] = EIGHTCLOCK;
		isVIPTable[i] = 0;
		serveNum[i] = 0;
	}
	int vipTableNum;
	cin>>vipTableNum;
	for (int i = 0, v = 0; i < vipTableNum; ++i)
	{
		cin>>v;
		isVIPTable[v] = 1;
	}
	sort(ordinaryPlayer.begin(), ordinaryPlayer.end(), cmp);
	sort(vipPlayer.begin(), vipPlayer.end(), cmp);
	for (int i = 0, j = 0; i + j < num;)
	{
		int index;
		if (j >= vipNum || (i < ordinaryNum && ordinaryPlayer[i].comeTime < vipPlayer[j].comeTime))
		{

			index = chooseFirst();
			// vip has priority
			if (isVIPTable[index] && j < vipNum && vipPlayer[j].comeTime <= table[index])
			{
			}else
			{
				//serveNum[index]++;
				if (table[index] < ordinaryPlayer[i].comeTime)
				{
					ordinaryPlayer[i].serveTime = ordinaryPlayer[i].comeTime;
					table[index] = ordinaryPlayer[i].comeTime;
				}else
					ordinaryPlayer[i].serveTime = table[index];
				
				if (ordinaryPlayer[i].serveTime + ordinaryPlayer[i].playTime > NIGHTCLOCK)
				{
					i++;
					continue;
				}
				table[index] += ordinaryPlayer[i].playTime * 60;
				serveNum[index]++;
				print(ordinaryPlayer[i]);
				i++;
				continue;
			}
		}
		index = chooseVIP();
		// the vip table is occupied and choose ordinary table
		if (index == -1 || table[index] > vipPlayer[j].comeTime)
		{
			index = chooseFirst();
		}
		//serveNum[index]++;
		if (table[index] < vipPlayer[j].comeTime)
		{
			vipPlayer[j].serveTime = vipPlayer[j].comeTime;
			table[index] = vipPlayer[j].comeTime;
		}else
			vipPlayer[j].serveTime = table[index];
		if (vipPlayer[j].serveTime + vipPlayer[j].playTime > NIGHTCLOCK)
		{
			j++;
			continue;
		}
		serveNum[index]++;
		table[index] += vipPlayer[j].playTime * 60;
		print(vipPlayer[j]);
		j++;	
	}
	for (int i = 1; i <= tableNum; ++i)
	{
		if (i != 1)
		{
			cout<<" ";
		}
		cout<<serveNum[i];
	}
	return 0;
}