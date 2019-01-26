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
#define B 31
#define int long long
int ncr[50][50] = {};
int NCR(int n, int r) {
    if(n < r || n < 0 || r < 0) return 0;
    return ncr[n][r];
}

int32_t main() {
    SYNC
    FOR(i, 0, 50) {
        ncr[i][0] = 1;
        FOR(j, 1, i+1) ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
    }
    // cout << NCR(49, 1) << endl;
    // return 0;
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        vi bits;
        FORD(i, 0, B) {
            if(n & (1 << i)) bits.pb(i);
        }
        int ans = 0;
        FOR(tot, 1, B+1) {
            ll cur = 0;
            int val = 0;
            FOR0(i, SZ(bits)) {
                int x = bits[i];
                if(x) {
                    int tmp = (((1LL << (x)) - 1) * tot % mod) * 1LL * NCR(x - 1, tot - i - 1) % mod;
                    val = (tmp + val) % mod;
                    if(tot - i - 1 >= 0 ) val = (val + (cur*NCR(x, tot - i) % mod)*1LL*tot) % mod;
                }
                // else if(SZ(bits)-1 == tot) ans += (cur * 1LL * tot % mod);
                cur |= (1 << x);
                if(i+1 == tot) val = (val + 1LL* cur * 1LL * tot)%mod;
                if(i + 1 > tot) break;
            }
            // DEBUG(val);
            ans = (ans + val) % mod;
        }
        // ans = (ans + 1LL*n* 1LL * (SZ(bits)))%mod;
        cout << (ans+mod)%mod << '\n';
    }
}