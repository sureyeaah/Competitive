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
const int N = 1e6 + 6;
int n;
ll fac[N], ifac[N];
ll ch(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fac[n] * 1LL * (ifac[r] * 1LL * ifac[n-r] % mod) % mod;
}
int modexp(ll a, int b, ll p) {
    ll ret = 1;
    for(; b; b>>=1) {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
    }
    return ret;
}
int main() {
    SYNC
    fac[0] = ifac[0] = 1;
    for(int i = 1; i<N; i++) fac[i] = fac[i-1] * 1LL * i % mod;
    for(int i = 1; i<N; i++) ifac[i] = modexp(fac[i], mod-2, mod);
    cin >> n;
    ll ans = 0, cur = 0, pre = 0;
    for(int i = 1; i < n; i++) {
        cur = ch(i-1, n-i-1) * fac[i] % mod;
        cur = cur * fac[n-i-1] % mod;
        (ans += i * (cur-pre) % mod) %= mod;
        pre = cur;
    }
    if(ans<0) ans += mod;
    cout << ans;
}
