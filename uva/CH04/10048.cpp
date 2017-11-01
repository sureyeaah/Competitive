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
typedef pair<int,ii> iii;
int caseNumber = 1, c, s, q, c1, c2, d, minimax[100 + 10][100 + 10];
vector<vii> graph(100 + 10), tree(100 + 10);
bool taken[100 + 10], visited[100 + 10];
priority_queue <iii> pq;
void process(int u) {
	taken[u] = true;
	repi(i, graph[u]) {
		if(!taken[(*i).first]) pq.push(mp(-(*i).second, mp((*i).first,u)));
	}
}
void clear() {
	while(!pq.empty()) pq.pop();
}
void dfs(int u, int maxTillHere, int source) {
	visited[u] = true;
	repi(i, tree[u]) {
		int d = (*i).second, v = (*i).first;
		if(visited	[v]) continue;
		minimax[source][v] = max(maxTillHere,d);
		dfs(v,minimax[source][v],source);
	}
}
int main() {
	while(scanf("%d%d%d",&c,&s,&q) && c && s && q) {
		FOR(i,1,c+1) graph[i].clear();
		FOR(i,1,c+1) tree[i].clear();
		clear();
		memset(taken,false,sizeof taken);
		FOR(i,1,c+1) FOR(j,1,c+1) minimax[i][j] = INF;
		FOR0(i, s) {
			scanf("%d%d%d",&c1,&c2,&d);
			graph[c1].pb(mp(c2,d));
			graph[c2].pb(mp(c1,d));
		}
		FOR(start,1,c+1) {
			if(taken[start]) continue;
			process(start);
			while(!pq.empty()) {
				iii curr = pq.top(); pq.pop();
				int w = -curr.first, v = curr.second.first, u = curr.second.second;
				if(!taken[v]) {
					tree[u].pb(mp(v,w));
					tree[v].pb(mp(u,w));
					process(v);
				}
			}
		}
		if(caseNumber > 1) printf("\n");
		printf("Case #%d\n", caseNumber++);
		while(q--) {
			scanf("%d%d", &c1, &c2);
			int ans = min(minimax[c1][c2],minimax[c2][c1]);
			if(ans == INF) {
				memset(visited, false, sizeof visited);
				dfs(c1,0,c1);
			}
			ans = min(minimax[c1][c2],minimax[c2][c1]);
			if(ans == INF) printf("no path\n");
			else printf("%d\n",ans);
		}
	}
}