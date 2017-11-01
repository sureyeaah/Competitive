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
const int N = 20005;
int n, m, num[N], low[N], cnt, scc, outdeg[N], indeg[N], comp[N];
bitset<N> vis;
vvi g(N);
vi s;
void dfs(int u) {
    low[u] = num[u] = ++cnt;
    s.push_back(u);
    vis[u] = 1;
    for(int v : g[u]) {
        if(!num[v])
            dfs(v);
        if(vis[v])
            low[u] = min(low[u], low[v]);
    }
    if(num[u] == low[u]) {
        comp[u] = ++scc;
        while(1) {
            int v = s.back(); s.pop_back(); vis[v] = 0;
            if(v == u) break;
            comp[v] = comp[u];
        }
    }
}
void check(int u) {
    for(int v : g[u]) {
        if(comp[v] != comp[u]) {
            outdeg[comp[u]] = 1;
            indeg[comp[v]] = 1;
        }
    }
}
int main() {
    SYNC
    int x, y, t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        FOR0(i, n+1) g[i].clear();
        FOR0(i, m) {
            cin >> x >> y;
            g[x].pb(y);
        }
        memset(num, 0, sizeof num);
        memset(indeg, 0, sizeof indeg);
        memset(outdeg, 0, sizeof outdeg);
        vis.reset();
        cnt = scc = 0;
        FOR(i,1,n+1) {
            if(!num[i]) dfs(i);
        }
        FOR(i,1,n+1) check(i);
        int i = count(indeg + 1, indeg + scc + 1, 0);
        int o = count(outdeg + 1, outdeg + scc + 1, 0);
        cout << (scc == 1 ? 0: max(i, o)) << newl;
    }
}