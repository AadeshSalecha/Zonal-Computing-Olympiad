#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	long long n1, n2, n3; int tmp;
	scanf("%lli %lli %lli", &n1, &n2, &n3);
	set<long long> books;
	for(int i = 0; i < n1; i++)
	{
		scanf("%i", &tmp);
		books.insert(tmp);	
	}
	for(int i = 0; i < n2; i++)
	{
		scanf("%i", &tmp);
		books.insert(tmp);	
	}
	for(int i = 0; i < n3; i++)
	{
		scanf("%i", &tmp);
		books.insert(tmp);	
	}
	printf("%d", books.size());
}
