#include <iostream>
#include <vector>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int tc, a, b, c, sl1, sl2, dice, moveBy[107];  vector<int> ppos;
	cin >> tc;
	while(tc--) {
		FOR0(i,107) moveBy[i] = 0;
		bool won = false;
		cin >> a >> b >> c;
		ppos.clear();
		ppos.resize(a,1);
		FOR0(i,b){
			cin >> sl1 >> sl2;
			moveBy[sl1] =sl2 - sl1;
		}
		FOR0(i,c/a) {
			FOR0(j, a) {
				cin >> dice;
				ppos[j] += dice;
				ppos[j] += moveBy[ppos[j]];
				if(ppos[j] >= 100) {ppos[j] = 100; won = true; c -= i*a + j+1;i=c/a;break;}
			}
		}
		if(!won) {
			FOR0(j, c%a) {
				cin >> dice;
				ppos[j] += dice;
				ppos[j] += moveBy[ppos[j]];
				if(ppos[j] >= 100) {ppos[j]=100; won = true; c -= a*((int)c/a) + j+1;break;}
			}
		}
		if(won) {
			FOR0(i,c) cin >> dice;
		}
		FOR0(i, a) {
            printf("Position of player %d is %d.\n", i+1, ppos[i]);
    }
	}
}
