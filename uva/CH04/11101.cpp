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
#define VALID(r,c) (r>=0 && c>=0 && r<=2000 && c<=2000)
int main() {
	int p, a, s, d;
	int** dist = (int**) malloc(2010*sizeof(int*));
	FOR0(i, 2010) dist[i] = (int*) malloc(2010*sizeof(int));
	int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};
	while(scanf("%d", &p) && p) {
		queue<ii> q;
		FOR0(i,2002) FOR0(j,2002) dist[i][j] = INF;
		FOR0(i, p) {
			scanf("%d%d",&a,&s);
			dist[a][s] = 0;
			q.push(mp(a,s));
		}
		scanf("%d", &p);
		FOR0(i, p) {
			scanf("%d%d",&a,&s);
			dist[a][s] = INF + 10;
		}
		int ans = INF;
		while(!q.empty()) {
			ii pos = q.front(); q.pop();
			int r= pos.first, c = pos.second;
			FOR0(i, 4) {
				int nr = r + dr[i], nc = c + dc[i];
				if(VALID(nr, nc)) {
					if(dist[nr][nc] > dist[r][c] + 1) {
						if(dist[nr][nc] > INF) {ans = min(ans, dist[r][c] + 1);}
						else {dist[nr][nc] = dist[r][c] + 1; q.push(mp(nr, nc));}
					}
				}
			}
			if(ans < INF) break;
		}
		cout << ans << endl;
	}
	FOR0(i, 2010) free(dist[i]);
	free(dist);
}