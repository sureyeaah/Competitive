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
const int N = 1e5 + 5;
int t, n, m, k, a[N], b[N][2], l, r; char type;
int ans = 1;
bitset<N> vis;
V<V<P<int,int>>> g(N);
void dfs(int u) {
    vis[u] = 1;
    if(a[u] < 1 || a[u] > k) ans=0;
    for(auto v : g[u]) {
        if(a[v.ff] == -1) a[v.ff] = a[u] + v.ss;
        else if(a[v.ff] != a[u] + v.ss) {ans = 0;}  
        if(a[v.ff] < 1 || a[v.ff] > k) ans=0;
        if(!vis[v.ff]) dfs(v.ff);
    }
}
void dfs1(int u, int x, int& a, int& b) {
    vis[u] = 1;
    a = min(a, x); b = max(b, x);
    for(auto v : g[u]) {
        if(!vis[v.ff]) dfs1(v.ff, x + v.ss, a, b);
    }
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        ans=1;
        vis.reset();
        memset(b, 0, sizeof b);
        cin >> n >> m >> k;
        FOR(i, 1, n+1) cin >> a[i];
        while(m--) {
            cin >> type >> l >> r;
            int ind = type=='I' ? 1 : 0;
            b[r][ind]--; b[l][ind]++;
        }
        FOR(i, 1, n) {
            b[i][0] += b[i-1][0];
            b[i][1] += b[i-1][1];
        }
        FOR(i, 1, n + 1) g[i].clear();
        FOR0(i, n) FOR0(j, 2) b[i][j] = b[i][j] != 0;
        FOR0(i, n) if(b[i][0] && b[i][1]) ans = 0;
        if(!ans) {cout << 0 << endl; continue;}
        FOR(i, 1, n) {
            if(b[i][1]) {
                g[i].pb(mp(i+1, 1));
                g[i+1].pb(mp(i, -1));
            }
            if(b[i][0]) {
                g[i].pb(mp(i+1, -1));
                g[i+1].pb(mp(i, 1));
            }
        }
        FOR(i, 1, n + 1) {
            if(!vis[i] && a[i] != -1) dfs(i);
        }
        FOR(i, 1, n + 1) {
            if(!vis[i]) {
                int a=0, b=0;
                dfs1(i, 0, a, b);
                ans = ans * 1LL * max(0, k-(b-a+1)+1) % mod;
            }
        }
        cout << ans << endl;
    }
}