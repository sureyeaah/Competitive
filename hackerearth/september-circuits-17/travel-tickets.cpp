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
#define N 300005
#define LOG 22
struct node {
    ll init, change;
    node(ll x, ll y): init(x), change(y){};
    node(): init(0), change(0){};
};
node add(node l, node r, ll val) {
    ll mid = l.init + l.change + val;
    ll newChange = l.change + val + r.change;
    ll newInit = mid >= r.init ? l.init: l.init + r.init - mid;
    return node(newInit, newChange);
}

int n, parent[N], parentEdge[N], depth[N], a[N];
vvi graph(N);
vii edges;
void dfs(int u) {
    for(int e : graph[u]) {
        int v = edges[e].ff ^ u;
        if(v == parent[u]) continue;
        parent[v] = u;
        parentEdge[v] = edges[e].ss;
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}
int P[N][LOG];
node up[N][LOG], down[N][LOG];
void lcaprocess() {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 0; 1 << j < N; j++)
            P[i][j] = -1;
    for (i = 2; i <= n; i++) {
        P[i][0] = parent[i];
        node na = node(a[i], -a[i]), npar = node(a[parent[i]], -a[parent[i]]);
        up[i][0] = add(na, npar, parentEdge[i]);
        down[i][0] = add(npar, na, parentEdge[i]);
    }
    for (j = 1; 1 << j <= n; j++)
        for (i = 1; i <= n; i++)
            if(P[i][j - 1] != -1) {
                int mid = P[i][j - 1];
                P[i][j] = P[mid][j - 1];
                up[i][j] = add(up[i][j-1], up[mid][j-1], a[mid]);
                down[i][j] = add(down[mid][j-1], down[i][j-1], a[mid]);
            }
}
ll query(int u, int v) {
    int swaps = 0, log, i;
    node l, r;
    if(depth[u] < depth[v]) {
        swap(u, v);
        swaps = 1;
    }
    for(log = 1; 1 << log <= depth[u]; log++);
    log--;
    l = node(a[u], -a[u]);
    r = node(a[v], -a[v]);
    for(i = log; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            if(swaps) l = add(down[u][i], l, a[u]);
            else l = add(l, up[u][i], a[u]);
            u = P[u][i];
        }
    }
    if(swaps) {
        swap(u, v);
        swap(l, r);
    }
    if (u == v) {
        return add(l, r, a[u]).init;
    }
    for(i = log; i >= 0; i--) {
        if(P[u][i] != -1 && P[u][i] != P[v][i]) {
            l = add(l, up[u][i], a[u]);
            r = add(down[v][i], r, a[v]);
            u = P[u][i]; v = P[v][i];
        }
    }
    return add(add(l, up[u][0], a[u]), add(down[v][0], r, a[v]), a[parent[u]]).init;
}
int main() {
    int m, x, y, c;
    cin >> n >> m;
    FOR(i,1,n+1) {
        cin >> a[i];
    }
    FOR(i,1,n) {
        cin >> x >> y >> c;
        edges.pb(mp(x^y, c));
        graph[x].pb(i-1);
        graph[y].pb(i-1);
    }
    memset(P, -1, sizeof P);
    memset(parent, -1, sizeof parent);
    parent[1] = -1;
    depth[1] = 0;
    dfs(1);
    lcaprocess();
    while(m--) {
        cin >> x >> y;
        cout << query(x, y) << endl;
    }
}