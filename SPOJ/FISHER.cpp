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

int n, t, toll[51][51], tt[51][51];
ii dp[51][1001];
ii go(int u, int tLeft) {
	if(tLeft < 0) return mp(INF, INF);
	if(u == n-1) return mp(0,0);
	if(dp[u][tLeft] != mp(-1, -1)) return dp[u][tLeft];
	ii ans = mp(INF, INF);
	FOR0(i, n) {
		if(i != u) {
			ii nxt = go(i, tLeft - tt[u][i]);
			if(nxt.ff + toll[u][i] < ans.ff) {
				ans.ff = nxt.ff + toll[u][i];
				ans.ss = nxt.ss + tt[u][i];
			}
		} 
	}
	return dp[u][tLeft] = ans;
}
int main() {
	while(scanf("%d%d", &n, &t) && (n||t)) {
		FOR0(i, n) FOR0(j, n) scanf("%d", &tt[i][j]);
		FOR0(i, n) FOR0(j, n) scanf("%d", &toll[i][j]);
		FOR0(i, n) FOR0(j, t+1) dp[i][j] = mp(-1, -1);
		ii ans = go(0, t);
		printf("%d %d\n", ans.ff, ans.ss);
	}
}