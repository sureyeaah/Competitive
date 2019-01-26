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
int n, parEdge[N], col[N], uv[N], w[N], dist[N][20], q, sz[N], par[N], lvl[N] = {}, ans[N], a, b, c; char x;
vvi g(N);
struct cmp {
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
};
inline void ERASE(auto& s, int x) {
    s.erase(s.find(x));
}
multiset<int, cmp> best[N], sub[N], all;
void dfs(int u, int pre) {
    sz[u] = 1;
    for(int e : g[u]) {
        int v= u^uv[e];
        if(v != pre && !lvl[v]) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
int centroid(int u, int pre, int tot) {
    for(int e : g[u]) {
        int v= u^uv[e];
        if(v != pre && !lvl[v] && sz[v] > tot/2)
            return centroid(v, u, tot);
    }
    return u;
}
void dfs1(int u, int pre, int head, int ind) {
    sub[ind].insert(dist[u][lvl[head]]);
    for(int e : g[u]) {
        int v = uv[e]^u;
        if(v != pre && !lvl[v]) {
            dist[v][lvl[head]] = dist[u][lvl[head]] + w[e];
            dfs1(v, u, head, ind);
        }
    }
}
void getAns(int u) {
    int i = 0, a[2] = {-inf, -inf};
    for(auto& cur: best[u]) {
        a[i++] = cur;
        if(i==2) break;
    }
    ans[u] = a[1] > -inf ? a[1] + a[0]: -inf;
    if(col[u]) {
        ans[u] = max(ans[u], a[0]);
    }
    all.insert(ans[u]);
}
void decompose(int u) {
    if(!u) {
        dfs(1, 0); u = centroid(1, 0, sz[1]);
        par[u] = 0;
    }
    lvl[u] = lvl[par[u]] + 1;
    best[u].insert(0);
    for(int e : g[u]) {
        int v= u^uv[e];
        if(!lvl[v]) {
            dist[v][lvl[u]] = w[e];
            dfs1(v, u, u, e);
            dfs(v, 0); v = centroid(v, 0 ,sz[v]);
            parEdge[v] = e; par[v] = u;
            decompose(v);
            best[u].insert(*(sub[e].begin()));
        }
    }
    getAns(u);
}
void add(int u) {
    best[u].insert(0);
    int cur = u;
    ERASE(all, ans[u]);
    getAns(u);
    while(par[cur]) {
        if(!sub[parEdge[cur]].empty())
            ERASE(best[par[cur]], *(sub[parEdge[cur]].begin()));
        sub[parEdge[cur]].insert(dist[u][lvl[cur]-1]);
        best[par[cur]].insert(*(sub[parEdge[cur]].begin()));
        cur = par[cur];
        ERASE(all, ans[cur]);
        getAns(cur);
    }
}
void rem(int u) {
    ERASE(best[u],0);
    int cur = u;
    ERASE(all, ans[u]);
    getAns(u);
    while(par[cur]) {
        ERASE(best[par[cur]], *(sub[parEdge[cur]].begin()));
        ERASE(sub[parEdge[cur]], dist[u][lvl[cur]-1]);
        if(!sub[parEdge[cur]].empty()) best[par[cur]].insert(*(sub[parEdge[cur]].begin()));
        cur = par[cur];
        ERASE(all, ans[cur]);
        getAns(cur);
    }
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n - 1) {
        cin >> a >> b >> w[i];
        uv[i] = a ^ b;
        g[a].pb(i);
        g[b].pb(i);   
    }
    fill(col, col + n + 1, 1);
    decompose(0);
    cin >> q;
    while(q--) {
        cin >> x;
        if(x == 'A') {
            int ans = *(all.begin());
            if(ans > -inf) {
                cout << ans << newl;
            } else cout << "They have disappeared." << newl;
        } else {
            cin >> a;
            col[a] ^= 1;
            if(col[a]) add(a); else rem(a);
        }
    }
}