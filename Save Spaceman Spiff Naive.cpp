#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Blaster
{
	int start, f, x, y;	
};

Blaster blast[2500];
int grid[2500][2500], n, m, k, a, b, tmp;

bool cmp(Blaster a, Blaster b)
{
	return a.start <= b.start;	
}

inline bool safe(int xc, int yc, int time)
{
	for(int i = 0; i < k and blast[i].start <= time; i++)
		if(blast[i].start <= time)
		{
//			cout << xc << " " << yc << " " << x[i] << " " << y[i] << endl;
			if(yc == blast[i].y)
			{
				// left blaster
				if(((time-abs(blast[i].x-xc))-blast[i].start)%blast[i].f == 0)
					return false;	

				// right blaster
				if(((time-abs(xc-blast[i].x))-blast[i].start)%blast[i].f == 0)
					return false;
			}
			if(xc == blast[i].x)	
			{
				// down blaster
				if(((time-abs(yc-blast[i].y))-blast[i].start)%blast[i].f == 0)
						return false;
				
				// up blaster
				if(((time-abs(blast[i].y-yc))-blast[i].start)%blast[i].f == 0)
						return false;		
			}
		}		
	return true;
}

int choose(int a, int b)
{
	if(a == -9 and b == -9)return -9;
	if(a == -9 and b != -9)return b;
	if(a != -9 and b == -9)return a;
	return min(a,b);	
}

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> a >> b >> blast[i].start >> blast[i].f;
		blast[i].x = a-1; blast[i].y = b-1;
	}
	sort(blast, blast+k, cmp);

	grid[0][0] = (safe(0,0,0) == true)?0:-9;
	// top row
	for(int i = 1; i < m; i++) 
	{
		if(grid[0][i-1] != -9)
		{
			if(safe(0,i,grid[0][i-1]+1))
				grid[0][i] = grid[0][i-1]+1;
			else
				grid[0][i] = -9;
		}
		else
			grid[0][i] = -9;
	}
	
	for(int i = 1; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			grid[i][j] = -9;
			if(j == 0)
			{
				if(grid[i-1][j] != -9 and safe(i,j, grid[i-1][j]+1) == true)
					grid[i][j] = grid[i-1][j]+1;
			}
			else
			{
				if(grid[i][j-1]	!= -9 and grid[i-1][j] != -9)
				{
					a = (safe(i,j,grid[i][j-1]+1) == true)?grid[i][j-1]+1:-9;
					b = (safe(i,j,grid[i-1][j]+1) == true)?grid[i][j-1]+1:-9;
					grid[i][j] = choose(a,b);
				}
				else if(grid[i][j-1] != -9)
					grid[i][j] = (safe(i,j, grid[i][j-1]+1) == true)?grid[i][j-1]+1:-9;
				else if(grid[i-1][j] != -9)
					grid[i][j] = (safe(i,j, grid[i-1][j]+1) == true)?grid[i-1][j]+1:-9;
			}	
		}
	
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}*/
	if(grid[n-1][m-1] == -1024)
		cout << "NO\n";
	else
		cout << "YES\n" << 	grid[n-1][n-1] << endl;
}
