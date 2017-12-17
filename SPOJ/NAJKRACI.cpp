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
const int N = 1505, M = 5005;
int n, m, d[M], v[M], w[M], ans[M], out[M], in[M];
bitset<M> exist, vis;
vvi g(N);
vi order;
void dfs(int u) {
    vis[u] = 1;
    for(int e : g[u]) {
        if(exist[e] && !vis[v[e]]) {
            dfs(v[e]);
        }
    }
    order.pb(u);
}
void solve(int st) {
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, st});
    memset(d, 63, sizeof d);
    d[st] = 0;
    while(!pq.empty()) {
        int u = pq.top().ss, dist = pq.top().ff; pq.pop();
        if(dist > d[u]) continue;
        for(int e : g[u]) {
            if(d[v[e]] > d[u] + w[e]) {
                pq.push(mp((d[v[e]] = d[u] + w[e]), v[e]));
            }
        }
    }
    exist.reset(); vis.reset();
    order.clear();
    memset(out, 0, sizeof out);
    memset(in, 0, sizeof in);
    FOR(i, 1, n + 1) {
        for(int e : g[i]) {
            if(d[v[e]] == d[i] + w[e]) exist[e] = 1;
        }
    }
    dfs(st);
    for(int u : order) {
        // int leaf = 1;
        out[u] = 1;
        for(int e : g[u]) {
            if(exist[e]) {
                out[u] = (out[u] + out[v[e]]) % mod;
                // leaf = 0;
            }
        }
        // if(leaf) out[u] = 1;
    }
    reverse(order.begin(), order.end());
    for(int u : order) {
        if(u == st) in[u] = 1;
        for(int e : g[u]) {
            if(exist[e]) {
                in[v[e]] = (in[v[e]] + in[u]) % mod;
            }
        }
    }
    for(int u : order) {
        for(int e : g[u]) {
            if(exist[e]) {
                ans[e] = (ans[e] + in[u] * 1LL * out[v[e]]) % mod;
            }
        }
    }
    // FOR(i, 1, n + 1) DEBUG(in[i]);
    // FOR(i, 1, n + 1) DEBUG(out[i]);
    // FOR(i, 1, m + 1) DEBUG(ans[i]);
}
int main() {
    SYNC
    cin >> n >> m;
    order.reserve(n + 1);
    int o, d, l;
    FOR(i, 1, m + 1) {
        cin >> o >> d >> l;
        g[o].pb(i);
        v[i] = d; w[i] = l;
    }
    // solve(5);
    FOR(i, 1, n + 1) {
        solve(i);
    }
    FOR(i, 1, m + 1) cout << ans[i] << newl;
}