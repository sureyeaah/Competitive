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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 100005
#define mod (1000000007)
inline int add(int x,int y) {return (((x) + (y)) % mod);}
inline int mul(int x, int y) {return (1LL * (x)*(y)) % mod;}
int n, m, k, x, dp[N][15][3] = {};
vvi g(N);
void dfs(int u, int prev) {
    dp[u][1][1] = 1;
    dp[u][0][0] = (k - 1);
    dp[u][0][2] = (m - k);
    for(int v : g[u]) {
        if(v == prev) continue;
        dfs(v, u);
        FORD(i,0,x+1) {
            int a = 0, b = 0, c = 0;
            FOR(j,0,i+1) {
                a = add(a,mul(dp[u][i-j][1], dp[v][j][0]));
                b = add(b, mul(dp[u][i-j][0], add(dp[v][j][1], add(dp[v][j][0],dp[v][j][2]))));
                c = add(c, mul(dp[u][i-j][2], add(dp[v][j][0], dp[v][j][2])));
            }
            dp[u][i][2] = c;
            dp[u][i][0] = b;
            dp[u][i][1] = a;
        }
    }
}
int main() {
    SYNC
    int u, v;
    cin >> n >> m;
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> k >> x;
    dfs(1, 0);
    int ans = 0;
    FOR0(i, x+1) {
        ans = add(ans, add(dp[1][i][0], add(dp[1][i][1], dp[1][i][2])));
    }
    cout << ans;
}