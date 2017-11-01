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
#define mod (7 + (int)1e9)
#define N 200005
int pow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)
            res = (1LL * res * a) % mod;
        b >>= 1;
        a = (1LL * a * a) % mod;
    }
    return res;
}
int main() {
    SYNC
    int t, xs, ys, xt, yt, k, fac[N], invfac[N];
    fac[0] = 1;
    FOR(i, 1, N) fac[i] = 1LL *fac[i-1] * i % mod;
    FOR0(i, N) invfac[i] = pow(fac[i], mod - 2);
    cin >> t;
    while(t--) {
        cin >> xs >> ys >> xt >> yt >> k;
        xt -= xs; yt -= ys;
        xt = abs(xt); yt = abs(yt);
        if(k < xt + yt || (k-xt-yt) & 1) {
            cout << 0 << "\n";
            continue;
        }
        int ways = 0;
        FOR0(l, (k-xt-yt) + 1) {
            int r = l + xt;
            int d = (k-yt-xt)/2 - l;
            int u = d + yt;
            // DEBUG(l); DEBUG(r); DEBUG(u); DEBUG(d);
            if(d < 0) continue;
            int val = 1LL * invfac[l] * invfac[r] % mod;
            val = 1LL*val*(1LL*invfac[u]*invfac[d] % mod) % mod;
            ways = (1LL*fac[k]*val + ways)%mod;
        }
        cout << ways << '\n';
    }
}