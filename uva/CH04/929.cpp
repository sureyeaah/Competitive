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
typedef pair<int,ii> iii;

int main() {
	int n,m,grid[1000][1000],dist[1000][1000], mazes, dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	priority_queue< iii, vector< iii >, greater< iii > >pq;
	scanf("%d", &mazes);
	while(mazes--) {
		scanf("%d%d", &n, &m);
		FOR0(i, n) {
			FOR0(j, m) {
				scanf("%d", &grid[i][j]);
				dist[i][j] = INF;
			}
		}
		dist[0][0] = grid[0][0];
		pq.push(mp(dist[0][0],mp(0,0)));
		while(!pq.empty()) {
			iii curr = pq.top(); pq.pop();
			int w = curr.first; ii u = curr.second;
			if(w > dist[u.first][u.second]) continue;
			FOR0(i, 4) {
				int v_x = u.first + dir[i][0], v_y = u.second + dir[i][1];
				if(!(v_x >= 0 && v_y >= 0 && v_x < n && v_y < m)) continue;
				if(grid[v_x][v_y] + dist[u.first][u.second] >= dist[v_x][v_y]) continue;
				dist[v_x][v_y] = grid[v_x][v_y] + dist[u.first][u.second];
				pq.push(mp(dist[v_x][v_y], mp(v_x, v_y)));
			}
		}
		cout << dist[n-1][m-1] << endl;
	}
}