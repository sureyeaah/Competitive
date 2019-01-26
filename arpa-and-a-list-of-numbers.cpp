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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 1000
bitset<N*N+5> bs;
bitset<N*N+5> cnt;
vi primes;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    FOR(i,2,N) {
        if(!bs[i]) continue;
        primes.pb(i);
        for(int j = i*i; j < N*N+5; j+=i) {
            bs[j] = 0;
        }
    }
}
int main() {
    SYNC
    sieve();
    int a[500005], n, x, y;
    cin >> n >> x >> y;
    FOR0(i, n) {
        cin >> a[i];
    }
    ll ans = 1LL*n*x;
    for(int p : primes) {
        ll cur = 0;
        FOR0(i, n) {
            int mod = a[i] % p;
            if(!mod) {
                while(a[i] % p == 0) a[i] /= p;
                continue;
            }
            cur += min(1LL*x, 1LL*y*(p - mod));
        }
        ans = min(ans, cur);
    }
    FOR0(i, n) cnt[a[i]] = 1;
    FOR(p,1001, N*N+5) {
        if(!bs[p] || !cnt[p]) continue;
        ll cur = 0;
        FOR0(i, n) {
            int mod = a[i] % p;
            cur += min(1LL*x, (mod ? 1LL*y*(p - mod): 0));
        }
        ans = min(ans, cur);
    }
    cout << ans;
}