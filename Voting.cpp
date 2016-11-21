#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int n1, n2, n3, n4, n5;
	scanf("%i %i %i %i %i", &n1, &n2, &n3, &n4, &n5);
	map<int, int> mem;
	int sum = n1+n2+n3+n4+n5, tmp;
	for(int i = 0; i < sum; i++)
	{
		scanf("%i", &tmp);	
		if(mem.find(tmp) != mem.end())
			mem[tmp] += 1;
		else
			mem[tmp] = 1;
	}
	int count = 0;
	for(map<int, int>::iterator it = mem.begin(); it!= mem.end(); it++)
		if(it->second >= 3)
			count++;
	printf("%d\n", count);		
}
