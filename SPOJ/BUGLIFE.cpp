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
#define printCase() "Scenario #" << caseNum << ":\n"
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
int t, n, m, x, y;
vvi graph(4005);
bitset<4005> vis,vis2;
int sex[2005], impos;
int dfs(int u) {
	vis[u] = 1;
	for(int v : graph[u]) {
		if(vis[v]) continue;
		int ret = dfs(v);
		if(sex[u>>1] == -1) sex[u>>1] = ret;
		else if(ret == sex[u>>1]) impos = 1;
	}
	return sex[u>>1];
}
void dfs2(int u, int val) {
	vis2[u] = 1;
	if(sex[u>>1] == -1) sex[u>>1] = val;
	else if(sex[u>>1] != val) impos = 1;
	for(int v : graph[u]) if(!vis2[v]) dfs2(v, !val);
}
int main() {
	SYNC;	
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> n >> m;
		FOR0(i, 4005) graph[i].clear();
		vis.reset(); vis2.reset(); impos = 0;
		FOR0(i, m) {
			cin >> x >> y;
			x<<=1; y<<=1;
			graph[x].pb(y^1); graph[x^1].pb(y);
			graph[y].pb(x^1); graph[y^1].pb(x);
		}
		FOR0(i, n+2) sex[i] = -1;
		FOR(i, 1, n+1) {
			if(!vis[i<<1]) {
				int ret = dfs(i<<1);
				dfs2(i<<1,(ret==-1?0:ret));
			}
		}
		cout << printCase() << (!impos ? "No suspicious bugs found!": "Suspicious bugs found!") << endl;
	}
}