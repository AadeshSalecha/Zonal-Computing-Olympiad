#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
#include <list>
using namespace std;

int in[2007];
int main(void)
{    
    int n, tmp; scanf("%i", &n);
    vector<int> v;
    for(int i = 0; i < n; i++)
        scanf("%i", &in[i]);
    
    // calculate zigma i..j
    int grid[n][n]; memset(grid, 0, sizeof(grid));              
    for(int i = n-1; i >=0; i--)
        for(int j = n-1; j >= n-(n-i); j--)
        {
            if(i == j)grid[i][j] = in[i];
            else grid[i][j] = in[i] + grid[i+1][j];
        }
              
    // calculate dp
    int dp[n][n][2]; memset(dp, 0, sizeof(dp));
    for(int i = n-1; i >= 0; i--)
        for(int j =  n-(n-i); j < n; j++)
        {
            if(i == j) dp[i][j][0] = dp[i][j][1] = in[i];
            else if(j-i == 1){dp[i][j][0] = min(in[i], in[j]); dp[i][j][1] = max(in[i], in[j]);}            
            else
                {
                if(i == 0 and j == n-1) cout << in[i]+dp[i+1][j][0] << " " << dp[i][j-1][0] << endl;
                dp[i][j][1] = max(in[i]+dp[i+1][j][0], in[j] + dp[i][j-1][0]);
                dp[i][j][0] = grid[i][j] - dp[i][j][1];
            }
        }   
    
    for(int i = 0; i < n; i++)
    {    
        for(int j = 0; j < n; j++)
             cout << dp[i][j][1] << "," << dp[i][j][0] << "  ";
        cout << endl;
    }
    printf("%i", dp[0][n-1][1]);
}