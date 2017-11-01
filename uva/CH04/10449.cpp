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

int n, busy[200 + 10], r, src, dest, q, junc, setNum = 0, dist[200+10];
bool negReachable[200 + 10];
vector<vii> graph(200 + 10);

bool dfs(int u) {
	negReachable[u] = true;
	repi(i, graph[u]) {
		if(!negReachable[(*i).first]) {
			dfs((*i).first);
		}
	}
}

int main() {

	while(cin>> n) {
		FOR(i,1,n+1) dist[i] = INF;
		FOR(i, 1, n+1)
			scanf("%d", busy + i);
		FOR(i, 1, n+1)
			graph[i].clear();
		scanf("%d", &r);
		while(r--) {
			scanf("%d%d", &src, &dest);
			graph[src].pb(ii(dest, pow(busy[dest] - busy[src], 3)));
		}
		dist[1] = 0;
		FOR0(i, n-1) {
			FOR(u,1,n+1) {
				if(dist[u] == INF) continue;
				repi(curr, graph[u]) {
					int v = (*curr).first, w = (*curr).second;
					dist[v] = min(dist[v], dist[u]+w);
				}
			}
		}
		memset(negReachable, false, sizeof negReachable);
		FOR(u,1,n+1) {
			if(dist[u] == INF) continue;
			repi(curr, graph[u]) {
				int v = (*curr).first, w = (*curr).second;
				if(dist[v] > dist[u]+w && !negReachable[u]) {
					dfs(u);
				}
			}
		}
		scanf("%d", &q);
		printf("Set #%d\n", ++setNum);
		while(q--) {
			scanf("%d", &junc);
			if(negReachable[junc] || dist[junc] < 3 || dist[junc] == INF) printf("?\n");
			else printf("%d\n",dist[junc]);
		}
	}
}