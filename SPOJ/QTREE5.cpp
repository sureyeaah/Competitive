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
const int N = 1e5 + 5, LOGN = 20;
vvi g(N);
multiset<int> white[N];
int n, q, a, b, type, col[N] = {}, dist[N][LOGN] = {}, lvl[N] = {}, par[N], sz[N];
void dfs(int u, int pre) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v != pre && !lvl[v]) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int centroid(int u, int pre, int tot) {
    for(int v : g[u]) {
        if(v != pre && !lvl[v] && sz[v] > tot/2) {
            return centroid(v, u, tot);
        }
    }
    return u;
}
int dfs1(int u, int pre, int head=0) {
    if(!pre) {
        head = u;
        dist[u][lvl[head]] = 0;
    } else dist[u][lvl[head]] = dist[pre][lvl[head]] + 1;
    for(int v : g[u]) {
        if(v != pre && !lvl[v]) {
            dfs1(v, u, head);
        }
    }    
}
void decompose(int u) {
    if(!u) {
        dfs(1, 0); u = centroid(1, 0, sz[1]);
        par[u] = 0;
    }
    lvl[u] = lvl[par[u]]+1;
    dfs1(u, 0);
    for(int v : g[u]) {
        if(lvl[v]) continue;
        dfs(v, 0); v = centroid(v, 0, sz[v]);
        par[v] = u;
        decompose(v);
    }
}
void update(int u) {
    int cur = u;
    while(cur) {
        if(col[u]) {
            white[cur].insert(dist[u][lvl[cur]]);
        }
        else {
            white[cur].erase(white[cur].find(dist[u][lvl[cur]]));
        }
        cur = par[cur];
    }
}
int query(int u) {
    int ans = inf, cur = u;
    while(cur) {
        if(!white[cur].empty())
            ans = min(ans, *(white[cur].begin()) + dist[u][lvl[cur]]);
        cur = par[cur];
    }
    return ans==inf ? -1: ans;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n - 1) {
        cin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }
    lvl[0] = 0;
    decompose(0);
    // FOR(i, 1, n + 1) cout << par[i] << newl;
    cin >> q;
    while(q--) {
        cin >> type >> a;
        if(type) {
            cout << query(a) << newl;
        } else {
            col[a] ^= 1;
            update(a);
        }
    }
}