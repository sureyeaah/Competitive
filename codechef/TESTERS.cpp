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
const int N = 3e5 + 5, M = 1500005;
int n, a[N], cntft[2*N] = {}, vis[N] = {}, sz[N];
ll ans = 0, depft[2*N] = {};
vvi g(N); vector<vii> val(N);
void dfs(int u, int pre) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v != pre && !vis[v]) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int centroid(int u, int pre, int tot) {
    for(int v : g[u]) {
        if(v != pre && !vis[v] && sz[v] > tot/2)
            return centroid(v, u, tot);
    }
    return u;
}
template <typename T> 
void upd(int i, int val, T ft[2*N]) {
    for(;i<2*N;i+=i&-i)
        ft[i] += val;
}
template <typename T> 
T query(int i, T ft[2*N]) {
    T ret = 0;
    for(;i;i-=i&-i)
        ret += ft[i];
    return ret;
}
void dfs1(int u, int pre, int dep, int del, int head) {
    del += a[u] ? 1 : -1;
    val[head].pb({del, dep});
    upd(n - del, dep, depft);
    upd(n - del, 1, cntft);
    for(int v : g[u]) {
        if(v != pre && !vis[v]) {
            dfs1(v, u, dep + 1, del, head);
        }
    }
}
void decompose(int u) {
    if(!u) {
        dfs(1, 0); u = centroid(1, 0, sz[1]);
    }
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v]) continue;
        dfs1(v, u, 1, 0, v);
    }
    if(a[u]) ans++;
    for(int v : g[u]) {
        if(vis[v]) continue;
        for(auto& x : val[v]) {
            upd(n - x.ff, -x.ss, depft);
            upd(n - x.ff, -1, cntft);
        }
        for(auto& x : val[v]) {
            ans += query(n + x.ff + (a[u] ? 1 : -1), depft);
            ans += query(n + x.ff + (a[u] ? 1 : -1), cntft) * 1LL * (x.ss + 1);
            if(x.ff + (a[u] ? 1 : -1) >= 0) ans += x.ss + 1; 
        }
        val[v].clear();
    }
    for(int v : g[u]) {
        if(vis[v]) continue;
        dfs(v, 0); v = centroid(v, 0, sz[v]);
        decompose(v);
    }
}
int main() {
    SYNC
    cin >> n;
    int u, v, sq[M] = {};
    for(int i = 0; i * i < M; i++) {
        sq[i*i] = 1;
    }
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR(i, 1, n + 1) {
        cin >> a[i];
        while((a[i] & 1) == 0) a[i] >>= 1;
        a[i] = sq[a[i]];
    }
    decompose(0);
    cout << ans;
}