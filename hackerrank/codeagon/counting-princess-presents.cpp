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
#define mod (7 + (int)1e9)
int dp[N] = {};
int n, special[N] = {}, x;
vvi g(N);
bool dfs(int u, int prev) {
    for(int v : g[u]) {
        if(v != prev) {
            if(dfs(v, u)) special[u] = 1;
        }
    }
    return special[u];
}
void ways(int u, int prev) {
    int cnt = 0; dp[u] = 1;
    for(int v : g[u]) {
        if(v != prev) {
            cnt++;
            ways(v, u);
            dp[u] = 1LL*dp[u]*(!special[v] + dp[v]) % mod;
        }
    }
}

int main() {
    int u, v;
    SYNC
    int t;
    cin >> t;
    while(t--) {
        int root = 0;
        cin >> n;
        FOR0(i, N) g[i].clear();
        memset(special, 0, sizeof special);
        memset(dp, 0, sizeof dp);
        FOR0(i, n-1) {
            cin >> u >> v >> x;
            g[u].pb(v);
            g[v].pb(u);
            special[u] |= x;
            special[v] |= x;
            if(special[u]) root = u;
            else if (special[v]) root = v;
        }
        if(root) {
            dfs(root, 0);
        }
        ways(max(1, root), 0);
        ll ans = 0;
        if(!root) {
            FOR(i,1,n+1)
                ans = (ans + dp[i]) % mod;
        }
        else ans = dp[root];
        cout << ans << '\n';
    }
}