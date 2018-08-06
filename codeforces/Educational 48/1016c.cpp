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
const int N = 3e5 + 5; 
int n; ll a[2][N], dp[2][N], dp2[2][N];
int main() {
    SYNC
    cin >> n;
    FOR0(i, 2) FOR0(j, n) cin >> a[i][j];
    ll cur = 0, ans = 0;
    FORD(i, 0, N) {
        dp[0][i] = dp[0][i+1] + cur + a[1][i] * (2*(n-i) - 1);
        dp[1][i] = dp[1][i+1] + cur + a[0][i] * (2*(n-i) - 1);
        cur += a[0][i] + a[1][i];
    }
    FORD(i, 0, N) {
        dp2[0][i] = dp2[0][i+1] + a[0][i];
        dp2[1][i] = dp2[1][i+1] + a[1][i];
    }
    cur = 0;
    FOR0(i, n) {
        int k = i & 1;
        ll val = cur + dp[k][i] + (dp2[k][i+1] + dp2[k^1][i]) * i * 2;
        ans = max(val, ans);
        cur += a[k^1][i] * (i*2 + 1) + a[k^1][i+1] * (i*2 + 2);
    }
    cout << ans;
}