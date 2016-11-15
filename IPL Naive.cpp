#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>

using namespace std;

long long ipl(vector<long long> v, int index, int cons, map< pair<long long, int> , long long> &memo)
{
	if(index >= v.size()) return 0;	
	if(memo.find(make_pair(index, cons)) != memo.end()) return memo[make_pair(index, cons)];
	if(index == v.size()-1 and (cons == 0 or cons == 1))
		return v[index];
	else if(index == v.size()-1 and cons == 2)
		return 0;
		
	long long tmp;
	if(cons == 2)
	{
		tmp = ipl(v, index+1, 0, memo);	
		memo[make_pair(index, cons)] = tmp;
		return tmp;
	}
	tmp = max(v[index]+ipl(v,index+1,cons+1, memo), ipl(v, index+1, 0, memo));
	memo[make_pair(index, cons)] = tmp;
	return tmp;
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long tmp, n; cin >> n;
	vector<long long> v;
	map< pair<long long, int> , long long> memo;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp; v.push_back(tmp);
	}
	cout << ipl(v, 0, 0, memo) << endl;
}
