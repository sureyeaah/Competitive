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

int main() {
	int n, cells[100 + 10], e, t, m, a, b, w, cases, dist[100 + 10];
	vector<vii> graph(100 + 10);
	priority_queue <ii, vector<ii>, greater<ii> > pq;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%d%d%d%d", &n, &e, &t, &m);
		FOR0(i, n+1) graph[i].clear();
		FOR0(i, m) {
			scanf("%d%d%d", &a, &b, &w);
			graph[a].pb(ii(b,w));
		}
		int escaped = 0;
		FOR(start, 1, n+1) {
			FOR0(i, n+1) dist[i] = INF;
			dist[start] = 0;
			pq.push(ii(0,start));
			while(!pq.empty()) {
				ii curr = pq.top(); pq.pop();
				int d = curr.first, u = curr.second;
				if(d > dist[u]) continue;
				repi(v, graph[u]) {
					if(dist[(*v).first] > dist[u] + (*v).second) {
						dist[(*v).first] = dist[u] + (*v).second;
						pq.push(ii((*v).second, (*v).first));
					}
				}
			}
			if(dist[e] <= t) escaped++;
		}
		cout << escaped << endl;
		if(cases) cout << endl;
	}
}