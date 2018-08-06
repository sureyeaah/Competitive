// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 1e6 + 6;
V<V<int>> g(N);
int dep[N], ans[N];
void dfs2(int u, int par = 0) {
    if(par) g[u].erase(remove(g[u].begin(), g[u].end(), par), g[u].end());
    dep[u] = 1;
    for(int v : g[u]) {
        dfs2(v, u);
        dep[u] = max(dep[u], dep[v] + 1);
    }
}
void dfs(int u, V<int>& vec) {
    if((int)g[u].size() == 0) {
        ans[u] = 0;
        vec[0] = 1;
        return;
    }
    if((int)g[u].size() == 1) {
        dfs(g[u][0], vec);
        ans[u] = ans[g[u][0]];
        vec.push_back(1);
        if(vec[ans[u]] == 1) ans[u] = dep[u] - 1;
        return;
    }
    V<int> nxt(dep[u], 0);
    for(int v : g[u]) {
        dfs(v, vec);
        FOR0(i, (int)nxt.size()) {
            nxt[i + dep[u]-dep[v]-1] += vec[i];
        }
        vec[dep[u]-1]++;
    }
    vec.clear();
    for(int x : nxt) vec.pb(x);
    ans[u] = dep[u] - 1;
    FORD(i, 0, (int)vec.size()) {
        if(vec[i] > vec[ans[u]]) ans[u] = i;
    }
}
int main() {
    SYNC
    int n,x,y;
    cin >> n;
    FOR0(i, n-1) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs2(1);
    V<int> vec(n);
    dfs(1, vec);
    FOR(i, 1, n + 1) cout << ans[i] << endl;
}