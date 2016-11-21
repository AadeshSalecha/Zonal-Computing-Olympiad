#include <queue>
#include <iostream>
#include <algorithm>                 
#include <vector>                    
#include <cstring>   
#include <functional>                
using namespace std;                 
                                     
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;	
}
       	                                 
int main(void)                       
{                                    
	freopen("input.txt", "r", stdin);   
	freopen("output.txt", "w", stdout);	
	int n, c, start, end, k = 0; scanf("%d%d", &n, &c);
	vector < pair<int, int> > customer;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &start, &end);
		customer.push_back(make_pair(start, end));	
	}
	sort(customer.begin(), customer.end(), cmp);
	
	priority_queue<int, vector<int>, greater<int> > bill;
		
	while(bill.size() < c and k < n)
		{
			bill.push(customer[k].first + customer[k].second);
			k++;	
		}
		
	int time = bill.top();	
	while(k < n)
	{
		while(bill.size() < c)
		{
			bill.push(time + customer[k].second);
			k++;	
		}		
		if(k == n)break;
		time = bill.top();
		bill.pop();	
	}
	
	while(bill.size() > 1)
		bill.pop();	
		
	cout << bill.top() << endl;
}
