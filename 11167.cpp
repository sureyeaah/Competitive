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
#define printCase "Case " << ++caseNum << ": "
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
int n, m, v[200], a[200], b[200], cnt, src=0, snk;
map<int, int> compress;
struct edge {
	int u,v,c,f;
	edge() {}
	edge(int _u, int _v, int _c, int _f): u(_u), v(_v), c(_c), f(_f) {}
};
vector<edge> edges;
vvi graph(1000);
void addEdge(int u, int v, int c) {
	graph[u].pb(SZ(edges));
	edges.pb(edge(u,v,c,0));
	graph[v].pb(SZ(edges));
	edges.pb(edge(v,u,0,0));
}
int bfs() {
	vi par(snk+1, -1), ptr(snk+1, 0);
	par[src] = src;
	int ret;
	queue<ii> q({mp(src, INF)});
	while(!q.empty()) {
		ii curr = q.front(); q.pop();
		if(curr.ff == snk) {ret = curr.ss; break;}
		for(int k : graph[curr.ff]) {
			edge &e = edges[k];
			if(par[e.v] == -1 && e.f < e.c) {
				par[e.v] = e.u;
				ptr[e.v] = k;
				q.push(mp(e.v, min(e.c-e.f, curr.ss)));
			}
		}
	}
	if(par[snk] == -1) return 0;
	int u = snk;
	while (u != src) {
		edges[ptr[u]].f += ret;
		edges[ptr[u]^1].f -= ret;
		u = par[u];
	}
	return ret;
}
int flow() {
	int ret = 0;
	while(int cur = bfs()) {
		ret += cur;
	}
	return ret;
}
int main() {
	SYNC;
	int caseNum = 0;
	while(cin >> n && n) {
		int tot = 0;
		cin >> m;
		cnt = 0;
		compress.clear();
		FOR0(i, n) {
			cin >> v[i] >> a[i] >> b[i];
			tot += v[i];
			if(!compress[a[i]]) compress[a[i]] = 1;
			if(!compress[b[i]]) compress[b[i]] = 1;
		}
		vi intervals;
		for(auto& x : compress) intervals.pb(x.ff);
		for(auto& x : intervals) compress[x] = cnt++;
		src = n+cnt; snk = src + 1;
		FOR0(i, snk+1) graph[i].clear();
		FOR0(i, n) {
			addEdge(src,i,v[i]);
			FOR(j,compress[a[i]],compress[b[i]]) addEdge(i,n+j,intervals[j+1]-intervals[j]);
		}
		FOR0(i,SZ(intervals)-1) addEdge(i+n, snk, m*(intervals[i+1]-intervals[i]));
		cout << printCase;
		int done[50001] = {};
		if(flow() == tot) {
			cout << "Yes" << endl;
			FOR0(i, n) {
				vii curr;
				FOR(x, 1, SZ(graph[i])) {
					edge &e = edges[graph[i][x]];
					if(e.f > 0) {
						int st = intervals[e.v-n];
						while(done[st] == m) st++;
						int nd = st+e.f;
						FOR(k,st,nd) done[k]++;
						if(!curr.empty() && curr[SZ(curr)-1].ss == st) curr[SZ(curr)-1].ss = nd;
						else curr.pb(mp(st,nd));
					}
				}
				cout << SZ(curr);
				for(auto cur: curr) cout << " " << "(" << cur.ff << "," << cur.ss << ")";
				cout << endl;
			}
		} else cout << "No" << endl;
	}
}