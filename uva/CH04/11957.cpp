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
#define MOD 1000007
#define valid(x,y) (x >= 0 && y >= 0 && y < n && x < n)
int T,n,dr[2],dc[2], ways[105][105];
char board[105][105];
void bfs() {
	FORD(r, 1, n) {
		FOR0(c, n) {
			FOR0(i,2) {
				int nr = r, nc = c;
				FOR0(k,2) {
					nr += dr[i]; nc += dc[i];
					if(valid(nr,nc)) {
						if(board[nr][nc] == 'B') continue;
						else {
							ways[nr][nc] = (ways[nr][nc]+ways[r][c])%MOD;
							break;
						}
					} else break;
				}
			}
		}
	}
}
int main() {
	dr[0] = dr[1] = dc[1] = -1; dc[0] = 1;
	scanf("%d",&T);
	FOR(caseNumber,1,T+1) {
		scanf("%d",&n);
		while(getchar() != '\n') {}
		FOR0(i, n) scanf("%s",board[i]);
		FOR0(i, n) FOR0(j, n) ways[i][j] = 0;
		FOR0(i, n) FOR0(j, n) {
			if(board[i][j] == 'W') {
				ways[i][j] = 1;
				bfs();
				i = INF;
				break;
			}
		}
		int ans = 0;
		FOR0(i, n) ans = (ans+ways[0][i])%MOD;
		printf("Case %d: %d\n", caseNumber,ans);
	}
}