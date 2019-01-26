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
#define N 755
#define mod (7 + (int)1e9)
int fac[N], invfac[N];
int pow(int a, int pow) {
    int res = 1;
    while(pow) {
        if(pow & 1) res = res * 1LL * a % mod;
        pow >>= 1;
        a = a * 1LL * a % mod;
    }
    return res;
}
int ncr(int n, int r) {
    if(r > n) return 0;
    else return (1LL * fac[n] * invfac[r] % mod) * invfac[n - r] % mod;
}
int main() {
    SYNC
    int n, a[N], cnt[N] = {}, dp[N][N] = {};
    fac[0] = 1; FOR(i,1,N) fac[i] = fac[i-1] * 1LL * i % mod;
    FOR0(i, N) infac[i] = pow(fac[i], mod - 2);
    cin >> n;
    FOR0(i, n) cin >> a[i];
    FOR0(i,n) cnt[a[i]]++;
    dp[0][0] = 1;
    int tot = 0;
    FOR(i,1,N) {
        FOR(j,0,N) {
            
        }
    }
}