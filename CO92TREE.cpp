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
const int N = 1e5 + 5;
int t, n, x, y, bc[N];
V<V<int>> g(N);
int dfs(int u, int pre, int minbc, int nd, int st) {
    int ret = 1;
    for(int v : g[u]) {
        if(v != pre && bc[v] >= minbc && v >= st && ((nd&v) == nd))
            ret += dfs(v, u, minbc, nd, st);
    }
    return ret;
}

ll solve(int u, int val, int rem) {
    ll ans = (val+rem) * 1LL * dfs(u, -1, bc[u], val+rem, u);
    while(val != 0) {
        ans = max(solve(u, val-(val&-val), rem), ans);
        rem += val&-val;
        val -= val&-val;
    }
    return ans;
}
int main() {
    SYNC
    cin >> t;
    FOR0(i, N) bc[i] = __builtin_popcount (i);
    while(t--) {
        cin >> n;
        FOR(i, 1, n + 1) g[i].clear();
        FOR0(i, n-1) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        ll ans = 0;
        FOR(i, 1, n + 1) {
            ans = max(ans, solve(i, i, 0));
        }
        cout << ans << endl;
    }
}