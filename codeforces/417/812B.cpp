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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	SYNC;
	int n,m;
	char grid[20][105];
	cin >> n>> m;
	FORD(i, 0, n) FOR0(j, m+2) cin >> grid[i][j];
	int dp[20][2];
	dp[0][0] = 0; dp[0][1] = INF;
	int ans = 0;
	FOR(i,1,n+1) {
		bool has = false; int st = INF, nd = -1;
		FOR0(j,m+2) if(grid[i-1][j] == '1') {
			has = 1;
			st = min(st, j);
			nd = max(nd, j);
		}
		if(has) ans = min(dp[i-1][1]+(m+1-st), dp[i-1][0]+nd);
		if(has) dp[i][1] = min(dp[i-1][0]+m+2, dp[i-1][1]+2*(m+1-st)+1);
		else dp[i][1] = min(dp[i-1][0]+m+2, dp[i-1][1]+1);
		if(has) dp[i][0] = min(dp[i-1][1]+m+2, dp[i-1][0]+2*(nd)+1);
		else dp[i][0] = min(dp[i-1][1]+m+2, dp[i-1][0]+1);
	}
	cout << ans;
}