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
ll modexp(ll a, ll b, ll p) {
    ll ret = 1;
    for(;b;b>>=1) {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
    }
    return ret;
}
ll invmod(int a, int p) {
    return modexp(a, p-2, p);
}
int main() {
    SYNC
    int a, b, p; ll x, ans = 0, cur = 1;
    cin >> a >> b >> p >> x;
    FOR(i, 1, p) {
        cur = cur * a % p;
        int B = b * invmod(cur, p) % p;
        B = (i - B + p) % p;
        ll r = floor((floor ((x-i) / (long double)(p-1)) - B) / ((long double)p)) ;
        ll l = ceil((ceil ((1-i) / (long double)(p-1)) - B) / ((long double)p)) ;
        ans += max(0LL, r-l+1);
    }
    cout << ans;
}