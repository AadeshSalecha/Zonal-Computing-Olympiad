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

int main(void)
{    
    int n, b, lower, upper, tmp;
    scanf("%i %i %i %i", &n, &b, &lower, &upper);
    set<int> choices; choices.insert(b);
    for(int i = 0; i < n; i++)
    {
       scanf("%i", &tmp);
       set<int> change;
       for(set<int>::iterator i = choices.begin(); i != choices.end(); i++)
       {
           if(*i + tmp >= lower and *i + tmp <= upper)
               change.insert(*i+tmp);
           if(*i - tmp >= lower and *i - tmp <= upper)
               change.insert(*i-tmp);                       
       }
       choices = change;
       // printf("%i ", (int)choices.size());      
    }
    int maximum = 0;
    for(set<int>::iterator i = choices.begin(); i != choices.end(); i++)        
            maximum = max(maximum, *i);
    printf("%i\n", maximum);
}