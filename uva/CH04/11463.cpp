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

int T, n, r, u, v, s, d, matrix[101][101],dists[101],distd[101];
vvi graph(100 + 10);
queue<int> q;

void bfs(int start, int dist[]) {
	FOR0(i,n) dist[i] = INF;
	q.push(start);
	dist[start] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		repi(i, graph[u]) {
			if(dist[*i] == INF) {
				dist[*i] = dist[u] + 1;
				q.push(*i);
			}
		}
	}
}

int main() {
	// bfs approach
	scanf("%d", &T);
	FOR(caseNum, 1, T+1) {
		scanf("%d%d", &n, &r);
		// reset
		FOR0(i,n) graph[i].clear();
		// fill matrix
		while(r--) {
			scanf("%d%d", &u, &v);
			graph[u].pb(v);
			graph[v].pb(u);
		}
		scanf("%d%d",&s,&d);
		bfs(s,dists);
		bfs(d,distd);
		int ans = 0;
		FOR0(i, n) ans = max(ans, dists[i] + distd[i]);
		printf("Case %d: %d\n", caseNum, ans);
	}
}

// Not as good an approach.
void main2() {
	// Floyd Marshall approach.
	int T, n, r, u, v, s, d, matrix[101][101];
	scanf("%d", &T);
	FOR(caseNum, 1, T+1) {
		scanf("%d%d", &n, &r);
		// reset
		FOR0(i,n)
			FOR0(j,n)
				matrix[i][j] = INF;
		FOR0(i, n) matrix[i][i] = 0;
		// fill matrix
		while(r--) {
			scanf("%d%d", &u, &v);
			matrix[u][v] = matrix[v][u] = 1;
		}
		scanf("%d%d",&s,&d);
		FOR0(k,n)
			FOR0(i,n)
				FOR0(j,n)
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
		int ans = 0;
		FOR0(i, n) ans = max(ans, matrix[s][i] + matrix[i][d]);
		printf("Case %d: %d\n", caseNum, ans);
	}
}