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
#define maxn 500005
vi g[maxn];
int fir[maxn], last[maxn], dist[maxn], idx = 1;
void dfs(int u, int depth) {
	fir[u] = idx++;
	//E[idx++] = u;
	dist[u] = depth;
	for(int v : g[u]) {
		dfs(v, depth+1);
	}
	last[u]=idx++;
	//E[idx++] = u;
}
void update(int i, ll val, ll ft[]) {
	while(i < idx) {
		ft[i] += val;
		i += (i&(-i));
	}
}
ll query(int i, ll ft[]) {
	ll ret = 0;
	while(i) {
		ret += ft[i];
		i -= (i&(-i));
	}
	return ret;
}
int main() {
	SYNC;
	int n, m, u, b, q, f[maxn], x[maxn], d[maxn], lq[maxn], rq[maxn], ans[maxn];
	ll th[maxn], ft1[maxn << 2], ft2[maxn << 2];
	vi own[maxn], check[maxn];
	cin >> n >> m;
	FOR0(i, n-1) {
		cin >> u;
		g[u].pb(i+2);
	}
	dfs(1,0);
	FOR0(i, n) {
		cin >> b;
		own[b].pb(i+1);
	}
	FOR0(i, m) cin >> th[i+1];
	cin >> q;
	FOR0(i, q) cin >> f[i] >> x[i] >> d[i];
	FOR0(i, m+1) lq[i] = 0;
	FOR0(i, m+1) rq[i] = q-1;
	FOR0(i, m+1) ans[i] = -1;
	bool done = false;
	while(!done) {
		done = true;
		FOR(i,1,m+1) {
			if(lq[i] > rq[i]) continue;
			done = false;
			check[(lq[i] + rq[i]) >> 1].pb(i);
		}
		memset(ft1,0,sizeof ft1);
		memset(ft2,0,sizeof ft2);
		FOR0(i, q) {
			update(fir[f[i]], x[i] - d[i]*((ll) dist[f[i]]), ft1);
			update(last[f[i]], -x[i] + d[i]*((ll) dist[f[i]]), ft1);
			update(fir[f[i]], d[i], ft2);
			update(last[f[i]], -d[i], ft2);
			while(!check[i].empty()) {
				for(int curr: check[i]) {
					ll amt = 0;
					for(int industry: own[curr]) {
						amt += query(fir[industry], ft1);// - query(last[industry], ft1);
						amt += (query(fir[industry], ft2) /*- query(last[industry], ft2)*/) * (ll)dist[industry];
						if(amt >= th[curr]) break;
					}
					if(amt >= th[curr]) {rq[curr] = i-1; ans[curr] = i+1;}
					else lq[curr] = i+1;
				}
				check[i].clear();
			}
		}
	}
	FOR(i, 1, m+1)
		if(ans[i] == -1) cout << "rekt" << endl;
		else cout << ans[i] << endl;
}