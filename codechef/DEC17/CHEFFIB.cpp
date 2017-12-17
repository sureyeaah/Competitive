// #pragma GCC optimize (3)
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
inline int add(int x, int y) {return (x + y) % mod;}
inline int mul(int x, int y) {return (x * 1LL * y) % mod;}
const int N = 3e5 + 5, LOGN=21;
int q, k, a, b, qq, type;
int fib[N] = {}, n, t, x, y;
vvi g(N); int dist[N][LOGN], lvl[N] = {}, par[N], sz[N], reach[N]={};
vii fen[N]; vii neg[N];
void dfs(int u, int pre) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v != pre && !lvl[v]) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}
void dfs1(int u, int pre, int head) {
    dist[u][lvl[head]] = pre ? dist[pre][lvl[head]] + 1: 0;
    for(int v : g[u]) {
        if(v != pre && !lvl[v]) {
            dfs1(v, u, head);
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
void decompose(int u) {
    if(!u) {
        dfs(1, 0); u = centroid(1, 0, sz[1]);
        par[u] = 0; reach[u] = n + 2;
    }
    lvl[u] = lvl[par[u]]+1;
    neg[u].resize(reach[par[u]]+2);
    fen[u].resize(reach[u] + 2);
    fill(neg[u].begin(), neg[u].end(), mp(0, 0));
    fill(fen[u].begin(), fen[u].end(), mp(0, 0));
    dfs1(u, 0, u);
    for(int v : g[u]) {
        if(lvl[v]) continue;
        dfs(v, 0); int s = sz[v];
        v = centroid(v, 0, sz[v]);
        par[v] = u; reach[v] = s + 2;
        decompose(v);
    }
}

inline void comb(ii& l, ii r) {
    l.ff = add(l.ff, r.ff);
    l.ss = add(l.ss, r.ss);
}
void upd(int i, ii val, vii& ft) {
    for(i++;i<SZ(ft);i+=i&-i) comb(ft[i], val);
}
inline ii fibn(int n, int a, int b) {
    if(!n) return mp(a, b);
    return mp(add(mul(fib[n+1], a), mul(fib[n], b)), add(mul(fib[n], a), mul(fib[n-1], b)));
}
void update() {
    int u = qq, cur = u, pre = 0;
    while(cur) {
        int d = k - dist[u][lvl[cur]];
        if(d >= 0) {
            d = min(d, reach[cur]);
            upd(0,fibn(dist[u][lvl[cur]],a, b), fen[cur]);
            upd(d+1,fibn(dist[u][lvl[cur]],-a, -b), fen[cur]);
            if(pre) {
                upd(d+1,fibn(dist[u][lvl[cur]],a, b), neg[pre]);
                upd(0,fibn(dist[u][lvl[cur]],-a, -b), neg[pre]);
            }
        }
        pre = cur; cur = par[cur];
    }
}
ii ftquery(int i, vii& ft) {
    ii ret;
    for(i++;i;i-=i&-i) {
        comb(ret, ft[i]);
    }
    return ret;
}
int query(int u) {
    int cur = u, pre = 0, ans = 0;
    while(cur) {
        int d = dist[u][lvl[cur]];
        ii f = ftquery(d, fen[cur]);
        if(pre) {
            comb(f, ftquery(d, neg[pre]));
        }
        ans = add(ans, fibn(dist[u][lvl[cur]],f.ff,f.ss).ff);
        pre = cur; cur = par[cur];
    }
    return ans<0?ans+mod:ans;
}
int main() {
    SYNC
    cin >> t;
    fib[0] = 0, fib[1] = 1;
    FOR(i, 2, N) fib[i] = add(fib[i-2], fib[i-1]);
    while(t--) {
        cin >> n >> q;
        fill(lvl, lvl + n + 1, 0);
        FOR0(i, n + 1) g[i].clear();
        FOR0(i, n-1) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        decompose(0);
        FOR0(i, q) {
            cin >> type;
            if(type == 1) {
                cin >> qq >> k >> a >> b;
                b -= a;
                update();
            }
            else {
                cin >> qq;
                cout << query(qq) << newl;
            }
        }
    }
}