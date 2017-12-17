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
int n, m, z;
const int N = 1.5e7 + 10;
bitset<N> p;
vi primes;
ll modexp(ll a, ll b) {
    ll ret = 1;
    for(;b;b>>=1) {
        if(b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}
int main() {
    SYNC
    cin >> n >> m;
    z = min(n, m) + 1;
    p.set(); p[0] = p[1] = 0;
    ll ans = 1;
    for(int i = 2; i < z; i++) {
        if(p[i]) {
            primes.pb(i);
            ll a = n, b = m, cnt = 0;
            while(a && b) {
                a /= i; b /= i;
                cnt += a * b;
            }
            ans = (ans * modexp(i, cnt)) % mod;
        }
        for(int j = 0; j < SZ(primes) && i * primes[j] < z; j++) {
            p[i * primes[j]] = 0;
            if(i % primes[j] == 0) break;
        }
    }
    cout << ans;
}