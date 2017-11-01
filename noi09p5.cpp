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
#define MOD 1024523
int main() {
	SYNC;
	int n, m, dp[505][505][505];
	cin >> n >> m;
	char s[2][505];
	FOR0(i, n) cin >> s[0][n-i-1];
	FOR0(i, m) cin >> s[1][m-i-1];
	dp[0][0][0] = 1;
	FOR0(i, n+1) {
		FOR0(j, m+1) {
			int len = i+j;
			FOR0(k,min(len,n)+1) {
				int l = len - k;
				if(l < 0 || l > m) continue;
				if(i) {
					if(l && s[1][l-1]==s[0][i-1]) dp[i][j][k] += dp[i-1][j][k];
					if(k && s[0][i-1]==s[0][k-1]) dp[i][j][k] += dp[i-1][j][k-1];
				}
				if(j) {
					if(k && s[0][k-1]==s[1][j-1]) dp[i][j][k] += dp[i][j-1][k-1];
					if(l && s[1][l-1]==s[1][j-1]) dp[i][j][k] += dp[i][j-1][k];
				}
				dp[i][j][k] %= MOD;
			}
		}
	}
	cout << dp[n][m][n] << endl;
}