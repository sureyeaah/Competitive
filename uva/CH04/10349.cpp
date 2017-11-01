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
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define poi '*'
#define valid(r, c) (r >= 0 && c >= 0 && r < h && c < w)
int n, h, w, match[41][11][2], dx[4], dy[4], vis[41][11];
char grid[41][11];
int augment(int r, int c) {
	if(vis[r][c]) return 0;
	vis[r][c] = 1;
	FOR0(x, 4) {
		int i = r+dx[x], j = c+dy[x]; 
		if(valid(i,j) && grid[i][j] == poi && (match[i][j][0] == -1 || augment(match[i][j][0], match[i][j][1]))) {
			match[i][j][0] = r; match[i][j][1] = c; return 1;
		}
	}
	return 0;
}
int main() {
	dx[0] = dx[2] = dy[1] = dy[3] = 0; dx[1] = dy[0] = 1; dx[3] = dy[2] = -1;
	SYNC;
	cin >> n;
	while(n--) {
		cin >> h >> w;
		FOR0(i, h) FOR0(j, w) cin >> grid[i][j];
		FOR0(i, h) FOR0(j, w) FOR0(k, 2) match[i][j][k] = -1;
		int ans = 0;
		FOR0(i, h) FOR0(j, w) {
			if(grid[i][j] == poi) {
				ans++;
				if((i&1) != (j&1)) continue;
				memset(vis, 0, sizeof vis);
				ans -= augment(i, j);
			}
		}
		cout << ans << endl;
	}
}