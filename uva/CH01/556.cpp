#include <iostream>
#include <vector>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int x, y, xd, yd, tmp, b, w;
vector<vector<int>> v;
void mv() {
	while(!v[x+xd][y+yd]) {
		tmp = xd;
		xd = -yd;
		yd = tmp;
	}
	x+=xd; y+=yd;
	if(v[x+yd][y-xd]) {
		tmp = xd;
		xd = yd;
		yd = -tmp;
	}
}

int main() {
	//ios::sync_with_stdio(false);
	char c;
	cin >> b >> w;
	while(b > 0) {
		x = b, y = 1, xd = 0, yd = 1;
		int val[6] = {};
		c=getchar();
		v.clear();
		v.resize(b+2,vector<int>(w+2));
		FOR0(i,w+2) {
			v[0][i] = 0;
		}
		FOR(i,1,b+1) {
			v[i][0] = 0;
			FOR(j,1,w+1){
				c=getchar();
				v[i][j] = c == '0' ? 1:0;
			}
			v[i][w+1]=0;
			c=getchar();
		}
		v[b+1] = v[0];
		do {
			v[x][y]++;
			mv();
		} while(x!=b || y!=1);

		FOR(i,1,b+1) {
			FOR(j,1,w+1) {
				val[v[i][j]]++;
			}
		}
		FOR(i,1,6) {
			printf("%3d",val[i]);
		}	
		cout << endl;
		cin >> b >> w;
	}
}