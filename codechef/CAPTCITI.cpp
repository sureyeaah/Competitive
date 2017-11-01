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

int main() {
	SYNC;
	int t, n, p[50005], c[50005], u, v, ind[50005];
	ll ns[50005];
	bitset<50005> vis;
	vvi graph(50005);
	cin >> t;
	while(t--) {
		cin >> n;
		FOR0(i, n+1) graph[i].clear();
		FOR0(i, n-1) {
			cin >> u >> v;
			graph[u].pb(v); graph[v].pb(u);
		}
		FOR0(i, n) cin >> p[i+1];
		FOR0(i, n) cin >> c[i+1];
		memset(ns, 0, sizeof ns);
		FOR(i, 1, n+1) {
			sort(graph[i].begin(), graph[i].end(), [p](int &l, int &r) -> bool {return p[l] < p[r];});
			FOR0(j, c[i]) ns[i] += p[graph[i][j]]; 
		}
		//FOR(i,1,n+1) cout << ns[i] << " ";
		vis.reset();
		FOR0(i, n+1) ind[i] = i;
		sort(ind+1, ind+n+1, [p,ns](int &l, int &r) -> bool {return (max((ll)p[l], ns[l]) == max((ll)p[r], ns[r])) ? ;});
		ll ans = 0;
		FOR(k,1,n+1) {
			int i = ind[k];
			if(vis[i]) continue;
			if(p[i] >= ns[i]) {
				FOR0(j, c[i]) if(!vis[graph[i][j]]) {
					ans += p[graph[i][j]];
					vis[graph[i][j]] = 1;
				}
			} else ans += p[i];
			vis[i] = 1;
		}
		cout << ans << endl;
	}
}