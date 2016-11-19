#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long  n, tmp; cin >> n;
	vector<long long > a;
	for(long long  i = 0; i < n; i++)
	{
		cin >> tmp; a.push_back(tmp);
	}
	long long  depth = 0, cur_start = 0, max_depth = 0, d_start = 0, num_char = 0, cur_char = 0, c_start = 1;
	for(long long  i = 0; i < n; i++)
	{
		if(a[i] == 1)
			depth++;
		if(a[i] == 2)
			depth--;
		cur_char++;
		if(depth > max_depth)
		{
			d_start = i+1;
			max_depth = depth;
		}
		if(cur_char > num_char)
		{
			num_char = cur_char;
			c_start = cur_start;
		}
		if(depth == 0)
		{
			cur_char = 0; cur_start = i+1;
		}		
	}
	cout << max_depth << " " << d_start << " " << num_char << " " << c_start+1 << endl;
	return 0;
}
