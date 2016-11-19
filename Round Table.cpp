#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
long long cost(vector<long long> &a)
{
	long long dp[a.size()][2];
	// Scenario a
	dp[0][0] = 0; dp[0][1] = a[0];
	dp[1][0] = dp[0][1]; dp[1][1] = a[1];
	for(int i = 2; i < a.size(); i++)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][1] = a[i] + min(dp[i-1][0], dp[i-1][1]);
	}
	
	// cout << dp[a.size()-1][0] << " " << dp[a.size()-1][1] << endl;
	return min(dp[a.size()-1][0], dp[a.size()-1][1]);
}
 
int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long n, tmp;
	cin >> n;
	vector<long long> a;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp; a.push_back(tmp);	
	}
	vector<long long> b(a.begin()+1, a.end());
	vector<long long> c(a.begin(), a.end()-1);
	cout << min(a[0]+cost(b), cost(c)+a.back()) << endl;
}