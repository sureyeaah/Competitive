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
int h, w, n;
const int N = 2005, M = 2e5 + 5;
int dp[N], fac[M], invfac[M];
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return a * 1LL * b % mod;}
int ways(int x1, int y1, int x2, int y2) {
    int x = x2 - x1, y = y2 - y1;
    if(x < 0 || y < 0) return 0;
    return mul(fac[x + y], mul(invfac[x], invfac[y]));
}
int modexp(int a, int b = mod-2, int p = mod) {
    int ret = 1;
    for(; b; b >>= 1) {
        if(b & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}
int main() {
    SYNC
    fac[0] = 1;
    FOR(i, 1, M) fac[i] = mul(fac[i-1], i);
    FOR0(i, M) invfac[i] = modexp(fac[i]);
    int x, y;
    cin >> h >> w >> n;
    V<P<int, int>> v;
    FOR0(i, n) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back({h, w});
    sort(v.begin(), v.end());
    FOR0(i, v.size()) {
        x = v[i].first, y = v[i].second;
        dp[i] = ways(1, 1, x, y);
        FOR0(j, i) {
            int X = v[j].first, Y = v[j].second;
            dp[i] = add(dp[i], -mul(dp[j], ways(X, Y, x, y)));
        }
        dp[i] = add(dp[i], mod);
    }
    cout << dp[n] << endl;
    
}
