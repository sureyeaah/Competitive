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
#define MOD (7+(int)1e9)
bitset<200005> vis;
int n, a[200000 + 5], cnt[200000 + 5] = {};
ii dfs(int u) {
	if(vis[u]) return mp(u, 0);
	vis[u] = 1;
	ii nxt = dfs(a[u]);
	if(nxt.ff) return nxt.ff == u ? mp(0,nxt.ss+1) : mp(nxt.ff, nxt.ss + 1);
	else return nxt;
}

int main() {
	SYNC;
	cin >> n;
	int tot = 0;
	ll ans = 1;
	int pow2[200000 + 5]; pow2[0] = 1;
	FOR(i,1,200000 + 5) pow2[i] = (pow2[i-1]*2) % MOD;
	FOR(i,1,n+1) {cin >> a[i]; cnt[a[i]]++;}
	FOR(i,1,n+1) if(!cnt[i] && !vis[i]) {
		ii val = dfs(i);
		if(val.ff) continue;
		tot += val.ss;
		ans = (ans*(pow2[val.ss]-2))%MOD;
	}
	FOR(i,1,n+1) if(!vis[i]) {
		ii val = dfs(i);
		if(val.ff) continue;
		tot += val.ss;
		ans = (ans*(pow2[val.ss]-2))%MOD;
	}
	ans = (ans*(pow2[n-tot]))%MOD;
	cout << ans << endl;
}