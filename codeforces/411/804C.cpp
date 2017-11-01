#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
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
int n, m, s, u, v, color[300005], x;
vi ice[300005], graph[300005];
void dfs(int u, int prev) {
	sort(ice[u].begin(), ice[u].end(), [](int lhs, int rhs) {return color[lhs] < color[rhs];});
	int p1 = 0, p2 = lower_bound(ice[u].begin(), ice[u].end(), INF, [](int lhs, int rhs) {return color[lhs] < rhs;})-ice[u].begin(), curr = 1;
	while(p2 < ice[u].size()) {
		while(curr == color[ice[u][p1]]) {curr++; p1++;}
		color[ice[u][p2++]] = curr++;
	}
	for(int v: graph[u]) {
		if(v == prev) continue;
		dfs(v, u);
	}
}
int main() {SYNC;
	cin >> n >> m;
	FOR0(i,m+1) color[i] = INF;
	FOR0(i, n) {
		cin >> s;
		while(s--) {cin >> x; ice[i+1].pb(x);}
	}
	FOR0(i, n-1) {
		cin >> u >> v;
		graph[u].pb(v); graph[v].pb(u);
	}
	dfs(1,-1);
	FOR(i,1,m+1) if(color[i] == INF) color[i] = 1;
	cout << *max_element(color+1, color+m+1) << endl;
	FOR(i,1,m+1) cout << color[i] << " ";
}