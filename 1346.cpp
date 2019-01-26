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
int a, b, n, x[N], dp[N][2];
int main() {
    SYNC
    cin >> a >> b; n = b - a + 1;
    FOR0(i, n) cin >> x[i]; 
    dp[0][0] = dp[0][1] = 1;
    FOR(i, 1, n) {
        if(x[i] == x[i-1]) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            continue;
        }
        int k = x[i] > x[i-1];
        dp[i][k] = min(dp[i-1][k], dp[i-1][k^1] + 1);
        dp[i][k^1] = min(dp[i-1][k] + 1, dp[i-1][k^1] + 1);
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
}
