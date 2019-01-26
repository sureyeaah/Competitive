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
#define N 1000005
int n, a, b, x[N], type[N];
bitset<100000> bs;
vi primes;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    FOR(i,2,100000) {
        if(!bs[i]) continue;
        primes.pb(i);
        for(ll j = 1LL*i*i; j < 100000; j++) {
            bs[j] = 0;
        }
    }
}
ll solve(int x) {
    vi f;
    ll ans = 1e18;
    for(int p : primes) {
        if(p > x) break;
        if(x % p == 0) {
            f.pb(p);
            while(x % p == 0) x/= p;
        }
    }
    if(x > 1) f.pb(x);
    int st = n+1, nd = -1;
    for(int p : f) {
        FOR(i,1,n) {
            if(x[i] % p == 0) type[i] = 0;
            else if((x[i]-1) % p || (x[i]+1) % p) {
                type[i] = -1;
                st = min(st, i);
                nd = max(nd, i);
            }
            else type[i] = 1;
        }
        ll ret = 1LL*b*count(type, type + n, 1);
        if(st < n) {
            FOR(i,st,nd+1) {
                ret += a;
                type[i] = -1;
            }
            int l = st;
            while(l > 0) {
                l--;
                if(type[l] != 1) {
                    continue;
                }
                ll v = -b + 1LL*a*(st-l);
                if(v <= 0) {
                    ret += v;
                } else break;
                st = l;
            }
            l = nd;
            while(l < n) {
                l++;
                if(type[l] != 1) {
                    continue;
                }
                ll v = -b + 1LL*a*(l - nd);
                if(v <= 0) {
                    ret += v;
                } else break;
                nd = l;
            }
        } else {
            int l = 0, r = 0;
        }
        ans = min(ans, ret);
    }
    return ans;
} 
int main() {
    SYNC
    sieve();
    cin >> n >> a >> b;
    FOR0(i, n) cin >> x[i];
    ll ans = 1e18;
    ans = min(ans, solve(x[0]));
    ans = min(ans, solve(x[0]-1) + b);
    ans = min(ans, solve(x[0]+1) + b);
    reverse(x, x + n);
    ans = min(ans, solve(x[0]));
    ans = min(ans, solve(x[0]-1) + b);
    ans = min(ans, solve(x[0]+1) + b);
    cout << ans;
}