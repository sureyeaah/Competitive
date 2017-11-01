#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endingl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).ending(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rending(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t;
int start[2][105], ending[2][105], cnt[2];
int dp[24*60 + 5][725][2], busy[2][24*60+5];
int main() {
	SYNC;
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> cnt[0] >> cnt[1];
		FOR0(i, cnt[0]) cin >> start[0][i] >> ending[0][i];
		FOR0(i, cnt[1]) cin >> start[1][i] >> ending[1][i];
		memset(busy, 0, sizeof busy);
		FOR0(i, 2) FOR0(j, cnt[i]) {
			FOR(k,start[i][j],ending[i][j]+1) busy[i][k] = 1;
		}
		FOR0(i, 24*60 + 5) FOR0(j, 725) FOR0(k, 2) dp[i][j][k] = INF;
		dp[0][720][0] = dp[0][720][1] = 0;
		FOR(st, 1, 720*2 + 1) {
			FOR0(i, 2) {
				if(busy[i][st]) continue;
				FOR(timeLeft,0,720){
					dp[st][timeLeft][i] = min(dp[st][timeLeft][i],dp[st-1][timeLeft+1][i]);
					dp[st][timeLeft][i] = min(dp[st][timeLeft][i],dp[st-1][timeLeft+1][1-i] + 1);
				}
			}
		}
		int ans = min(dp[720*2][0][0], dp[720*2][0][1]);
		cout << ans << endl;
	}
}