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
int n, q, h[100000 + 5], l[200000 + 5], e[200000 + 5], idx, st[800000 + 5];
vvi graph(100000 + 5);
void dfs(int u, int depth, int prev) {
	h[u] = idx; e[idx] = u; l[idx++] = depth;
	for(int v : graph[u]) {
		if(v == prev) continue;
		dfs(v, depth+1, u);
		e[idx] = u;
		l[idx++] = depth;
	}
}
void build(int p, int lt, int rt) {
	if(lt == rt) {st[p] = lt; return;}
	build(p<<1,lt,(lt+rt)>>1);
	build(p<<1|1,((lt+rt)>>1)+1, rt);
	if(l[st[p<<1]] < l[st[p<<1|1]]) st[p] = st[p<<1];
	else st[p] = st[p<<1|1];
}
int rmq(int p, int lt, int rt, int i, int j) {
	if(lt > j || rt < i) return INF;
	if(lt >= i && rt <= j) return st[p];
	int lq = rmq(p<<1,lt,(lt+rt)>>1,i,j);
	int rq = rmq(p<<1|1,((lt+rt)>>1)+1, rt,i,j);
	if(lq == INF) return rq; if(rq == INF) return lq;
	if(l[lq] < l[rq]) return lq;
	else return rq;
}

int lca(int a, int b) {
	return e[rmq(1,0,2*n-2,min(h[a], h[b]), max(h[a], h[b]))];
}
int dist(int a, int b) {
	return l[h[a]]+l[h[b]] - 2*l[h[lca(a,b)]];
}
int main() {
	SYNC;
	 cin >> n >> q;
	FOR0(i, n-1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb(v); graph[v].pb(u);
	}
	idx = 0; memset(h,-1,sizeof(h));
	dfs(1,0, -1);
	build(1,0,2*n-2);
	while(q--) {
		int a, b, c;
		cin >> a >> b >> c;
		int x = lca(a,b);
		int ans = INF, d = -1, tmp;
		if((tmp=dist(a,x)+dist(b,x)+dist(c,x)) < ans) {d = x; ans = tmp;}
		x = lca(b,c);
		if((tmp=dist(a,x)+dist(b,x)+dist(c,x)) < ans) {d = x; ans = tmp;}
		x = lca(c,a);
		if((tmp=dist(a,x)+dist(b,x)+dist(c,x)) < ans) {d = x; ans = tmp;}
		cout << d << " " << ans<< endl;
	}
}