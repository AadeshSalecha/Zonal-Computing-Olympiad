#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, m, row, col, str, a, b;
    cin >> n >> m;
    int grid[n][n];
    bool safe[n][n];
	for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
         {
         	cin >> grid[i][j];
         	safe[i][j] = false;
         }
     
	for(int i = 0; i < m; i++)
	{
		cin >> row >> col >> str;
		for(int j = row-1-str; j < row+str; j++)
			for(int k = col-1-str; k < col+str; k++)
			{
				if((j >= 0 and j < n) and (k >= 0 and k < n))
					if(abs(row-1-j) + abs(col-1-k) <= str)
						safe[j][k] = true;
			}
	}
	
	int new_grid[n][n];
	for(int i = n-1; i >= 0; i--)
		for(int j = n-1; j >= 0; j--)
		{
			if(i == n-1 and j == n-1)
			{
				new_grid[i][j] = grid[i][j];
				continue;
			}
			
			new_grid[i][j] = -123456;
			if(!safe[i][j])continue;

			
			if(i == n-1) // bottom row
			{
				if(safe[i][j+1])
					new_grid[i][j] = grid[i][j] + new_grid[i][j+1];
			}
			else if(j == n-1)
			{
				if(safe[i+1][j]) // bottom safe
				{
					new_grid[i][j] = grid[i][j] + new_grid[i+1][j];
				}
			}
			else
			{
				if(safe[i][j+1] and safe[i+1][j]) // both safe
				{
					new_grid[i][j] = grid[i][j] + max(new_grid[i][j+1], new_grid[i+1][j]);
				}
				else if(safe[i+1][j]) // one safe
				{
					new_grid[i][j] = grid[i][j] + new_grid[i+1][j];
				}
				else if(safe[i][j+1]) // other safe
				{
					new_grid[i][j] = grid[i][j] + new_grid[i][j+1];
				}
			}

		}
		
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//			cout << new_grid[i][j] << " ";
//		cout << endl;
//	}
	
	if(new_grid[0][0] > -100000)
 	 cout << "YES\n" << new_grid[0][0] << endl;
    else
	 	cout << "NO\n";
}
