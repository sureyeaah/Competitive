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
int T, n, m, a, b, c, tree[100+10];
int p[100 + 10], r[100 + 10];
vector<iii> edges;
int findSet(int u) {
	return ((u == p[u]) ? u : (p[u] = findSet(p[u])));
}
bool sameSet(int u, int v) {
	return findSet(u) == findSet(v);
}
void unionSet(int u, int v) {
	int x = findSet(u), y = findSet(v);
	if(r[x] > r[y]) p[y] = x;
	else {
		p[x] = y;
		if(r[x] == r[y]) r[y]++;
	}
}
int mst(int flag) {
	int cost = 0, edgesUsed = 0;
	FOR0(i, n+1) p[i] = i;
	FOR0(i, n+1) r[i] = 0;
	FOR0(i, m) {
		if(i == flag) continue;
		int w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
		if(!sameSet(u, v)) {
			unionSet(u, v);
			cost += w;
			if(flag==-1) tree[edgesUsed++] = i;
		}
	}
	return cost;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		edges.clear();
		FOR0(i, m) {
			scanf("%d%d%d",&a,&b,&c);
			edges.pb(mp(c,mp(a,b)));
		}
		sort(edges.begin(), edges.end());
		int mst1 = mst(-1);
		int mst2 = INF;
		FOR0(i, n-1) {
			int curr_mst = mst(tree[i]);
			if(curr_mst >= mst1) mst2 = min(mst2, curr_mst);
		}
		if(mst2 == INF) mst2 = mst1;
		printf("%d %d\n", mst1, mst2);
	}
}