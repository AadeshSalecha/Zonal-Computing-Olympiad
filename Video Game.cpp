#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int main(void)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long n, h, tmp; cin >> n >> h;
	vector<long long> boxes;
	for(long long i = 0; i < n; i++)
	{
		cin >> tmp; boxes.push_back(tmp);
	}
	long long curr = 0; bool picked = false;
	while(cin >> tmp)
	{
		if(tmp == 0)break;
		if(tmp == 1 && curr != 0)
			curr--;
		if(tmp == 2 && curr != boxes.size()-1)
			curr++;
		if(tmp == 3 && picked == false && boxes[curr])
		{
			boxes[curr]--;
			picked = true;
		}
		if(tmp == 4 && picked == true && boxes[curr] < h)
		{
			picked = false;
			boxes[curr]++;
		}
	}
	for(long long i = 0; i < boxes.size(); i++)
		cout << boxes[i] << " ";
	cout << endl;
}
