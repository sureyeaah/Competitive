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
const int N = 2e5 + 5, LOGN = 19;
int n,m,start=1,lvl[N]={},sz[N],par[N],best[N],dist[N][LOGN];
vvi g(N);
int dfs2(int u, int pre, int head) {
    dist[u][lvl[head]] = pre ? 1 + dist[pre][lvl[head]]: 0;
    for(int v : g[u]) {
        if(v==pre || lvl[v]) continue;
        dfs2(v, u, head);
    }
}
int dfs(int u, int pre) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v==pre || lvl[v]) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}
int centroid(int u, int pre, int tot) {
    for(int v : g[u]) {
        if(v==pre || lvl[v]) continue;
        if(sz[v] > tot/2) return centroid(v,u,tot);
    }
    return u;
}
void decompose(int u, int l = 1) {
    if(!u) {
        dfs(1, 0);
        u = centroid(1, 0, sz[1]);
        par[u] = 0;
    }
    lvl[u] = l;
    dfs2(u, 0, u);
    for(int v : g[u]) {
        if(lvl[v]) continue;
        dfs(v, 0);
        int nr = centroid(v, 0, sz[v]);
        par[nr] = u;
        decompose(nr, l + 1);
    }
}
int getDist(int u, int v) {
    int l1=u, l2=v;
    while (u != v) {
        if(lvl[u] < lvl[v]) swap(u, v);
        u = par[u];
    }
    return dist[l1][lvl[u]] + dist[l2][lvl[u]];
}
void update(int u) {
    int v = u;
    while(u) {
        best[u] = min(best[u], getDist(v, u));
        u=par[u];
    }
}
int query(int u) {
    int ans = inf, v=u;
    while(u) {
        ans = min(ans, getDist(v, u) + best[u]);
        u=par[u];
    }
    return ans;
}
int main() {
    SYNC
    cin >> n >> m;
    int a, b;
    FOR0(i, n - 1) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    decompose(0);
    memset(best,63,sizeof best);
    update(1);
    int type,v;
    while(m--) {
        cin >> type >> v;
        if(type==1) {
            update(v);
        } else cout << query(v) << newl;
    }
}