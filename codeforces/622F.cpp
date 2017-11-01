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
#define N 1000000001
#define K 1000005
#define mod (7+(ll)1e9)
ll expmod(ll a, ll b, ll p) {
    ll ret = 1;
    for(;b;b>>=1) {
        if(b & 1) ret = (ret * a) % p;
        a = (a*a) % mod;
    }
    return ret;
}
int main() {
    SYNC
    int n, k; cin >> n >> k;
    ll sum[K], num, ans = 0, fac[K];
    sum[0] = 0; fac[0] = 1;
    FOR(i, 1, k+2) sum[i] = (sum[i-1] + expmod(i,k,mod)) % mod;
    if(!k) ans = n;
    else if(n < k+2) {
        ans = sum[n];
    } else {
        num = 1;
        FOR0(i, k+2) num = (num*((ll)n - i)) % mod;
        FOR(i,1,k+2) fac[i] = (fac[i-1] * i) % mod;
        FOR0(i, k+2) {
            ll val = (num*expmod(n-i, mod-2, mod)) % mod;
            val = (val * expmod((fac[i]*fac[k+1-i]) % mod, mod-2, mod)) % mod;
            if((k+1-i)&1) val = mod - val;
            val = (val*sum[i]) % mod;
            ans = (ans + val) % mod;
        }
    }
    cout << ans;
}