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
#define INF ((int)1e9 + 5)
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
int main() {
    SYNC
    int n, tot, w[N], v[N], dp[N][N][3*N];
    cin >> n >> tot;
    FOR0(i, n) {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    int ans = 0;
    dp[0][1][0] = v[0];
    FOR(i, 1, n) {
        dp[i][0][0] = 0;
        FOR(taken, 1, n + 1) {
            FOR(wt, 0, 3*taken + 1) {
                int val = (wt-(w[i] - w[0]) >= 0 ? dp[i-1][taken-1][wt-(w[i] - w[0])]: -1);
                if(val >= 0) val += v[i];
                dp[i][taken][wt] = max(dp[i-1][taken][wt], val);
            }
        }
    }
    FOR(taken, 1, n+1) {
        FOR0(wt, 3*taken + 1) {
            if(wt + taken*((ll)w[0]) <= tot) ans = max(ans, dp[n-1][taken][wt]);
        }
    }
    cout << ans;
}