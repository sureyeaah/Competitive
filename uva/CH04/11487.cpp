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
#define cell(p) grid[p.first][p.second]
#define MOD 20437
#define valid(x,y) (x>=0 && y>=0 && x < n && y < n)
int n, targets, dr[4], dc[4];
ii location[26];
char grid[11][11];
ii bfs(int start) {
	int dp[11][11] = {}, level[11][11] = {};
	queue<ii> q;
	q.push(location[start]);
	dp[location[start].first][location[start].second] = level[location[start].first][location[start].second] = 1;
	while(!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();
		FOR0(i, 4) {
			int nr = r + dr[i], nc = c + dc[i];
			if(!valid(nr,nc)) continue;
			if(!level[nr][nc] && (grid[nr][nc]=='.'||grid[nr][nc]==('A'+start+1))) {
				q.push(mp(nr, nc));
				level[nr][nc] = level[r][c]+1;
			}
			if(level[nr][nc] == level[r][c]+1)
				dp[nr][nc] = (dp[r][c]+dp[nr][nc])%MOD;
		}
	}
	int dx = location[start+1].first, dy =location[start+1].second ;
	return mp(dp[dx][dy], level[dx][dy] - 1);
}
int main() {
	int caseNum = 1;
	dr[0] = dr[2] = dc[1] = dc[3] = 0;
	dr[1] = dc[0] = 1;
	dr[3] = dc[2] = -1;
	while(scanf("%d", &n) && n) {
		targets = 0;
		FOR0(i, n) scanf("%s",grid+i);
		FOR0(i, n) {
			FOR0(j, n) {
				if(grid[i][j] != '.' && grid[i][j] != '#') {
					targets = max(targets, grid[i][j] - 'A' + 1);
					location[grid[i][j]-'A'] = mp(i, j);
				}
			}
		}
		cell(location[0]) = 1;
		int ans = !(!targets), shortestPath=0;
		FOR0(i, targets-1) {
			cell(location[i]) = '.';
			ii ret = bfs(i);
			ans = (ans*ret.first)%MOD;
			if(ret.second<1) {
				shortestPath = INF;
				break;
			}
			shortestPath += ret.second;
		}
		printf("Case %d: ", caseNum++);
		if(shortestPath == INF) printf("Impossible\n");
		else printf("%d %d\n", shortestPath, ans);
	}
}