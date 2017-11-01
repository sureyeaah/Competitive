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
#define O 25
#define N 85
int c,t,n,a,dp[O][N],oxygen[1005],nitrogen[1005],weight[1005];
int main() {
	SYNC
	cin >> c;
	while(c--) {
		memset(dp,63,sizeof dp);
		cin >> t >> a >> n;
		FOR0(i, n) cin >> oxygen[i] >> nitrogen[i] >> weight[i];
		dp[0][0] = 0;
		int ans = INF;
		FOR0(i, n) {
			FORD(j,0,O) {
				FORD(k,0,N) {
					if(j + oxygen[i] < O && k + nitrogen[i] < N) dp[j + oxygen[i]][k + nitrogen[i]] = min(dp[j + oxygen[i]][k + nitrogen[i]], dp[j][k] + weight[i]);
					else ans = min(ans, dp[j][k] + weight[i]);
				}
			}
		}
		FOR(j,t,22) FOR(k,a,85) ans = min(ans, dp[j][k]);
		cout << ans << '\n';
	}
}