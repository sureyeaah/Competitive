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
const int N = 2e5 + 5;
const int M = 1e6 + 5;
const int LOGN = 19;
vvi g(N);
int n, q, a[N], val[N], cnt = 0, cntft[N] = {}, ft[N] = {}, st[N], nd[N], occur[M] = {};
int table[N][LOGN], depth[N] = {};
struct node {
    int s, e, v, p;
    node() : s(0), e(0), v(0), p(0) {};
    node(int s, int e, int v, int p) : s(s), e(e), v(v), p(p) {};
    bool operator < (node other) {
        return e == other.e ? v > other.v: e < other.e;
    }
};
vector<node> vec;
void dfs(int u, int prev) {
    st[u] = ++cnt;
    table[u][0] = prev;
    vec.pb(node(st[u], st[u], a[u], -1));
    for (int v : g[u]) {
        if(v == prev) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
    nd[u] = ++cnt;
    vec.pb(node(st[u], nd[u], 0, u));
}
void update(int i, int val) {
    for(;i<=cnt;i+=i&-i)
        cntft[i] += val;
}
int query(int i) {
    int ret = 0;
    for(;i;i-=i&-i)
        ret += cntft[i];
    return ret;
}
void pathupdate(int i, int val) {
    for(;i <= cnt; i += i&-i)
        ft[i] ^= val;
}
int pathquery(int i) {
    int ans = 0;
    for(;i;i-=i&-i)
        ans ^= ft[i];
    return ans;
}
int lca(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOGN; i++)
        if((diff>>i) & 1)
            u = table[u][i];
    if(v == u)
        return v;
    FORD(i, 0, LOGN) {
        if(table[u][i] != table[v][i]) {
            u = table[u][i];
            v = table[v][i];
        }
    }
    return table[u][0];
}
int main() {
    SYNC
    int u, v;
    cin >> n >> q;
    FOR(i,1,n+1) cin >> a[i];
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(table, -1, sizeof table);
    dfs(1, -1);
    sort(vec.begin(), vec.end());
    for(auto& cur : vec) {
        if(cur.v == 0)
            val[cur.p] = query(cur.e) - query(cur.s - 1);
        else {
            if(occur[cur.v] != 0) update(occur[cur.v], -1);
            update(cur.s, 1);
            occur[cur.v] = cur.s;
        }
    }
    // FOR(i,1,n+1) cout << val[i] << newl;
    FOR(i,1,n+1) {
        pathupdate(st[i],val[i]);
        pathupdate(nd[i],val[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; 1 << j <= n; j++) {
            if(table[i][j-1] != -1)
                table[i][j] = table[table[i][j-1]][j-1];
        }
    }
    while(q--) {
        cin >> u >> v;
        cout << (pathquery(st[u]) ^ pathquery(st[v]) ^ val[lca(u,v)] ?"First":"Second") << newl;
    }
}