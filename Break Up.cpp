#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
using namespace std;
 
int main(void)
{
    int tmp, n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp; v.push_back(tmp);
    }
    
    // dp wat all palindrome
    int dp[n][n]; memset(dp, 0, sizeof(dp));
    
    for(int i = n-1; i >= 0; i--)
    {    
        for(int j = n-1; j >= n-(n-i); j--)
        {                    
            if(j - i == 0) dp[i][j] = 1;
            else if(j - i == 1) dp[i][j] = (v[i] == v[j])?1:0;
            else if(v[i] == v[j] and dp[i+1][j-1]) dp[i][j] = 1;   
        }        
    }
    
    
    // check for min cut
    int mini[n]; memset(mini, 0, sizeof(mini));
    for(int i = 0; i < n; i++)
    {
        if(dp[0][i]) mini[i] = 0;      
        else
        {
            int minimum = INT_MAX;
            for(int j = 0; j < i+1; j++)
            {                    
                if(dp[j][i])
                    minimum = min(minimum, mini[j-1]+1);
            }            
            mini[i] = minimum;
        }
    }    
    cout << mini[n-1]+1 << endl;
}