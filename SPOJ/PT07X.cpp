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
#define maxn 100005
int n, dp1[maxn], dp2[maxn];
vvi graph(maxn);
void dfs(int u, int par) {
	dp1[u] = 1; dp2[u] = 0;
	for(int v : graph[u]) {
		if(v == par) continue;
		dfs(v, u);
		dp1[u] += min(dp1[v], dp2[v]);
		dp2[u] += dp1[v];
	}
}
int main() {
	SYNC;
	cin >> n;
	int u, v;
	FOR0(i, n-1) {
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dfs(1, -1);
	cout << min(dp1[1], dp2[1]) << endl;
}