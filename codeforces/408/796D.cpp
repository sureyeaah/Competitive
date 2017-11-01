#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
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
#define MAXN 300005
int n, k, d, ps[MAXN] = {}, dist[MAXN];
bitset<MAXN> police;
vector<vii> graph(MAXN);
int main() {
	SYNC;
	memset(dist, 63, sizeof dist);
	int u, v, x;
	cin >> n >> k >> d;
	queue<int> q;
	FOR0(i, k) {
		cin >> x;
		if(police[x]) continue;
		q.push(x);
		police[x] = 1;
		dist[x] = 0;
		ps[x] = x;
	}
	cout << police.count() - 1 << '\n';
	FOR0(i, n-1) {
		cin >> u >> v;
		graph[u].pb(mp(v, i+1));
		graph[v].pb(mp(u, i+1));
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(ii v : graph[u]) {
			if(dist[v.ff] > dist[u] + 1) {
				dist[v.ff] = dist[u] + 1;
				ps[v.ff] = ps[u];
				q.push(v.ff);
			}
		}
	}
	FOR(i,1,n+1) {
		for(ii e : graph[i]) {
			if(e.ff > i && ps[i] != ps[e.ff]) cout << e.ss << ' ';
		}
	}
}