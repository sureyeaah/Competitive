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
const int N = 2e5 + 5;
int fac[2*N], invfac[2*N];
int invmod(int a, int b = mod-2) {
    ll ret = 1;
    for(; b; b>>=1) {
        if(b&1)
            ret = ret * a % mod;
        a = (a*1LL*a) % mod;
    }
    return ret;
}
ll ch(int n, int r) {
    return fac[n] * (invfac[r] * 1LL * invfac[n-r] % mod) % mod;
}
int main() {
    SYNC
    int n, pre[N];string s;
    cin >> s; n = s.length();
    pre[0] = 0;
    fac[0] = invfac[0] = 1;
    FOR(i, 1, 2*N) {
        fac[i] = fac[i-1] * 1LL * i % mod;
        invfac[i] = invmod(fac[i]);
    }
    FOR0(i, s.length()) {
        pre[i+1] = pre[i] + (s[i] == '(');
    }
    int ans = 0;
    FOR(i, 1, n+1) {
        if(pre[i] == pre[i-1]) continue;
        int x = pre[i], y = n - i - (pre[n] - pre[i]);
        ans = (ans + ch(x+y-1, x)) % mod;
    }
    cout << ans;
}