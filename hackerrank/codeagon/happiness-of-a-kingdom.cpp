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
#define N 500005
int n, m, edges[1000005], root, childCount, num[N] = {}, low[N] = {}, par[N] = {}, cnt = 0, bridge[1000005];
vvi g(N);
bitset<N> vis;
vi mem;
int dfs(int u) {
    vis[u] = 1;
    mem.pb(u);
    int curSz = 1;
    low[u] = num[u] = ++cnt;
    for(int e : g[u]) {
        if(edges[e] == -1) continue;
        int v = edges[e] ^ u;
        if(!num[v]) {
            par[v] = u;
            if(u == root) {
                childCount++;
            }
            curSz += dfs(v);
            if(low[v] > num[u]) bridge[e] = 1;
            low[u] = min(low[v], low[u]);
        } else if (v != par[u])
            low[u] = min(low[u], num[v]);
    }
    return curSz;
}
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, m) {
        int u, v; 
        cin >> u >> v;
        g[u].pb(i);
        g[v].pb(i);
        edges[i] = u ^ v;
    }
    int done = 0;
    ll ans;
    while(done < 2) {
        memset(low, 0, sizeof low);
        memset(num, 0, sizeof num);
        memset(bridge, 0, sizeof bridge);
        memset(par, 0, sizeof par);
        cnt = 0;
        vis.reset();
        vii sizes;
        ans = 0;
        FOR(i,1,n+1) {
            if(!vis[i]) {
                root = i;
                childCount = 0;
                mem.clear();
                int curSz = dfs(i);
                ans += 1LL * curSz * (curSz - 1);
                if(SZ(g[i]) == 1)
                    bridge[g[i][0]] = 1;
                
                for(int u : mem) {
                    int totEdges = 0, selected = -1;
                    for(int e : g[u]) {
                        if(edges[e] != -1) {
                            selected = e;
                            totEdges++;
                        }
                    }
                    if(totEdges == 1 && selected != -1) sizes.pb(mp(curSz, selected));
                }
            }
        }
        int found = 0;
        FOR(i,1,n+1) {
            for(int e : g[i]) {
                if(edges[e] != -1 && !bridge[e]) {
                    edges[e] = -1;
                    found = 1; i = INF; break;
                }
            }
        }
        if(!found) {
            int selected = -1, best = INF;
            for(ii cur : sizes) {
                if(cur.ff < best) {
                    selected = cur.ss;
                    best = cur.ff;
                }
            }
            edges[selected] = -1;
            ans -= (best - 1) << 1;
        }
        done++;
    }
    cout << ans << endl;
}