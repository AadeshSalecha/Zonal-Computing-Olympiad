#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stack>
using namespace std;
 
int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, tmp, max_depth = 0; 
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp; a.push_back(tmp);
	}
	
	stack<int> alt; stack<int> depth;	
	for(int i = 0; i < n; i++)
	{
		// if alt is empty just push
		if(alt.empty() and (a[i] == 1 or a[i] == 3))
		{
			alt.push(a[i]);			
			depth.push(1);
		}
		// if 1 and last was 3 put to alt
		else if((a[i] == 1 and alt.top() == 3) or (a[i] == 3 and alt.top() == 1))
		{
			alt.push(a[i]);
			depth.push(depth.top()+1);
		}
		// else put to waste
		else if(a[i] == 1 or a[i] == 3)
		{
			alt.push(a[i]);	
			depth.push(depth.top());
		}
			
		max_depth = max(max_depth, depth.top());
		if(a[i] == 2 or a[i] == 4)
		{
			depth.pop(); alt.pop();
		}
	}
	cout << max_depth << " ";
	
	int p_char = 0, sq_char = 0, max_sq_char = 0, max_p_char = 0, p_depth = 0, sq_depth = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 1)
			p_depth++;
		if(a[i] == 3)
			sq_depth++;
			
		if(p_depth)
			p_char++;
		if(sq_depth)
			sq_char++;
		
		max_sq_char = max(max_sq_char, sq_char);
		max_p_char = max(max_p_char, p_char);	
		
		if(a[i] == 2)
			p_depth--;
		if(a[i] == 4)
			sq_depth--;
			
		if(p_depth == 0) p_char = 0;
		if(sq_depth == 0) sq_char = 0;
	}
	cout << max_p_char << " " << max_sq_char << endl;
}	
 