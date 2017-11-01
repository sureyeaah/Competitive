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

int n, energy[100 + 10], dist[100 + 10], connecting, x, finish, start;
vvi graph(100 + 10);
queue<int> q;
bool visited[100 + 10];

bfs(int u) {
	memset(visited, 0, sizeof visited);
	q.push(u);
	while(!q.empty()) {
		int curr = q.front(); q.pop();
		visited[curr] = true;
		repi(i, graph[curr]) {
			if(!visited[*i]) {
				q.push(*i);
			}
		}
	}
	return visited[finish];
}

int main() {
	while(scanf("%d", &n) && n != -1) {
		FOR(i, 1, n+1) {
			graph[i].clear();
			dist[i] = -INF;
			scanf("%d%d", energy + i, &connecting);
			finish = n;
			start = 1;
			while(connecting--) {
				scanf("%d", &x);
				graph[i].pb(x);
			}
		}
		dist[start] = 100;
		FOR0(i, n-1) {
			FOR(u, 1, n+1) {
				if(dist[u] <= 0) continue;
				repi(v, graph[u]) {
					dist[*v] = max(dist[*v], dist[u] + energy[*v]);
				}
			}
		}
		bool winnable = dist[finish] >= 0;
		if(!winnable) {
			FOR(u, 1, n+1) {
				if(dist[u] <= 0) continue;
				repi(v, graph[u]) {
					if((dist[*v] < dist[u] + energy[*v]) && bfs(u)) {winnable = true; u = INF; break;}
				}
			}
		}
		if(winnable) printf("winnable\n");
		else printf("hopeless\n");
	}
}