// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 1e5 + 5; int n, up[N][2], sz[N], dwn[N], a[N];
V<V<int>> g(N);
int ans = 0;
int add(int a, int b) {
    return (a + b) % mod;
}
int mult(ll a, ll b) {return (a * b) % mod;}
void dfs(int u, int pre) {
    up[u][1] = a[u];
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == pre) continue;
        dfs(v, u);
        sz[u] += sz[v];
        up[u][0] = add(up[u][0], add(mult(sz[v], -a[u]), up[v][1]));
        up[u][1] = add(up[u][1], add(mult(sz[v], a[u]), up[v][0]));
        dwn[u] = add(dwn[u], dwn[v]);
    }
    ans = add(ans, add(up[u][0], up[u][1]));
    
    for(int v : g[u]) {
        if(v == pre) continue;
        ans = add(ans, mult(up[v][0], sz[u] - sz[v] - 1));
        ans = add(ans, mult(dwn[u]-dwn[v], sz[v]));
        ans = add(ans, mult(up[v][1], sz[u] - sz[v] - 1));
        ans = add(ans, mult(dwn[u]-dwn[v], -sz[v]));
    }
    dwn[u] *= -1;
    for(int v : g[u]) {
        if(v==pre) continue;
        dwn[u] = add(dwn[u], mult(sz[v], a[u]));
    }
    dwn[u] += a[u];
    ans = add(ans, dwn[u]);
    cerr << u << " " << dwn[u] << " " << up[u][0] << " " << up[u][1] << endl;
}
int main() {
    SYNC
    cin >> n;
    FOR(i, 1, n + 1) cin >> a[i];
    FOR0(i, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1, 0);
    cout << (ans + mod) % mod;
}