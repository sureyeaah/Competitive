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
bitset<100005> vis;
int n,a,b,p[100005],ans[100005];
map<int,int> m;
int color;
int dfs(int u) {
	vis[u] = 1;
	ans[u] = color;
	int t1 = m[a-p[u]], t2 = m[b-p[u]];
	if(!t1 && !t2) return 0;
	if(t1 && t2) {
		if(a == 2*p[u]) return (vis[t2]) ? color == 2: dfs(t2);
		if(b == 2*p[u]) return (vis[t1]) ? color == 1: dfs(t1);
		if (vis[t1] && vis[t2]) return 0;
		if (vis[t1]) return dfs(t2);
		if (vis[t2]) return dfs(t1);
		return dfs(t2) && dfs(t1);
	}
	if(t1) return (vis[t1]) ? (color==1): dfs(t1); // a
	if(t2) return (vis[t2]) ? (color==2): dfs(t2); // b
	return 0;
}
void dfsclear(int u) {
	if(!u) return;
	if(ans[u] == -1) return;
	ans[u] = -1; vis[u] = 0;
	dfsclear(m[a-p[u]]); dfsclear(m[b-p[u]]);
}
int main() {
	SYNC;
	cin >> n >> a >> b;
	FOR(i, 1, n+1) {
		cin >> p[i];
		m[p[i]] = i;
	}
	if(a==b) {
		FOR(i,1,n+1) if(!m[a-p[i]]) {
			cout << "NO" << endl; return 0;
		}
		cout << "YES" << endl;
		FOR(i,1,n+1) cout << 0 << " ";
		return 0;
	}
	FOR(i,1,n+1) {
		if(!vis[i]) {
			color = 1;
			if(!dfs(i)) {
				dfsclear(i);
				color = 2;
				if(!dfs(i)) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	FOR(i,1,n+1) cout << ans[i]-1 << " ";
}