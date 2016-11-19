#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
#include <list>
#include <stack>
using namespace std;

struct Point
    {
    int x, y;
    bool visited;
};

bool sortx(Point a, Point b)
    {
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool sorty(Point a, Point b)
    {
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

const int MAXX = 100000, MAXY = 500;
int main(void)
{    
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, max_area = 0; Point tmp; vector<Point> v;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        Point tmp; tmp.x = a; tmp.y = b; tmp.visited = false;
        v.push_back(tmp);
    }        
    Point last_point; tmp.x = 0; tmp.y = MAXY; last_point.x = MAXX; last_point.y = 0;
    v.push_back(last_point);
    sort(v.begin(), v.end(), sortx);     
    
    // check all vertical lines
    for(int i = 0; i < v.size(); i++)
    {        
        int cur_area = (v[i].x - tmp.x) * MAXY;
        max_area = max(max_area, cur_area);        
        tmp = v[i];     
		// cout << cur_area << " " << tmp.x << " " << tmp.y << endl;
    }    
    
    v.pop_back(); // remove last point
    for(int i = 0; i < v.size(); i++)
        {
        if(v[i].x == v[i+1].x)
            {
            int count = 1;
            while(v[i].x == v[i+count].x)
                {
                v[i+count].visited = true;
                count++;
            }
            i += (count);
        }
    }
    sort(v.begin(), v.end(), sorty);
    // right now, all unnecessary points have been removed
    
    for(int i = 0; i < v.size(); i++)
        {
            if(!v[i].visited)
            {
				Point max_l, max_r; max_l.x = 0; max_l.y = 0; max_r.x = MAXX; max_r.y = 0;
				for(int j = 0; j < i; j++)
				{
					if(v[j].x < v[i].x and v[j].x > max_l.x and v[j].y < v[i].y and v[i].x != v[j].x)
						max_l = v[j];
					if(v[j].x > v[i].x and v[j].x < max_r.x and v[j].y < v[i].y and v[i].x != v[j].x)
						max_r = v[j];
				}
				
    			// x is right.x - left.x    			
    			int cur_area = (max_r.x - max_l.x) * v[i].y;
				max_area = max(max_area, cur_area);   
				
				//cout << "POINT " << v[i].x << " " << v[i].y << " LEFT: " << max_l.x << " "<< max_l.y << " "<< " RIGHT: " << max_r.x << " " << max_r.y << " AREA: " << cur_area << endl;         
            }            
        }
    cout << max_area << endl;    
}
