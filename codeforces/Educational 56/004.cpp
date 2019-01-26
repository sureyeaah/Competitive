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
const int inf = 1e9, mod = 998244353 ;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 3e5 + 5;
int p2[N], a[N];
int n, m;
ll ans;
V<V<int>> g(N);
void dfs(int u, int &sz, int &x) {
    sz++;
    x += a[u];
    for(int v : g[u]) {
        if(a[v]==-1) {
            a[v] = !a[u];
            dfs(v, sz, x);
        } else if(a[v] == a[u]) ans = 0;
    }
}
int main() {
    SYNC
    FOR0(i, N) p2[i] = i ? (p2[i-1] *1LL* 2) % mod: 1;
    int t;
    cin>>t;
    while(t--) {
        cin >> n >> m;
        ans = 1;
        FOR(i, 1, n+1) {
            a[i] = -1;
            g[i].clear();
        }
        FOR0(i, m) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        FOR(i, 1, n + 1) {
            if(a[i] == -1) {
                int o = 0, sz = 0;
                a[i] = 0;
                dfs(i, sz, o);
                ans = (ans * ((p2[o] + 0LL + p2[sz-o]) % mod)) % mod;
            }
        }
        cout << ans << endl;
    }

}