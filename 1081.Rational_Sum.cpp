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
vector<pair<long long, long long> > numbers;   // numerator and denominator
// get the greatest common divisor
long long gcd(long long numerator, long long denominator)
{
	if (numerator == 0 || denominator == 0)
	{
		return numerator == 0 ? denominator : numerator;
	}
	return numerator > denominator ? gcd(numerator % denominator, denominator)
		: gcd(denominator % numerator, numerator);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	numbers.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>numbers[i].first;
		getchar();
		cin>>numbers[i].second;
	}
	long long denominator = 1;
	for (int i = 0; i < n; ++i)
	{
		if (denominator % numbers[i].second)
			denominator *= numbers[i].second;
	}
	long long numerator = 0;
	for (int i = 0; i < n; ++i)
	{
		numerator += denominator / numbers[i].second * numbers[i].first;
	}
	if (numerator == 0)
	{
		cout<<"0";
		return 0;
	}
	int sign = numerator < 0 ? -1 : 1;     // maybe negtive number
	numerator *= sign; 
	long long integer = numerator / denominator;   // the integer part of result
	numerator %= denominator;
	long long tmp = gcd(numerator, denominator);
	numerator /= tmp;
	denominator /= tmp;
	if (integer > 0)
		cout<<sign * integer;
	if (numerator)
	{
		if (integer > 0)
		{
			cout<<" ";
		}
		cout<<numerator<<'/'<<denominator;
	}
	return 0;
}