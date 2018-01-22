
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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 105;
int n, q, a[N], e[N], dp[N][N] = {};
vvi g(N);
int dfs(int u = 1, int pre = 0) {
  dp[u][0] = 0;
  int cnt = 0;
  for(int nxt : g[u]) {
    int v = e[nxt] ^ u;
    if(v == pre) continue;
    int tot = dfs(v, u) + 1;
    cnt += tot;
    FORD(i, 0, n) {
      FOR(j, 0, tot) {
        if(j <= i) dp[u][i] = min(dp[u][i], dp[v][j] + dp[u][i - j]);
      }
      if(tot <= i) {
        dp[u][i] = min(dp[u][i], dp[v][tot - 1] + a[nxt] + dp[u][i - tot]);
      }
    }
  }
  return cnt;
}
int main() {
	SYNC;
  cin >> n >> q;
  FOR0(i, n-1) {
    int u, v;
    cin >> u >> v >> a[i];
    g[u].pb(i);
    g[v].pb(i);
    e[i] = u ^ v;
  }
  memset(dp, 63, sizeof dp);
  dfs();
  cout << accumulate(a, a + n - 1, 0) - dp[1][n - 1 - q];
}

