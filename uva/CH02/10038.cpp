#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int main()
{
	//ios::sync_with_stdio(false);
	int x, y, diff, n;
	while(cin >> n)
	{
		bool jolly = true;
		cin >> x;
		bool b[3000] = {};
		FOR(i,1,n)
		{
			cin >> y;
			diff = ABS(x-y);
			cout << diff;
			if(diff && diff < n && !b[diff]) b[diff] = true;
			else {jolly = false; break;}
			x = y;
		}
		cout << (jolly ? "Jolly": "Not jolly") << endl;
	}
}
