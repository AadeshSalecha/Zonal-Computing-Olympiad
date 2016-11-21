#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long n, tmp, k, r = 0;
	cin >> n >> k;
	vector<long long> a; 
	for(int i = 0; i < n;i++)
	{
		cin >> tmp; a.push_back(tmp);
	}
	
	sort(a.begin(), a.end());
	
	for(int i = 0; i < a.size(); i++)
	{
		int j = upper_bound(a.begin()+i, a.end(), a[i]+k-1) - a.begin();
		//	cout << j << " " << (n-j) << endl;
		if(j < n and j >= 0 and j != i)
			r += (n-j);
	}
	cout << r << endl;
}