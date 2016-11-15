#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
 
int v[2500+7];
int main(void)
{	
	int n;
	scanf("%i", &n);
	for(int i = 0; i < n; i++)
		scanf("%i", &v[i]);			
	sort(v, v+n);
    map<int, int> indx;
    for(int i = 0; i < n; i++)
        indx.insert(make_pair(v[i], i));
    
    if(n > 2)
    {
        int grid[n][n];
        memset(grid, 0, sizeof(grid));
       
        for(int i = n-2; i >= 0; i--)
            for(int j = n-1; j > n-(n-i); j--)
            {
               int d =v[j]-v[i];
               if(indx.find(v[i]-d) != indx.end())
               {                   
                   grid[indx[v[i]-d]][i] = max(3, grid[i][j]+1);    
               }
            }  
        
        int maximum = 2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] > maximum) {maximum = grid[i][j]; cout << "";}
            }
        } 
        cout << maximum << endl;
    }
    else
        cout << n << endl;
	
}  