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
int n, m; const int N = 105;
V<V<int>> g(N);
int a[N];
ll dp[N];
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    a[0] = 0; a[n+1] = n + 2;
    FOR(i, 1, n + 1) {
        int l = i-1, r = 0;
        for(int j : g[i]) {
            if(j < i) l--;
            else r++;
        }
        a[i] = l + r + 1;
        cerr << a[i] << " ";
    }
    n += 2;
    dp[0] = 1;
    FOR(i, 0, n) {
        int mx = -1;
        FORD(j, 0, i) {
            if(a[j] < a[i]) {
                if(a[j] > mx) {
                    dp[i] += dp[j];
                    mx = a[j];
                }
            }
        }
    }
    cout << dp[n-1];
}