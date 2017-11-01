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
int cases, days[26], head[26], timeDone[26];
char from, to, tmp;
vvi graph(26);
int dfs(int u) {
	if(timeDone[u]>=0) return timeDone[u];
	int ret = 0;
	repi(v, graph[u]) ret = max(ret, dfs(*v));
	return timeDone[u] = ret + days[u];
}
int main() {
	scanf("%d%*c%*c", &cases);
	while(cases--) {
		FOR0(i,26) graph[i].clear();
		FOR0(i,26) days[i] = INF;
		FOR0(i,26) head[i] = -1;
		FOR0(i,26) timeDone[i] = -INF;
		while(scanf("%c",&from)!=EOF && from != '\n') {
			scanf("%d%c", &days[from-'A'], &tmp);
			if(tmp=='\n') continue;
			head[from-'A'] = (!head[from-'A'])?0:1;
			while(scanf("%c",&to) && to != '\n') {
				graph[from-'A'].pb(to-'A');
				head[to-'A'] = 0;
			}
		}
		int ans = 0;
		FOR0(i,26) if(head[i] == 1) ans=max(ans,dfs(i));
		printf("%d\n",ans);
		if(cases) printf("\n");
	}
}