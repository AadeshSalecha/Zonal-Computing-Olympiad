#include <iostream>                  
#include <algorithm>                 
#include <vector>                    
#include <cstring>    
#include <utility>
#include <numeric>               
using namespace std;                 

const int MAX = 20000;
int arr[MAX];
               
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;	
}
			                         
int main(void)                       
{                                    
	freopen("input.txt", "r", stdin);   
	freopen("output.txt", "w", stdout);	
	int n, m, temp, dist, belt; scanf("%d%d", &n, &m);
	vector < pair<int, int> > monkeys;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &dist, &belt);
		monkeys.push_back(make_pair(dist, belt));	
	}
	sort(monkeys.begin(), monkeys.end(), cmp);
	
	for(int i = 1; i <= n; i++)
		arr[i-1] = i;
		
	for(int i = 0; i < m; i++)
	{
		temp = arr[monkeys[i].second-1];
		arr[monkeys[i].second-1] = arr[monkeys[i].second];	
		arr[monkeys[i].second] = temp;
	}		

	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
