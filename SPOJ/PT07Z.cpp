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
int dist[10010];
int n,u,v;
vvi graph(10000+10);
int bfs(int start) {
	queue<int> q;
	int ret = start;
	memset(dist,0,sizeof dist);
	dist[start] = 1;
	q.push(start);
	while(!q.empty()) {
		int v= q.front(); q.pop(); ret = v;
		repi(i,graph[v]) if(dist[*i] == 0) {q.push(*i); dist[*i] = dist[v]+1;}
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	FOR0(i,n-1) {
		scanf("%d%d",&u,&v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	printf("%d",dist[bfs(bfs(1))]-1);
}