#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int N, K, tmp, tmp1;
	cin >> N >> K;
		                  	
	vector<int> a; vector<int> b; vector<int> b1; vector<int> a1;
	for(int i = 0; i < N; i++)
	{
		cin >> tmp; a.push_back(tmp); b1.push_back(tmp);	
	}
	for(int i = 0; i < N; i++)
	{
		cin >> tmp; b.push_back(tmp); a1.push_back(tmp);	
	}
	sort(a.begin(), a.end()); sort(b.begin(), b.end()); sort(a1.begin(), a1.end()); sort(b1.begin(), b1.end());
	
	// a and b
	for(int i = 0; i < K; i++)
	{
		vector<int>::iterator it = a.end(); it--;
		if(b[0] < *it)	
		{			
			iter_swap(b.begin(), it);
		}
		
		int curr = a.size()-1;
		while(a[curr] < a[curr-1] and curr != 0)
		{
			tmp = a[curr]; a[curr] = a[curr-1]; a[curr-1] = tmp;	
			curr--;
		}
		curr = 0;
		while(b[curr] > b[curr+1] and curr != b.size()-1)
		{
			tmp = b[curr]; b[curr] = b[curr+1]; b[curr+1] = tmp;		
			curr++;
		}			
	}
	
	// b and a
	for(int i = 0; i < K; i++)
	{
		vector<int>::iterator it = a1.end(); it--;
		if(b[0] < *it)	
		{			
			iter_swap(b1.begin(), it);
		}
		
		int curr = a1.size()-1;
		while(a1[curr] < a1[curr-1] and curr != 0)
		{
			tmp = a1[curr]; a1[curr] = a1[curr-1]; a1[curr-1] = tmp;	
			curr--;
		}
		curr = 0;
		while(b1[curr] > b1[curr+1] and curr != b1.size()-1)
		{
			tmp = b1[curr]; b1[curr] = b1[curr+1]; b1[curr+1] = tmp;		
			curr++;
		}			
	}
	cout << min(a.back()+b.back(), b1.back()+a1.back()) << endl;
}