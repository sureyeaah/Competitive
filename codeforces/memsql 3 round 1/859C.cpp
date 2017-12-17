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

int main() {
    SYNC
    int n, a[55], dp[55][2][2] = {};
    cin >> n;
    FOR0(i, n) cin >> a[i];
    memset(dp[n], 0, sizeof dp[n]);
    FORD(i,0,n) {
        FOR0(j, 2) {
            dp[i][j][1] = max(dp[i+1][j][0] + a[i], dp[i+1][j][1]);
        }
        FOR0(j, 2) {
            dp[i][j][0] = (dp[i][!j][1] == dp[i+1][!j][0] + a[i]) ? dp[i+1][j][1]: dp[i+1][j][0] + a[i];
        }
    }
    cout << dp[0][0][0] << " " << dp[0][1][1];
}