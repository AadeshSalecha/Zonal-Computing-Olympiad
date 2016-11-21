#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
using namespace std;

int a[2007], b[2007];
int main(void)
{    
    int n, m, tmp;
    cin >> m >> n;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int dp[n][m]; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = 90;//INT_MAX;
        
    dp[n-1][m-1] = abs(a[n-1]-b[m-1]); cout << b[m-1] << endl;
    for(int i = n-1; i >= 0; i--)
        for(int j =  m-(n-i); j >= i; j--)
        {        
            if(i == n-1 and j == m-1) continue;
            if(i == n-1) dp[i][j] = min(dp[i][j+1], abs(a[i]-b[j]));
            else dp[i][j] = min(abs(a[i]-b[j])+dp[i+1][j+1], dp[i][j+1]);
        }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%i ", dp[i][j]);
        printf("\n");
    }
}