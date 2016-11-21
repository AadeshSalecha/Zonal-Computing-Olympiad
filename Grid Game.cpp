#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int n; scanf("%d", &n);
	int grid[n][n], top[n][n], bottom[n][n]; 
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
	
	// top - down
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(i == 0 and j == 0) top[i][j] = grid[i][j];	
			else if(i == 0)
				top[i][j] = grid[i][j] + top[i][j-1];
			else if(j == 0)
				top[i][j] = grid[i][j] + top[i-1][j];
			else
				top[i][j] = grid[i][j] + max(top[i][j-1] , top[i-1][j]);	
		}	
	
	// bottom - up
	for(int i = n-1; i > -1; i--)
		for(int j = n-1; j > -1; j--)
		{
			if(i == n-1 and j == n-1) bottom[i][j] = grid[i][j];	
			else if(i == n-1)
				bottom[i][j] = grid[i][j] + bottom[i][j+1];
			else if(j == n-1)
				bottom[i][j] = grid[i][j] + bottom[i+1][j];
			else
				bottom[i][j] = grid[i][j] + max(bottom[i][j+1] , bottom[i+1][j]);
		}
			
	// max with left and up
	int maximum = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(i == 0 and j == 0) maximum = max(maximum, top[i][j]);
			else if(i == 0)
				maximum = max(maximum, top[i][j] + bottom[i][j-1]);
			else if(j == 0)
				maximum = max(maximum, top[i][j] + bottom[i-1][j]);
			else
				maximum = max(maximum, top[i][j]+max(bottom[i][j-1], bottom[i-1][j]));
		}
			
	printf("%d\n", maximum);
}
