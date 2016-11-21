#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = (int)10e4+7;
int grid[MAX];

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);	
	int n; cin >> n;
	int z[n][2];
	for(int i = 1; i <= n; i++)
		cin >> grid[i];
	z[n][0] = 0; z[n][1] = grid[n];
	for(int i = n-1; i >= 1; i--)
	{
		z[i][0] = max(z[i+1][0], z[i+1][1]);
		z[i][1] = grid[i] + z[i+1][0];	
	}
//	cout << z[1][1] << " " << z[1][0] << endl;
	cout << max(z[1][1], z[1][0]) << endl;
}
