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
#define N 2005
int main() {
    SYNC
    int n, m; long double p[N], dp[N][N];
    cin >> n >> m;
    FOR(i, 1, n+m) {
        cin >> p[i];
    }
    FOR0(i, N) {
        FOR0(j, N) {
            dp[i][j] = 0.0;
        }
    }
    dp[0][n] = 1.0;
    long double ans = 0.0;
    FOR(game,1,n+m) {
        FOR(i, max(0, n-game), n+1) {
            if(i < n) dp[game][i] = dp[game-1][i+1] * (1 - p[game]);
            dp[game][i] += dp[game-1][i] * p[game];
            if(n-i+m == game) {
                ans += dp[game][i];
                dp[game][i] = 0;
            }
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}