
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
const int N = 1e5 + 5;
const int K = 205;
int n, k, s[N], path[N], cnt = 0;
ll w[N], dp[N][K], a[N];
vvi g(N);

int dfs(int u = 1, int prev = 0) {
  path[++cnt] = u;
  s[u] = 1;
  w[u] = a[u];
  for(int v : g[u]) {
    if(v == prev) continue;
    s[u] += dfs(v, u);
    w[u] += w[v];
  }
  return s[u];
}

int main() {
	SYNC;
  cin >> n >> k;
  FOR(i, 1, n+1)
    cin >> a[i];
  FOR0(i, n-1) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  memset(dp, 63, sizeof dp);
  dfs();
  dp[0][0] = 0;
  FOR(i, 1, n + 1) {
    int u = path[i];
    dp[i][0] = 0;
    FOR(j, 1, k + 1) {
      dp[i + s[u] - 1][j] = min(dp[i - 1][j - 1] + w[u], dp[i + s[u] - 1][j]);
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
    }
  }
  cout << accumulate(a + 1, a + n + 1, 0LL) - *min_element(dp[n], dp[n] + k + 1);
}

