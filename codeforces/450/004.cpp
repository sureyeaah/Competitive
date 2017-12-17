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
#define mod (1000000000 + 7)
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
int x, y;
unordered_map<int, int> m;
int modexp(ll a, int b, int p) {
    ll ret = 1;
    for(;b;b>>=1) {
        if(b&1)
            ret = ret * a % p;
        a= a * a % p;
    }
    return ret;
}
int main() {
    SYNC
    cin >> x >> y;
    if(y % x) {
        cout << 0; return 0;
    }
    y /= x;
    vi fac;
    for(int i = 1; i * i <= y; i++) {
        if(y % i == 0) fac.pb(i);
    }
    FORD(i, 0, SZ(fac)) if(fac[i]*fac[i] != y) fac.pb(y/fac[i]);
    int ans = 0;
    for(int x : fac) {
        if(x==1) {
            m[1] = 1;
        } else {
            int fo = 0;
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) {
                    fo = 1;
                    m[x] = m[x/i] * -1 * (x/i % i != 0);
                    break;
                }
            }
            if(!fo) {
                m[x] = -1;
            }
        }
        // if(m[x]) DEBUG(m[x]);
        ans = (ans + m[x] * modexp(2,y/x-1,mod)) % mod;
    }
    cout << (ans+mod) % mod;
}