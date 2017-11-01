#include <iostream>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
using namespace std;
int days, dd, mm, yy, mday[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};
bool isLeap()
{
    if (yy % 4 == 0)
    {
	if (yy % 100 != 0 || yy % 400 == 0)
	    return true;
	else
	    return false;
    }
    else
	return false;
}
int main()
{
    //ios::sync_with_stdio(false);
    cin >> days >> dd >> mm >> yy;
    int years, leap;
    while (dd > 0)
    {
		bool before = (mm < 3) ? true : false;
		if(before) {
			while(days > 365) {
				days -= isLeap() ? 366 : 365;
				yy++;
			}
		}
		else {
			while(days > 365) {
				yy++;
				days -= isLeap() ? 366 : 365;
			}	
		} 
	mday[1] = isLeap() ? 29 : 28;
	while (days >= mday[mm - 1])
	{
	    days -= mday[mm - 1];
	    mm++;
	    if (dd > mday[mm - 1])
	    {
		dd -= mday[mm - 1];
		mm++;
	    }
	    if (mm == 13)
	    {
		mm = 1;
		yy++;
		mday[1] = isLeap() ? 29 : 28;
	    }
	}
	dd += days;
	while (dd > mday[mm - 1])
	{
	    dd -= mday[mm - 1];
	    mm++;
	    if (mm == 13)
	    {
		mm = 1;
		yy++;
	    }
	}
	printf("%d %d %d\n", dd, mm, yy);
	cin >> days >> dd >> mm >> yy;
    }
}
/*
	years = days / 366;
	leap = years / 4 + (yy % 4 == 0 ? 1 : 0) - (years/100 + (yy % 100 == 0 ? 1 : 0)) + (years / 400 + (yy % 400 == 0 ? 1 : 0));
	if(mm>2) leap-= ;
	days -= years*365 + leap;
	yy += years;
	if(mm == 2 && dd == 29 && !isLeap()) {mm=3; dd=1;}
*/