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
int n, m, p[105]; const int N = 105;
V<V<int>> g(N);
int x1;
int dfs2(int u, int d=0, int pre=-1) {
    if(d > x1) return 0;
    int x = p[u];
    for(auto v : g[u]) {
        if(v == pre) continue;
        // cerr << u << " " <<  v << " " << d << endl;
        x += dfs2(v, d+1, u);
    }
    return x;
}
int main() {
    SYNC
    cin >> n >> m;
    FOR(i, 1, n+1) {
        cin >> p[i];
    }
    FOR0(i, n-1) {
        int u, v;
         cin >> u >> v;
         g[u].push_back(v);
         g[v].push_back(u);
    }
    int lt = 0, rt = n-1, ans = n + 1;
    while(lt <= rt) {
        int mid = (lt + rt) >> 1, f = 0;
        FOR(i, 1, n + 1) {
            V<int> v1, v2;
            x1 = mid/2; 
            int s = p[i], val = s;
            for(int v: g[i]) {
                v1.push_back(dfs2(v, 1, i));
                s += v1.back();
            }
            x1 = (mid+1)/2;
            for(int v: g[i])
                v2.push_back(dfs2(v, 1, i));
            FOR0(j, v1.size()) {
                val = max(val, s-v1[j]+v2[j]);
            }
            if(val >= m) {
                ans = mid; rt = mid-1; f = 1;
                break;
            }
        }
        if(!f) lt = mid + 1;
    }
    cout << ans;
}