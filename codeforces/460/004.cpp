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
const int N = 3e5 + 5;
char c[N];
int n, m, vis[N], ans = 0, val[N][26] = {};
set<P<int,int>> s;
V<int> vec;
V<V<int>> g(N);
void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v] == 1) {
            ans = -1;
            return;
        }
        if(!vis[v]) dfs(v);
    }
    vec.pb(u);
    vis[u] = 2;
}
int main() {
    SYNC
    int x, y;
    cin >> n >> m;
    FOR0(i, n) cin >> c[i+1];
    FOR0(i, m) {
        cin >> x >> y;
        if(s.find(mp(x, y)) == s.end()) {
            s.insert(mp(x, y));
            g[x].pb(y);
        }
        if(x == y) {
            cout << -1; return 0;
        }
    }
    FOR(i, 1, n + 1) {
        if(!vis[i]) dfs(i);
    }
    if(ans == -1) {
        cout << -1; return 0;
    }
    for(int u : vec) {
        for(int v : g[u]) {
            FOR0(i, 26) {
                val[u][i] = max(val[u][i], val[v][i]);
            }
        }
        val[u][c[u] - 'a']++;
        ans = max(ans, val[u][c[u] - 'a']);
        // DEBUG(u); DEBUG(ans);
    }
    cout << ans;
}