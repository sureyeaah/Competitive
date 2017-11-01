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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 100005
int n, m, c[N], num[N] = {}, low[N], cnt = 0, comps= 0, wt[N];
vvi g(N), dag(N);
stack<int> s;
bitset<N> vis, root;
int gcd(int a, int b) {
    return b ? gcd(b, a % b): a;
}
int scc(int u) {
    vis[u] = 1;
    num[u] = low[u] = ++cnt;
    s.push(u);
    for(int v : g[u]) {
        if(!num[v])
            scc(v);
        if(vis[v])
            low[u] = min(low[v], low[u]);
    }
    if(low[u] == num[u]) {
        int val = c[u];
        while(1) {
            int v = s.top(); s.pop();
            comp[v] = comps;
            vis[v] = 0;
            cur.pb(v);
            if(v == u) break;
            val = gcd(val, c[v]);
        }
        wt[comp] = val;
        comps++;
    }
}
int dfs(int u) {
    if(!vis[u]) {
        vis[u] = 1;
        for(int v : g[u])
            c[u] = gcd(c[u], dfs(v));
    }
    return wt[u];
}
int main() {
    SYNC
    int u, v;
    cin >> n >> m;
    FOR0(i, n) {
        cin >> c[i];
    }
    while(m--) {
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
    }
    FOR0(i, n) {
        if(!num[i]) scc(i);
    }
    root.set();
    FOR0(i, n) {
        for(int v : g[u]) {
            root[comp[v]] = 0;
            if(comp[v] != comp[i]) dag(comp[i]).pb(comp[v]);
        }
    }
    int ans = INF;
    vis.reset();
    FOR0(i,comps) {
        if(root[i])ans = min(dfs(i), ans);
    }
    cout << ans;
}