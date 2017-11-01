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
int t,n,s[100000 + 10],u,v;
/*vvi graph(100000 + 10);
int dfs(int u, int prev) {
	repi(i, graph[u]) {
		if(*i != prev) {
			dfs(*i,u);
		}
	}
}*/
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		FOR(i,1,n+1) scanf("%d",s+i);
		int cuts=0;
		FOR(i,1,n) {
			scanf("%d%d",&u,&v);
			switch (s[u]+s[v])
			//graph[u].pb(v);
			//graph[v].pb(u);
		}
		//dfs(1,0);
	}
}