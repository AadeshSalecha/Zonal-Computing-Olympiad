#include <algorithm>
#include <vector>
#include <iostream>
#define vi vector<int> 
using namespace std;

int main(void)
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);    
    long long n, tmp; cin >> n;
    vi a;
    for(long long i = 0; i < n;i++)
    {
      cin >> tmp; a.push_back(tmp);        
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long maximum = 0;
    for(long long i = 0; i < n; i++)
    {
       maximum = max(maximum, a[i] * (i+1));
    }
    cout << maximum << endl;
    return 0;
}
