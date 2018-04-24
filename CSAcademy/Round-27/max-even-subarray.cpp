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
#define INF ((ll)1e18)
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
	int n, a[100005];
	ll dp[100005][2];
	cin >> n;
	FOR0(i, n) cin >> a[i];
	dp[n-1][0] = -INF; dp[n-1][1] = a[n-1];
	FORD(i,0,n-1) {
		dp[i][0] = max(dp[i+1][1] + a[i], (ll)a[i] + a[i+1]);
		dp[i][1] = max(dp[i+1][0] + a[i], (ll)a[i]);
	}
	ll ans= -INF;
	FOR0(i, n-1) ans = max(ans, dp[i][0]);
	cout << ans << endl;
}