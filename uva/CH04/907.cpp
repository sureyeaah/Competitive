#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, k, dp[610][310], dist[610], x;
int go(int site, int day) {
	if(dp[site][day]!=INF || !day) return dp[site][day];
	FOR(i, 0, site+1) dp[site][day] = min(dp[site][day], max(dist[site]-dist[i],go(i, day-1)));
	return dp[site][day];
}
int main() {
	while(scanf("%d%d",&n,&k)!=EOF) {
		FOR0(i, n+2) FOR0(j, k+2) dp[i][j] = INF;
		dist[0] = 0;
		FOR(i,1,n+2) {
			scanf("%d",&x);
			dist[i] = dist[i-1] + x;
		}
		dp[0][0] = 0;
		printf("%d\n",go(n+1,min(n,k)+1));
	}
}