#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	return a.first < b.first;	
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	long long n, x, y, s, e, tmp;
	cin >> n >> x >> y;	
	vector<pair<long long, long long> > contest(n); vector<long long> start(x);vector<long long> back(y);
	
	for(long long i = 0; i < n; i++)
		cin >> contest[i].first >> contest[i].second;

	for(long long i = 0; i < x; i++)
		cin >> start[i];

	for(long long i = 0; i < y; i++)
		cin >> back[i];

	sort(start.begin(), start.end());
	sort(back.begin(), back.end());
	sort(contest.begin(), contest.end(), cmp);
	
	long long ans = INT_MAX,i ,j;
	for(long long z = 0; z < n; z++)
	{
		i = (int)distance(start.begin(), upper_bound(start.begin(), start.end(), contest[z].first))-1;				
		if(contest[z].second > back.back()+1 or i < 0) continue;
		j = (int)distance(back.begin(), lower_bound(back.begin(), back.end(), contest[z].second));
		ans = min(ans, back[j] - start[i] + 1);	
	}
	cout << ans << endl;
}
