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
const int N = 1000005;
bitset<N> p;
vector<int> primes, fac(N, 0);
void sieve() {
    p.set(); p[0] = p[1] = 0;
    for(ll i = 2; i < N; i++) {
        if(!p[i]) continue;
        // primes.pb(i);
        for(ll j = i; j < N; j+=i) {
            if(j != i) p[j] = 0;
            fac[j] = i;
        }
    }
}
int main() {
    SYNC
    int x, l; cin >> x;
    int ans = x; l = x;
    sieve();
    FORD(i, x-fac[x]+1, x + 1) {
        if(!p[i]) {
            ans = min(ans, i - fac[i] + 1);
        }
    }
    cout << ans;
}