#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll expmod(ll a, ll b, ll p) {
    ll ret = 1;
    while(b > 0) {
        if (b & 1)
            ret = (ret*a)%p;
        b >>= 1;
        a = (a*a) % p;
    }
    return ret;
}

ll recurse (ll r, ll n, ll p) {
    ll ret = 0;
    if(n & 1) {ret += expmod(r, n-1, p); n--;}
    if(n == 2) return (ret + (1 + r)) % p;
    if(n == 1) return 1;
    n >>= 1;
    ll r2 = expmod(r,2,p);
    ll ret2 = ((1 + r)%p * (recurse(r2, n, p)%p))%p;
    return (ret + ret2)%p;
}

int main() {
    int t;
    ll a, n, m;
    cin >> t;
    while(t--) {
        scanf("%lld%lld%lld", &a, &n, &m);
        ll ans = a%m;
        int len = ceil(log10((double)(a+1)));
        ll k = expmod(10, len, m);
        if (k == 1) ans *= n%m;
        else if(k!=0 && n!=1){
            ll gp = recurse (k, n, m);
            ans = (ans*gp)%m;
        }
        cout << ans << endl;

    }
}