#include <iostream>
#include <algorithm>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
int t, mm, dd, yy; char date[8];
bool isLeap() {
	if(yy%4 == 0) {
		if(yy % 100 != 0 || yy % 400 == 0) return true;
		else return false;
	} else return false;
}
int mday[13] = {31,28,31,30,31,30,31,31,30,31,30,31,31}, start[12] = {21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};
string zodiac[13] = {"capricorn","aquarius","pisces","aries","taurus","gemini","cancer","leo","virgo","libra","scorpio","sagittarius","capricorn"};
int main()
{
    cin >> t; cin.ignore();
    FOR0(day, t)
    {
        int days = 280;
        FOR0(i,8) {date[i] = getchar();} cin.ignore();
        mm = (date[0] - '0')*10 + (date[1] - '0'); dd = (date[2] - '0')*10 + (date[3] - '0'); yy = (date[4] - '0')*1000 + (date[5] - '0')*100+(date[6] - '0')*10 + (date[7] - '0');
        mday[1] = isLeap() ? 29 : 28; 
        while(days>=mday[mm-1]) {
            days -= mday[mm-1];
            mm++;
            if(dd > mday[mm-1]) {dd -= mday[mm-1]; mm++;} if(mm==13) {mm=1;yy++; mday[1] = isLeap() ? 29 : 28;}
        }
        dd += days; if(dd > mday[mm-1]) {dd -= mday[mm-1]; mm++;} if(mm==13) {mm=1;yy++;} 
        printf("%d %02d/%02d/%04d ", day+1, mm, dd, yy);
        if(dd < start[mm-1]) cout << zodiac[mm-1]; else cout << zodiac[mm]; cout << endl;
    }
}