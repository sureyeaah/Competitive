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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 2500 + 5;
int t, n, a, b, dep[N], ht[N];
vvi g(N);
void dfs(int u, int prev, int remu, int remv) {
	ht[u] = 0;
	for(int v : g[u]) {
		if(prev == v) continue;
		if((u==remu && v == remv) || (v == remu && u == remv)) continue;
		dep[v] = dep[u] + 1;
 		dfs(v, u, remu, remv);
		ht[u] = max(ht[u], ht[v] + 1);
	}
}
ii solve(int u, int v) {
	memset(dep, -1, sizeof dep);
	dep[u] = 0;
	dfs(u, 0, u, v);
	int st = max_element(dep+1, dep + n + 1) - dep;
	memset(dep, -1, sizeof dep);
	memset(ht, -1, sizeof ht);
	dep[st] = 0;
	dfs(st, 0, u, v);
	int d = *max_element(dep+1, dep + n+1);
	FOR(i, 1, n+1) {
		if(dep[i] == (d+1)/2 && ht[i] + dep[i] == d) return mp(d, i);
	}
}
int main() {
	SYNC
	cin >> t;
	while(t--) {
		cin >> n;
		FOR0(i, n+1) g[i].clear();
		FOR0(i, n-1) {
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		int ans = inf, uans, vans, urem, vrem;
		FOR(i, 1, n+1) {
			for(int u : g[i]) {
				if(u > i) {
					auto g1 = solve(i, u), g2 = solve(u, i);
					int cur = max(g1.ff, max(g2.ff, (g1.ff + 1)/2 + (g2.ff + 1)/2  + 1));
					if(cur < ans) {
						ans = cur;
						uans = g1.ss, vans = g2.ss, urem = i, vrem = u;
					}
				}
			}
		}
		cout << ans << newl;
		cout << urem << " " << vrem << newl;
		cout << uans << " " << vans << newl;
	}
}