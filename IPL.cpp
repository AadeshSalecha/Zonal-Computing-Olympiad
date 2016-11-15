#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>

using namespace std;

const int MAX = 200000 + 10;
int cons0[MAX], cons1[MAX], ipl[MAX];

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long tmp, n; cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> ipl[i];
	
	cons0[n] = ipl[n]; cons1[n] = ipl[n];
	cons0[n-1] = ipl[n-1] + cons1[n]; cons1[n-1] = max(ipl[n], ipl[n-1]);
	cons0[n-2] = max(ipl[n-2]+cons1[n-1], cons0[n-1]);
	cons1[n-2] = max(ipl[n-2]+cons0[n], cons0[n-1]);
	
	for(int i = n-3; i >= 0; i--)
	{
		cons0[i] = max(cons0[i+1], ipl[i]+cons1[i+1]);
		cons1[i] = max(cons0[i+1], ipl[i]+cons0[i+2]);
	}	
	cout << max(cons0[0], cons1[0]) << endl;
}
