#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

bool cmp(long long a, long long b)
{
	return a > b;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long  n, tmp;
	scanf("%lli", &n);
	vector<long long> a;
	for(long long  i = 0; i < n; i++)
	{
		scanf("%lli", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end(), cmp);
	long long sum = 0;
	for(int i = 0,f = n - 1; i < n; i++, f--)
	{
		sum += a[i] * (f-i);
	}
	printf("%lli\n", sum);
}
