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
const int inf = 1e9, mod = 1e6 + 3;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
ll n, k;
ll modexp(ll a, ll b=mod-2, ll p=mod) {
    ll ret = 1;
    for(;b;b>>=1) {
        if(b&1) ret = ret * a % p;
        a = a*a % p;
    }
    return ret;
}
int main() {
    SYNC
    cin >> n >> k;
    if(n < 63 && (1LL << n) < k) {
        cout << "1 1";
        return 0;
    }
    int a, days = modexp(2, n), b = modexp(days, k);
    a = 1;
    FOR0(i, min(k, 1LL*mod)) a = a * 1LL * (days - i) % mod;
    ll c = days;
    FOR(i, 1, 61) c = c * modexp(2, (k-1)/(1LL << i)) % mod;
    cerr << a << " " << b << " " << c << " " << days;
    c = modexp(c); a = a * c % mod; b = b * c % mod;
    a = (b-a) % mod; if(a < 0) a += mod;
    cout << a << " " << b;
}