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
#define mod ((int)1e9 + 7)
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
const int N = 1e5 + 5;
int modexp(int a, int b, int p) {
    int ret = 1;
    for(;b;b>>=1) {
        if(b&1)
            ret = (1LL * ret * a) % p;
        a = (1LL * a * a) % p;
    }
    return ret;
}
int inv(int a) {
    return modexp(a, mod-2, mod);
}
int main() {
    SYNC
    int invfac[N];
    invfac[0] = 1;
    FOR(i,1,N) {
        invfac[i] = (1LL * invfac[i-1] * inv(i)) % mod;
    }
    int k, x, s = 0, ans = 1;
    cin >> k;
    FOR0(i, k) {
        cin >> x; x--;
        s += x;
        ans = (1LL * ans * invfac[x]) % mod;
    }
    FOR(i,1,s+1) ans = (1LL * ans * i) % mod;
    cout << ans;
}