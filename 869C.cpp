#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (998244353LL)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 10000
int a, b, c;
ll fac[N], invfac[N];
int modexp(ll a, ll b, ll p) {
    ll res = 1;
    while(b) {
        if(b & 1)
            res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}
ll inv(ll x) {
    return modexp(x, mod-2, mod);
}
ll choose(ll a, ll b) {
    return (((fac[a] * invfac[b]) % mod ) * invfac[a - b]) % mod;
}
ll val(ll a, ll b) {
    if(a < b) swap(a, b);
    ll ans = 0;
    FOR0(i, b+1) {
        ll x = (choose(a, i) * choose(b, i)) % mod;
        ans = (ans + (x * fac[i])) % mod;
    }
    return ans;
}
int main() {
    SYNC
    fac[0] = 1;
    FOR(i,1,N) fac[i] = (fac[i-1] * i) % mod;
    FOR0(i,N) invfac[i] = inv(fac[i]);
    cin >> a >> b >> c;
    ll ans = 1;
    ans = (ans * val(a, b)) % mod;
    ans = (ans * val(b, c)) % mod;
    ans = (ans * val(c, a)) % mod;
    cout << ans;
}