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
const int N = 1e5 + 5, LOGN = 19;

V<V<int>> g(N);
int n, q, a, b, c, par[N][LOGN], sz[N], dep[N];
void dfs(int u) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == par[u][0]) continue;
        par[v][0] = u, dep[v] = dep[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
}
int lca(int u , int v){
    if(dep[u] < dep[v])swap(u , v); 
    for(int i = LOGN - 1; i >= 0; i--){
        if(par[u][i] && dep[u] - (1 << i) >= dep[v])
            u = par[u][i]; 
    }
    if(v == u) return u;
    for(int i = LOGN - 1; i >= 0; i--){
        if(par[u][i] && par[u][i] != par[v][i]){ 
            u = par[u][i]; v = par[v][i]; 
        }
    }
    return par[u][0];
}
int kth(int u, int k) {
    for(int i = LOGN - 1; i >= 0; i--){
        if(k & (1 << i)) {
            u = par[u][i];
        }
    }
    return u;
}
int val(int x, int y) {
    int l = lca(x, y);
    if(l == y) {
        x = kth(x, dep[x] - dep[y] - 1);
        return sz[x];
    } else {
        return n - sz[y];
    }
}
int dist(int x, int y) {
    int l = lca(x, y);
    return dep[x] + dep[y] - 2*dep[l];
}
int main() {
    SYNC
    cin >> n >> q;
    FOR0(i, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);
    for(int i = 1; i < LOGN; i++) {
        for(int u = 1; u <= n; u++) {
            par[u][i] = par[par[u][i-1]][i-1];
        }
    }
    while(q--) {
        cin >> a >> b >> c;
        int ans = (dist(a,c) + dist(b,c) == dist(a,b)) ? n - val(a, c) - val(b, c): 0;
        cout << ans << endl; 
    }
}