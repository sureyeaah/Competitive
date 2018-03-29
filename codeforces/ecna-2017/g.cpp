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
const int N = 105, L = 50;
int n, m, a[N], dp[N][L];
V<int> c;
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, n) cin >> a[i];
    while(m) {
        c.pb(m);
        m = 2*m / 3;
    }
    c.pb(0);
    m = SZ(c);
    int ans = 0;
    FORD(i, 0, n) {
        FOR0(j, m) {
            dp[i][j] = max({
                        min(a[i], c[j]) + dp[i+1][j+1],
                        (j-1>=0?dp[i+1][j-1]:0),
                        dp[i+2][0] });
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}