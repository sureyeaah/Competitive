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
#define INF ((int)1e15)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAXN 100005
int main() {
	SYNC;
	int n, l, x[MAXN], d[MAXN], t[MAXN], p[MAXN];
	cin >> n >> l;
	FOR0(i, n) cin >> x[i] >> d[i] >> t[i] >> p[i];
	x[n] = 0; d[n] = l; p[n] = 0; t[n] = 0;
	vi ramps;
	FOR0(i, n) ramps.pb(i);
	sort(ramps.begin(), ramps.end(), [](const int& lhs, const int& rhs){return x[lhs]-p[lhs] >= x[rhs]-d[rhs];});
	ll dp[MAXN][2]; memset(dp,2*INF,sizeof dp);
	dp[0][0] = 0;
	FOR(i, 1, n+1) {
		int curr = ramps[i], prev = ramps[i-1]; 
		dp[i][0] = min(dp[i-1][0]+x[prev]-x[curr], dp[i-1][1]);
	}
}