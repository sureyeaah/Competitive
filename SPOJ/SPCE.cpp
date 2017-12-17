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
int t, n, m;
vvi g(N);
bitset<N> vis;
int dfs(int u) {
    vis[u] = 1;
    int cur = 1;
    for(int v : g[u]) {
        if(vis[v]) continue;
        cur += dfs(v);
    }
    return cur;
}
int main() {
    SYNC
    int u, v;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int ans = 1, cnt = 0;
        FOR0(i, n+1) {
            g[i].clear();
            vis.reset();
        }
        while(m--) {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        FOR(i, 1, n+1) {
            if(!vis[i]) {
                ans = ans * 1LL * dfs(i) % mod;
                cnt++;
            }
        }
        if(cnt > 1) {
            FOR0(i, cnt-2) ans = ans * 1LL * n % mod;
        } else ans = -1;
        cout << ans << newl;
    }
}