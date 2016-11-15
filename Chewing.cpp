#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long n, k, tmp; cin >> n >> k;	
	vector<long long > a;
	for(long long  i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	long long  pairs = 0;
	for(long long  i = 0; i < n; i++)
	{
		if(a[i] >= k) break;
		long long  j = upper_bound(a.begin()+i, a.end(), k-a[i]-1) - a.begin();
		if(j < n and j > 0 and j != i) 
		{
			pairs += (j-i-1);
//			cout << k-a[i] << " " << (j-i-1) << " " << j << endl;
		}
	}
	cout << pairs << endl;
}
