#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
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
int m, w, id, c, graph[105][105], p[105], f;
void augment(int v, int minEdge) {
	if(v == 1) {f = minEdge; return;}
	else if(p[v]) {
		augment(p[v], min(minEdge, graph[p[v]][v]));
		graph[p[v]][v] -= f; graph[v][p[v]] += f;
	}
}
int main() {
	while(scanf("%d%d", &m, &w) && (m || w)) {
		memset(graph,0,sizeof graph);
		FOR0(i, m-2) {
			scanf("%d%d", &id, &c);
			graph[id][m+id] = c; 
		}
		graph[1][m+1] = graph[m][m+m] = INF;
		FOR0(i, w) {
			int j, k, d;
			scanf("%d%d%d", &j, &k, &d);
			graph[j+m][k] = graph[k+m][j] = d;
		}
		int mc = 0;
		while(1) {
			f = 0; memset(p,0,sizeof p); p[1] = -1;
			queue<int> q; q.push(1);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if (u == m) break;
				FOR(v,1,2*m+1) {
					if(graph[u][v] && !p[v]) {
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(m, INF);
			if(!f) break;
			mc += f;
		}
		printf("%d\n", mc);
	}
}