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
#define INF ((int)2e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 1005

int n, m, dp0[N][N] = {}, dp1[N][N] = {},dp2[N][N] = {},dp3[N][N] = {},a[N][N];
int main() {
    SYNC
    cin >> n >> m;
    FOR(i,1,n+1) FOR(j,1,m+1) cin >> a[i][j];
    FOR(i,1,n+1) FOR(j,1,m+1) dp0[i][j] = max(dp0[i-1][j], dp0[i][j-1]) + a[i][j];
    FORD(i,1,n+1) FORD(j,1,m+1) dp1[i][j] = max(dp1[i+1][j], dp1[i][j+1])+ a[i][j];
    FORD(i,1,n+1) FOR(j,1,m+1) dp2[i][j] = max(dp2[i+1][j], dp2[i][j-1])+ a[i][j];
    FOR(i,1,n+1) FORD(j,1,m+1) dp3[i][j] = max(dp3[i-1][j], dp3[i][j+1])+ a[i][j];
    int ans = 0;
    FOR(i,2,n) FOR(j,2,m) {
            int sum = max(dp0[i-1][j]+dp1[i+1][j]+dp2[i][j-1]+dp3[i][j+1], dp3[i-1][j]+dp2[i+1][j]+dp0[i][j-1]+dp1[i][j+1]);
            ans = max(ans, sum);
    }
    cout << ans;
}