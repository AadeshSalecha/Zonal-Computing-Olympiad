#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	
	int n, k, minimum; cin >> n >> k; k--;
	int grid[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> grid[i][j];
			
	
	// solve special to end
	for(int i = n-1; i >= k;  i--)
	{
		for(int j = n-1; j >= 0; j--)
		{
			if(i == n-1 and j == n-1) continue;
			if(i == n-1) grid[j][i] += grid[j+1][i];
			else if(j == n-1) grid[j][i] += grid[j][i+1];
			else grid[j][i] += min(grid[j][i+1], grid[j+1][i]);
		}	
	}

	// solve special row
	for(int row = n-1; row >= 0; row--)
	{
		if(row == n-1)
			minimum = grid[row][k];
		else
			minimum = min(grid[row][k], grid[row+1][k-1]);
			
		// iterate throught all rows of special
		for(int i = 0; i < n; i++)
			minimum = min(minimum, grid[i][k] + abs(row-i));			
			
		grid[row][k-1] += minimum;
	}
	// finished special row
	
	// solve 0 to special-1
	for(int i = n-1; i >= 0; i--)
		for(int j = k-2; j >= 0; j--)
		{
			if(i == n-1) grid[i][j] += grid[i][j+1];	
			else
				grid[i][j] += min(grid[i][j+1], grid[i+1][j]);
		}		
		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}	
	
	cout << grid[0][0] << endl;
}
