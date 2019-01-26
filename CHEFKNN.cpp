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
const int inf = 1e9, mod = 163577857;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 2500;
int dp[N][N];
int main() {
    SYNC
    int t, n, k;
    cin >> t;
    FOR0(i, N) dp[i][0] = 1;
    FOR0(i, N) dp[1][i] = i+1;
    FOR(i, 2, N) {
        FOR(j, 1, N) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] % mod;
            dp[i][j] = (dp[i][j] + ((i-1) * 1LL * dp[i-1][j-1])) % mod;
        }
    }
    while(t--) {
        cin >> n >> k;
        int ans = (dp[n][k]-dp[n][k-1] + mod) % mod;
        cout << ans << endl;
    }
}