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
	int c,n,m,dist[1000+10],edges[2000+10][3];
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &n, &m);
		FOR0(i, m)
			scanf("%d%d%d",&edges[i][0],&edges[i][1],&edges[i][2]);
		FOR0(i,n) dist[i] = INF;
		dist[0] = 0;
		FOR0(i, n-1) {
			FOR0(j, m) {
				if(dist[edges[j][0]] != INF) dist[edges[j][1]] = min(dist[edges[j][1]], dist[edges[j][0]]+edges[j][2]);
			}
		}
		bool possible = false;
		FOR0(i,m) {
			if ((dist[edges[i][0]] != INF) && dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2])
				possible = true;
		}
		if(possible) printf("possible\n");
		else printf("not possible\n");
	}
}