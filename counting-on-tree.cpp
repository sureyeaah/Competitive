
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
const int N = 5e4 + 5;
const int K = 105;
int n, a[N], dp[N][K] = {}, k, ans;
vvi g(N);
inline int add(int a, int b) {return (a + b) % mod;}
inline int mult(int a, int b) {return (1LL * a * b) % mod;}
void dfs(int u, int pre = 0) {
  dp[u][a[u]] = 1;
  for(int v : g[u]) {
    if(v == pre) continue;
    dfs(v, u);
    FORD(i, 0, k+1) {
      FOR(j, 0, i+1) {
        dp[u][i] = add(dp[u][i], mult(dp[v][j], dp[u][i-j]));
      }
    }
  }
  ans = add(ans, dp[u][k]);
}
int main() {
	SYNC;
  int t;
  cin >> t;
  while(t--) {
    memset(dp, 0, sizeof dp);
    cin >> n >> k;
    FOR(i, 1, n+1) {
      cin >> a[i];
      g[i].clear();
      ans = 0;
    }
    FOR0(i, n-1) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1);
    cout << ans << newl;
  }
}
