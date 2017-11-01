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
#define N 105
#define T 25005
#define K 35
int main() {
    SYNC
    int n, a, b, t, dp[T][K], q, qq;
    cin >> n;
    memset(dp, -1, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);
    while(n--) {
        cin >> a >> b >> t;
        if(b == 0) {
            FOR(i,t,T) {
                dp[i][0] = max(dp[i][0], dp[i-1][0]);
                if(dp[i-t][0] != -1) dp[i][0] = max(dp[i][0], dp[i-t][0] + a);
            }
        } else {
            for(int j = 1; a - (j-1)*(j-1)*b > 0; j++) {
                FORD(i, t, T) {
                    dp[i][j] = dp[i-1][j];
                    if(dp[i-t][j-1] != -1) {
                        dp[i][j] = max(dp[i][j], dp[i-t][j-1] + a - (j-1)*(j-1)*b);
                        dp[i][0] = max(dp[i][j], dp[i][0]);
                    }
                }
            }
        }
        FOR(i,1,T) {
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
        }
    }
    cin >> q;
    while(q--) {
        cin >> qq;
        cout << dp[qq][0] << newl;
    }
}