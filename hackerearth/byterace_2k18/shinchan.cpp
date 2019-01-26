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
const int N = 1e5 + 5, LOGN = 19;
V<V<int>> g(N);
int dep[N], a[N], b[N], par[N] = {};
void dfs(int u, int pre=0) {
    dep[u] = pre ? dep[pre]+1: 0;
    par[u] = pre;
    for(int v : g[u] ) {
        if(v == pre) continue;
        a[v] += a[u];
        b[v] += b[u];
        dfs(v, u);
    }
}

int q, n, G, k;
int main() {
    SYNC
    cin >> q;
    while(q--) {
        int u, v;
        cin >> n;
        FOR(i, 1, n + 1) {
            g[i].clear();
            dep[i] = 0;
            par[i] = 0;
            a[i] = 0; b[i] = 0;
        }
        V<unordered_set<int>> e(N);
        FOR0(i, n-1) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            e[u].insert(v); e[v].insert(u);
        }
        dfs(1);
        cin >> G >> k;
        int a1 = 0;
        FOR0(i, G) {
            cin >> u >> v;
            if(e[u].find(v) == e[u].end()) continue;
            if(par[v] == u) {
                a[v]++;
                a1++;
            } else {
                b[u]++;
            }
        }
        dfs(1);
        int ans = 0;
        FOR(i,1,n+1) {
            int val = a1 - a[i] + b[i];
            if(val >= k) ans++;
        }
        int x = __gcd(ans, n); ans /= x, n /= x;
        cout << ans << "/" << n << endl;
    }
}