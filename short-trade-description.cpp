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
const int N = 1e2 + 5;
int q, a, m;
ll dp[N][N][N]; // m, a, last
int solve(int a, int m) {
    memset(dp, 0, sizeof dp);
    FOR0(i, a + 2) dp[0][a][i] = 1;
    FOR(i, 1, m + 1) {
        FOR(j, 0, a + 1) {
            dp[i][j][a+1] = 0;
            FORD(k, 0, a + 1) {
                dp[i][j][k] = j+k <= a ? dp[i-1][j+k][k?k+1:0]: 0;
                dp[i][j][k] += dp[i][j][k+1];
            }
        }
    }
    return dp[m][0][0];
}
int main() {
    SYNC
    cin >> q;
    while(q--) {
        cin >> a >> m;
        cout << solve(a, m) << endl;
    }
}
