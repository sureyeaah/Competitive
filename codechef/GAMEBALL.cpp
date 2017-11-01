#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define valid(i,j) (i >= 0 && j >= 0 && i < n && j < m)


struct ans {
	int x1,y1,x2,y2;
	ans() { }
	ans(int _x1, int _y1, int _x2, int _y2) : x1(_x1+1), y1(_y1+1), x2(_x2+1), y2(_y2+1) { }
};
int main() {
	SYNC;
	int t, n, m, di[4], dj[4];
	char x;
	int grid[11][11];
	di[0] = di[2] = dj[1] = dj[3] = 0; di[1] = dj[0] = 1; di[3] = dj[2] = -1;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		FOR0(i, n) {
			FOR0(j, m) {
				cin >> x;
				grid[i][j] = (x=='*') ;
			}
		}
		vector<ans> output;
		if(n == m && m <= 2) {cout << -1 << endl; continue;}
		else {
			int cnt = n*m - 1;
			while(cnt > 1 && output.size() <= 5000) {
				bool done = false;
				FOR0(i,n) FOR0(j, m) {
					if(grid[i][j]) {
						FOR0(k, 4)
						if(valid(i+di[k],j+dj[k]) && valid(i-di[k],j-dj[k]) && !grid[i+di[k]][j+dj[k]] && grid[i-di[k]][j-dj[k]]) {
							done = true;
							grid[i+di[k]][j+dj[k]] = 1;
							grid[i-di[k]][j-dj[k]] = grid[i][j] = 0;
							output.pb(ans(i-di[k],j-dj[k],i+di[k],j+dj[k]));
							cnt--;
							break;
						}
					}
				}
				if(done || cnt==1) continue;
				FOR0(i,n) {
					FOR0(j, m) {
						if(grid[i][j]) {
							FOR0(k, 2)
							if(valid(i+di[k],j+dj[k]) && !grid[i+di[k]][j+dj[k]]) {
								done = true;
								grid[i+di[k]][j+dj[k]] = 1;
								grid[i][j] = 0;
								output.pb(ans(i,j,i+di[k],j+dj[k]));
								break;
							}
						}
					}
				}
				if(done) continue;
				FOR0(i,n-1) {
					FOR0(j, m-2) {
						if(!grid[i][j] && !grid[i][j+1] && grid[i+1][j+2]) {
							output.pb(ans(i+1,j+2,i,j+1));
							grid[i][j+1] = 1; grid[i+1][j+2] = 0;
							done = true;
							break;
						}
					}
					if(done) continue;
				}
				if(done) continue;
				FOR0(i,n-2) {
					FOR0(j, m-1) {
						if(!grid[i][j] && !grid[i+1][j] && grid[i+2][j+1]) {
							output.pb(ans(i+2,j+1,i+1,j));
							grid[i+1][j] = 1; grid[i+2][j+1] = 0;
							done = true;
							break;
						}
					}
					if(done) continue;
				}
			}
			if(cnt > 1) {cout << -1 << endl; continue;}
			cout << output.size() << '\n';
			for(auto& i : output) cout << i.x1 << " " << i.y1 << " " << i.x2 << " " << i.y2 << '\n';
		}
	}
}