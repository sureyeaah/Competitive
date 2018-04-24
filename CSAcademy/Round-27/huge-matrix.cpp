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

int main() {
	SYNC;
	int n, m, l, r, a;
	cin >> n >> m;
	vii grid[11];
	bitset<11> bs[100005];
	FOR0(i, n) {
		cin >> l >> r >> a;
		grid[a].pb(mp(l, r));
		if(l > 1) grid[0].pb(mp(1, l-1));
		if(r < m) grid[0].pb(mp(r+1, m));
	}
	FOR0(i, 11) sort(grid[i].begin(), grid[i].end());
	FOR0(i, 11) {
		int st = 0, nd = 0;
		for(ii & cur : grid[i]) {
			if(cur.ff > nd) {
				st = cur.ff; nd = cur.ss;
				FOR(j,st,nd+1) bs[j][i] = 1;
			} else {
				FOR(j,nd+1, cur.ss + 1) bs[j][i] = 1;
				nd = cur.ss;
			}
		} 
	}
	int ans = 0;
	FOR(i,1,m+1) ans = max(ans, (int)bs[i].count());
	cout << ans;
}