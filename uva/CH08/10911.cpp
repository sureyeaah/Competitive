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
#define printCase() "Case " << ++caseNum << ": "
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
string s;
int n, x[16], y[16];
double dist[16][16], dp[(1 << 16) + 1];

double recurse(int mask) {
	if(dp[mask] > -1.0) return dp[mask];
	if(mask == (1 << (2*n))-1) return dp[mask] = 0;
	double ans = 1e9;
	FOR0(i, n*2) {
		if(mask & (1<<i)) continue;
		FOR(j, i+1, n*2) {
			if(mask & (1<<j)) continue;
			ans = min(ans, dist[i][j] + recurse(mask | (1<<i) | (1<<j)));
		}
		break;
	}
	return dp[mask] = ans;
}
int main() {
	SYNC;
	int caseNum = 0;
	while(cin >> n && n) {
		FOR0(i, 2*n) cin >> s >> x[i] >> y[i];
		FOR0(i, 2*n) FOR0(j, 2*n) dist[i][j] = hypot(x[i]-x[j], y[i]-y[j]);
		FOR0(i, (1 << (2*n))) dp[i] = -2;
		cout << printCase() << setprecision(2) << fixed << recurse(0) << endl;
	}
}