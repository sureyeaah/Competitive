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
#define printCase() "Case " << caseNum << ":"
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
// from stanford notebook
struct edge {
	int u, v;
	int c, f;
	edge() { }
	edge(int _u, int _v, int _c, int _f = 0): u(_u), v(_v), c(_c), f(_f) { }
};
int numVer; // number of vertices
vector<edge> edges;
vector<vector<int> > g(5000);
vector<int> d, pt;

void addEdge(int u, int v, int c, int f = 0) {
	g[u].push_back(edges.size());
	edges.push_back(edge(u,v,c,f));
	g[v].push_back(edges.size());
	edges.push_back(edge(v,u,0,-f));
}
bool bfs(int s, int t) {
	queue<int> q; q.push(s);
	d.assign(numVer+1, numVer+2);
	d[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		FOR0(tmp,SZ(g[u])) {
			int k = g[u][tmp];
			edge &e = edges[k];
			if(e.f < e.c && d[e.v] > d[e.u] + 1){
				d[e.v] = d[e.u] + 1;
				q.push(e.v);
			}
		}
	}
	return d[t] < numVer+2;
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
		pt.assign(numVer+1, 0);
		while(int val = dfs(s,t)) ans += val;
	}
	return ans;
}

int main() {
	SYNC;
	int cases, n, m, x, s, t, d1[55][55], d2[55][55], mat[105][105];
	cin >> cases;
	FOR(caseNum,1,cases + 1) {
		cin >> n >> m;
		s = 0; t=1; numVer = 2;
		FOR(i,1,n+m) {
			cin >> x;
			FOR0(j,min(i,n)) {
				if(i-j >= 0 && i-j-1 < m) {
					d1[j][i-j-1] = numVer;
					x--;
				}
			}
			addEdge(s,numVer,x,0);
			numVer++;
		}
		FOR(i,1,n+m) {
			cin >> x;
			FOR0(j,min(i,n)) {
				if(m+j-i >= 0) {
					d2[j][m+j-i] = numVer;
					addEdge(d1[j][m+j-i], numVer, 99, 0);
					x--;
				}
			}
			addEdge(numVer,t,x,0);
			numVer++;
		}
		numVer++;
		flow(s,t);
		cout << printCase() << "\n";
		FOR0(i, SZ(edges)) {
			edge& e = edges[i];
			if(e.u != s && e.v != t && e.c > 0) mat[e.u][e.v] = e.f;
		}
		FOR0(i, n) {
			FOR0(j, m) cout << 1+mat[d1[i][j]][d2[i][j]] << (j==m-1 ? "\n": " ");
		}
		edges.clear();
		FOR0(i,numVer+2) g[i].clear();
	}
}