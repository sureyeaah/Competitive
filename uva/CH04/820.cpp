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

int main() {
	int n, s, t, c, adj[101][101],x,y,z,p[101],f,mf;
	int netNum = 0;
	while(scanf("%d", &n) && n) {
		scanf("%d%d%d", &s, &t, &c);
		memset(adj, 0, sizeof adj);
		FOR0(i, c) {
			scanf("%d%d%d",&x,&y,&z);
			adj[x][y] = adj[y][x] += z;
		}
		mf = 0;
		while(true) {
			memset(p,0,(sizeof (int)) * (n+1));
			f = INF; queue<int> q; q.push(s); p[s] = s;
			while(!q.empty()) {
				int u = q.front(); q.pop();
				FOR(i,1,n+1) {
					if(adj[u][i] && !p[i]) {
						p[i] = u;
						q.push(i);
					}
				}
				if(u == t) break;
			}
			if(!p[t]) break;
			x = t;
			while(p[x] != x) {
				f = min(f, adj[p[x]][x]);
				x = p[x];
			}
			if(!f || f==INF) break;
			x = t;
			while(p[x] != x) {
				adj[p[x]][x] -= f;
				adj[x][p[x]] += f;
				x = p[x];
			}
			mf += f;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", ++netNum, mf);
	}
}