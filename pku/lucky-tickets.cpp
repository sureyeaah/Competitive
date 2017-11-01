#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

int main() {
    SYNC
    int n, dp[6][50] = {};
    cin >> n;
    dp[0][0] = 1;
    FOR(cnt,1,n/2 + 1) {
        FOR(sum, 0, 50) {
            FOR(digit,0,10) {
                if(digit <= sum) dp[cnt][sum] += dp[cnt-1][sum-digit];
            }
        }
    }
    ll ans = 0;
    FOR0(i, 50) ans += 1LL*dp[n/2][i]*dp[n/2][i];
    cout << ans;
}