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
struct edge {
	int u, v;
	int c, f;
	edge() { }
	edge(int _u, int _v, int _c, int _f = 0): u(_u), v(_v), c(_c), f(_f) { }
};
int n;
vector<edge> edges;
vector<vector<int> > g(250);
vector<int> d, pt;

void addEdge(int u, int v, int c, int f = 0) {
	g[u].emplace_back(edges.size());
	edges.emplace_back(edge(u,v,c,f));
	g[v].emplace_back(edges.size());
	edges.emplace_back(edge(v,u,0,0));
}
bool bfs(int s, int t) {
	queue<int> q({s});
	d.assign(n+1, n+2);
	d[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for(int k : g[u]) {
			edge &e = edges[k];
			if(e.f < e.c && d[e.v] > d[e.u] + 1){
				d[e.v] = d[e.u] + 1;
				q.push(e.v);
			}
		}
	}
	return d[t] < n+2;
}

int dfs(int u, int t, int flow = -1) {
	if(u == t || !flow) return flow;
	for(int &i = pt[u]; i < (int)(g[u].size()); i++) {
		edge &e = edges[g[u][i]], &oe=edges[g[u][i]^1];
		if(d[e.v] == d[e.u] + 1) {
			int amt = e.c - e.f;
			if (flow != -1 && amt > flow) amt = flow;
			if(int pushed = dfs(e.v,t,amt)) {
				e.f += pushed;
				oe.f -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

int flow(int s, int t) {
	int ans = 0;
	while(bfs(s,t)) {
		pt.assign(n+1, 0);
		while(int val = dfs(s,t)) ans += val;
	}
	return ans;
}
int main() {
	SYNC;
	int t, num, x;
	cin >> t;
	while(t--) {
		cin >> n;
		edges.clear();
		FOR0(i, n+1) g[i].clear();
		FOR(i, 1, n) {
			cin >> num;
			while(num--) {
				cin >> x;
				int capacity = (i == 1 || x == n) ? 1 : INF;
				addEdge(i,x,capacity);
			}
		}
		cout << flow(1,n) << endl;
	}
}