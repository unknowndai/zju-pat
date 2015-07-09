#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
// get greatest common divisor
long long gcd(long long numerator, long long denominator)
{
	if (numerator == 0) return denominator;
	if (denominator == 0) return numerator;
	return numerator > denominator ? gcd(numerator % denominator, denominator) : \
		 gcd(numerator, denominator % numerator);
}
// print the rational number
void print(long long numerator, long long denominator)
{
	if (numerator == 0)
	{
		cout<<'0';
		return;
	}
	if (denominator == 0)
	{
		cout<<"Inf";
		return;
	}
	bool flag = false;       // is it negtive?
	if (numerator < 0)
	{
		flag = !flag;
		numerator *= -1;
	}
	if (denominator < 0)
	{
		flag = !flag;
		denominator *= -1;
	}
	int integer = numerator / denominator;      // the integer part
	numerator %= denominator;
	long long g = gcd(numerator, denominator);  // the fraction part
	numerator /= g;
	denominator /= g;
	if (flag)
	{
		cout<<"(-";
	}
	if (integer > 0)
	{
		cout<<integer;
		if (numerator != 0)
			cout<<' ';
	}
	if (numerator != 0)
	{
		cout<<numerator<<'/'<<denominator;
	}
	if (flag)
	{
		cout<<")";
	}
}
// maybe overflow with int
void operate(long long a, long long b, long long c, long long d, char op)
{
	print(a, b);
	cout<<' '<<op<<' ';
	print(c, d);
	cout<<" = ";
	switch(op)
	{
		case '+':
			print(a * d + c * b, b * d);
			break;
		case '-':
			print(a * d - c * b, b * d);
			break;
		case '*':
			print(a * c, b * d);
			break;
		case '/':
			print(a * d, b * c);
			break;
	}
	cout<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/jianwen/Documents/project/pat/data.txt", "r", stdin);
	#endif
	int a, b, c, d;
	scanf("%d/%d %d/%d", &a, &b, &c, &d);
	operate(a, b, c, d, '+');
	operate(a, b, c, d, '-');
	operate(a, b, c, d, '*');
	operate(a, b, c, d, '/');
	return 0;
}