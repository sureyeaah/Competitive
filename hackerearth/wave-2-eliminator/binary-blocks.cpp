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
int dp[2505][2505] = {};

inline int val(int r, int c, int rr, int cc) {
    return dp[r][c] - dp[r][cc] - dp[rr][c] + dp[rr][cc];
}

int main() {
    SYNC
    int n, m;
    char x;
    cin >> n >> m;
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            cin >> x;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (x == '1');
        }
    }
    int ans = dp[n][m];
    for(int k = max(n, m) + 1; k > 1; k--) {
        int cur = 0;
        for(int i = k; i <= n; i += k) {
            for(int j = k; j <= m; j += k) {
                cur += min(k*k - val(i,j,i-k,j-k), val(i,j,i-k,j-k));
            }
            if(m % k) cur += min(val(i,m,i-k,m-(m%k)), k*k - val(i,m,i-k,m-(m%k)));
        }
        if(n % k) {
            for(int j = k; j <= m; j += k) {
                cur += min(k*k - val(n,j,n-n%k,j-k), val(n,j,n-n%k,j-k));
            }
            if(m % k) cur += min(val(n,m,n-n%k,m-(m%k)), k*k - val(n,m,n-n%k,m-(m%k)));
        }
        ans = min(ans, cur);
    }
    cout << ans;
}