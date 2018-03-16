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
V<V<int>> g1, g2;
int modexp(int a, int b, int p) {
    int ret = 1;
    FOR0(i, b) ret = (ret*1LL*a) % p;
    return ret;
}
int dfs(int u, V<V<int>> &g, int p1, int p2, int p3) {
    if(!SZ(g[u])) return p3;
    V<int> v;
    for(int uu : g[u]) {
        v.pb(dfs(uu, g, p1, p2, p3));
    }
    sort(v.begin(), v.end());
    int h = 0;
    FOR0(i, SZ(v)) {
        h = (h + v[i]*1LL*modexp(p2, i+1, p1)) % p1;
    }
    return h;
}
int main() {
    SYNC
    int t, n, r1, r2;
    cin >> t;
    while(t--) {
        cin >> n;
        g1.clear(); g1.resize(n+1);
        g2.clear(); g2.resize(n+1);
        FOR(i, 1, n+1) {
            int p; cin >> p;
            g1[p].pb(i);
            if(!p) r1 = p;
        }
        FOR(i, 1, n+1) {
            int p; cin >> p;
            g2[p].pb(i);
            if(!p) r2 = p;
        }
        int ans = 1;
        if(dfs(r1, g1, 80046121, 56152351, 42591347) != dfs(r2, g2, 80046121, 56152351, 42591347)) ans = 0;
        if(dfs(r1, g1, 93914113, 80638039, 76095619) != dfs(r2, g2, 93914113, 80638039, 76095619)) ans = 0;
        cout << ans << endl;
    }
}