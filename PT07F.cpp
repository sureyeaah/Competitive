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
#define N 10005
int t, n, dp1[N], dp2[N], par[N], cnt, path[N][3];
vvi g(N), out(N);
bitset<N> vis;
void dfs(int u, int prev) {
    par[u] = prev;
    dp1[u] = dp2[u] = 0;
    priority_queue<ii> pq;
    for(int v : g[u]) {
        if(v == prev) continue;
        dfs(v, u);
        dp1[u] += min(dp1[v], dp2[v]);
        if(dp1[v] <= dp2[v]) path[u][0] = v;
        pq.push(mp(dp1[v] - min(dp1[v], dp2[v]), v)); 
        if(pq.size() > 2) pq.pop();
    }
    dp1[u] += path[u][0] == -1;
    if(pq.size() == 2) {
        dp2[u] = -1;
        int tmp = 0;
        while(!pq.empty()) {dp2[u] += pq.top().ff; path[u][++tmp] = pq.top().ss; pq.pop(); }
        dp2[u] += dp1[u];
    } else dp2[u] = (pq.size() == 1) ? dp1[u]: 1;
}
void add(int u, int j) {
    int v = u;
    while(path[v][j] != -1) {
        v=path[v][j];
        vis[v] = 1;
        j = 0;
        out[cnt].pb(v);
    }
}
void gen(int u, int prev) {
    if(!vis[u]) {
        if(dp1[u] <= dp2[u]) {
            add(u,0);
            out[cnt].pb(u);
        } else {
            add(u,1);
            reverse(out[cnt].begin(), out[cnt].end());
            out[cnt].pb(u);
            add(u,2);
        }
        cnt++;
        vis[u] = 1;
    }
    for(int v : g[u]) if(v != prev) gen(v, u);
}
int main() {
    SYNC
    int u, v;
    cin >> t;
    while(t--) {
        cin >> n;
        vis.reset();
        FOR0(i, n+1) g[i].clear();
        FOR0(i, n+1) out[i].clear();
        memset(path, -1, sizeof path);
        cnt = 0;
        FOR0(i, n-1) {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1, 0);
        gen(1,0);
        cout << cnt << "\n";
        FOR0(i, cnt) {
            for(int v : out[i]) cout << v << " ";
            cout << "\n";
        }
    }
}