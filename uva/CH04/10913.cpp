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
#define INF -1000000000
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
#define down 0
#define left 1
#define right 2
int main() {
	int n, k, dp[80][80][6], curr[80][6][3], grid[80][80];
	FOR0(col,80) FOR0(negs, 6) dp[0][col][negs] = INF;
	dp[0][1][0] = 0;
	int caseNum = 0;
	while(scanf("%d%d", &n, &k) && (n || k) && ++caseNum) {
		FOR0(i, n) FOR0(j, n) scanf("%d", grid[i+1] + j + 1);
		FOR0(row, n) {
			FOR(col,1,n+1) {
				if(grid[row+1][col]<0) {
					FOR0(negs, k+1) {
						curr[col][negs][down] = (negs) ? ((dp[row][col][negs-1] != INF) ? dp[row][col][negs-1]+grid[row+1][col]: INF): INF;
						if(col==1) curr[col][negs][left] = INF;
						else if(!negs) curr[col][negs][left] = INF;
						else {
							int val = max(curr[col-1][negs-1][left], curr[col-1][negs-1][down]);
							curr[col][negs][left] = (val != INF) ? val+grid[row+1][col]: INF;
						}
					}
				}
				else {
					FOR0(negs, k+1) {
						curr[col][negs][down] = (dp[row][col][negs] != INF) ? dp[row][col][negs]+grid[row+1][col]: INF;
						if(col==1) curr[col][negs][left] = INF;
						else {
							int val = max(curr[col-1][negs][left], curr[col-1][negs][down]);
							curr[col][negs][left] = (val != INF) ? val+grid[row+1][col]: INF;
						}
					}
				}
			}
			// right
			FORD(col,1,n+1) {
				if(grid[row+1][col]<0) {
					FOR0(negs, k+1) {
						if(col==n) curr[col][negs][right] = INF;
						else if(!negs) curr[col][negs][right] = INF;
						else {
							int val = max(curr[col+1][negs-1][right], curr[col+1][negs-1][down]);
							curr[col][negs][right] = (val != INF) ? val+grid[row+1][col]: INF;
						}
					}
				}
				else {
					FOR0(negs, k+1) {
						if(col==n) curr[col][negs][right] = INF;
						else {
							int val = max(curr[col+1][negs][right], curr[col+1][negs][down]);
							curr[col][negs][right] = (val != INF) ? val+grid[row+1][col]: INF;
						}
					}
				}
			}
			FOR(col,1,n+1) FOR0(negs,k+1) dp[row+1][col][negs] = *max_element(curr[col][negs],curr[col][negs]+3);
		}
		int ans = *max_element(dp[n][n], dp[n][n]+k+1);
		printf("Case %d: ", caseNum);
		if(ans==INF) printf("impossible\n");
		else printf("%d\n", ans);
	}
}