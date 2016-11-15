#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
using namespace std;
 
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.second < b.second;    
}
 
bool intersect(long long a1, long long b1, long long c)
{
    return (c <= b1 and c >= a1);
}
 
int main(void)
{
    // read input
    long long n, a, b, tmpa, tmpb; cin >> n; vector< pair<long long, long long> > v; vector<bool> visited(n, 0); vector<long long> seen; bool result;
    for(long long i = 0; i < n; i++){cin >> a >> b; v.push_back(make_pair(a,b));}
    
    // sort by first value
    sort(v.begin(), v.end(), cmp);
    
    // take the minimum and remove all intersecting
    long long count = 0;
    for(long long i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            result = true;
            visited[i] = true;        
            for(int j = 0; j < seen.size(); j++)
                if(intersect(v[i].first, v[i].second, seen[j]))
                {                    
                    result = false;
                    break;
                }
           if(result)
               seen.push_back(v[i].second);
        }
    }
 
    cout << seen.size() << endl;
}  