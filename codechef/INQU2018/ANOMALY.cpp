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
const int N = 1e5 + 5, K = 3e3 + 3;
int n, l; string p, s, r;
V<V<int>> dwn(N, V<int>(K, 0)), up(N, V<int>(K, 0));
V<V<int>> g(N);
int mul(int a, int b) {return a * 1LL * b % mod;}
int add(int a, int b) {return (a + b) % mod;}
ll ans = 0;
int dfs(int u, int par=0) {
    int dep = 1;
    if(s[u-1] == p.back()) dwn[u][1] = 1;
    if(s[u-1] == p.front()) up[u][1] = 1;
    for(int v : g[u]) {
        if(v == par) continue;
        dep = max(dep, 1+dfs(v, u));
        for(int i = 2; i <= min(l,dep+1); i++) {
            if(s[u-1] == p[l-i]) {
                dwn[u][i] += dwn[v][i-1];
            }
            if(s[u-1] == p[i-1]) {
                up[u][i] += up[v][i-1];
            }
        }
    }
    ans += dwn[u][l] + up[u][l];
    for(int v : g[u]) {
        if(v == par) continue;
        for(int i = 2; i < min(l, dep+1); i++) {
            if(s[u-1] == p[l-i]) {
                ans += dwn[v][i-1] * 1LL * (up[u][l-i+1] - up[v][l-i]);    
            }
        }
    }
    return dep;
}
int main() {
    SYNC
    cin >> n >> s >> p;
    l = p.length();
    if(l == 1) {
        cout << count(s.begin(), s.end(), p[0]) << endl;
        return 0;
    }
    FOR0(i, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << ans;
}