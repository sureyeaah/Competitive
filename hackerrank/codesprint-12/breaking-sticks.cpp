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
const int N = 1e6 + 5;
bitset<N> bs;
vi primes;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    for(int i = 2; i < N; i++) {
        if(!bs[i]) continue;
        primes.pb(i);
        for(int j = i; j < N; j+=i) {
            bs[j] = 0;
        }
    }
}
ll solve(ll a) {
    if(a==1) return 1;
    vector<ll> f;
    for(int p : primes) {
        while(a % p == 0) {
            a /= p;
            f.pb(p);
        }
    }
    if(a > 1) f.pb(a);
    ll cur = 1;
    for(ll& c : f) {
        cur = 1 + cur*c;
    }
    return cur;
}
int main() {
    SYNC
    sieve();
    int n; ll a;
    cin >> n;
    ll ans = 0;
    while(n--) {
        cin >> a;
        ans += solve(a);
    }
    cout << ans;
}