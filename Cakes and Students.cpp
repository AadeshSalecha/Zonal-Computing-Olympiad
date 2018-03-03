#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;
struct Interval{
	int e, s;
};

#define MAX_STUDENTS 100007
Interval all_intervals[MAX_STUDENTS];

bool comparator(Interval a, Interval b);
bool interval_intersection(Interval a, Interval b);
void arr_intersections(Interval arr[]);
void input();
void copy(Interval* a, Interval* b);
bool try_array(Interval* all_intervals, Interval tmp, int index);
void debug();

int cakes, students, k, arr_indx, arr_intsec;
Interval tmp;
char output[20];
int main()
{
	input();	
	arr_intersections(all_intervals);

	int num_intsec = arr_intsec, gindex = arr_indx;
	if(k == 0 && num_intsec > 0)
		cout << "Bad\n";
	else if(num_intsec == 0)
		cout << "Good\n";
	else if(k == 1 && num_intsec > 2)
		cout << "Bad\n";
    else if(num_intsec == 1)
    {	
    	// tmp = indx
    	if(try_array(all_intervals, tmp, gindex))
			cout << "Good\n";

    	// tmp = indx + 1
    	else if(try_array(all_intervals, tmp, gindex + 1))
			cout << "Good\n";

		else
			cout << "Bad\n";
    }
    else if(num_intsec == 2)
    {
    	// tmp = indx
    	if(try_array(all_intervals, tmp, gindex))
			cout << "Good\n";

    	// tmp = indx + 1
    	else if(try_array(all_intervals, tmp, gindex + 1))
			cout << "Good\n";

		// tmp = indx - 1
    	else if(try_array(all_intervals, tmp, gindex - 1))
			cout << "Good\n";

		else
			cout << "Bad\n";
    }
}

bool comparator(Interval a, Interval b)
{
	return a.s < b.s;
}

bool interval_intersection(Interval a, Interval b)
{
	return a.e >= b.s;
}


void arr_intersections(Interval arr[])
{
	arr_indx = -1; arr_intsec = 0;
	sort(all_intervals, all_intervals + students, comparator);

	for(int i = 0; i < students - 1; i++)
	{
		if(interval_intersection(all_intervals[i], all_intervals[i+1]))
		{
			arr_intsec++;
			arr_indx = i;
		}
	}
}

void input()
{
	cin >> cakes >> students >> k;

	for(int i = 0; i < students; i++)
	{
		cin >> tmp.s >> tmp.e;
		all_intervals[i] = tmp;
	}
}

void copy(Interval* a, Interval* b)
{
	(*a).s = (*b).s;
	(*a).e = (*b).e;
}

bool try_array(Interval* all_intervals, Interval tmp, int index)
{
	// take out index
	copy(&tmp, &all_intervals[arr_indx]);	
	int wanted = all_intervals[index].e - all_intervals[index].s + 1;
	copy(&all_intervals[index], &all_intervals[students-1]);
	copy(&all_intervals[students-1], &tmp);
	students--;	
	// sort
	sort(all_intervals, all_intervals + students, comparator);
	// check for intersections
	arr_intersections(all_intervals);
	if(arr_intsec > 0) 
	{
		students++;
		sort(all_intervals, all_intervals + students, comparator);
		return false;
	}

	// if none try inserting 
	int available = max(all_intervals[0].s - 1, cakes - all_intervals[students-1].e);	
    for(int i = 0; i < students-1 && available < wanted ; i++)
    	available = max(available, all_intervals[i+1].s - all_intervals[i].e - 1);
    students++;
	sort(all_intervals, all_intervals + students, comparator);    
    return (available >= wanted);
}

void debug()
{
	cout << "\n";
	for(int i= 0; i < students; i++)
		cout << all_intervals[i].s << " " << all_intervals[i].e << "\n";
	cout << "\n";
}
