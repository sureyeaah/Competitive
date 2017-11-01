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
vvi graph(100000 + 5), treeGraph(100000 + 5);
int tree[100000 + 5];
int n, m, q, u, v,trees;
void getTree(int x, int p) {
	treeGraph[p].pb(x);
	tree[x] = p;
	repi(i, graph[x]) if(!tree[*i]) getTree(*i, p);
}
int main() {
	trees = 0;
	memset(tree,0,sizeof tree);
	scanf("%d%d%d", &n, &m, &q);
	FOR0(i, m) {
		scanf("%d%d",&u,&v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	FOR(i, 1, n+1) if(!tree[i]) getTree(i,++trees);
	FOR0(i, q) {
		scanf("%d%d",&u,&v);
		if(tree[u] == tree[v]) printf("-1\n");

	}
}