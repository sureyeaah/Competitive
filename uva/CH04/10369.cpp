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
typedef pair<int, ii> iii;

int n, s, p, coords[501][2];
vector<iii> edges;
int parent[501], Rank[501];
int findSet(int u) {
	if(parent[u] == u) return u;
	else return (parent[u] = findSet(parent[u]));
}
bool sameSet(int u, int v) {
	return findSet(u) == findSet(v);
}
void unionSet(int u, int v) {
	int setu = findSet(u), setv = findSet(v);
	if(Rank[setu] > Rank[setv]) parent[setv] = setu;
	else {
		parent[setu] = setv;
		if(Rank[setu] == Rank[setv]) Rank[setv]++;
	}
}
int main() {
	
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &s, &p);
		FOR0(i, p)
			scanf("%d%d", &coords[i][0], &coords[i][1]);
		edges.clear();
		FOR0(i, p)
			FOR0(j,i)
				edges.pb(mp(((pow(coords[i][0]-coords[j][0],2)) + (pow(coords[i][1]-coords[j][1],2))), mp(i,j)));
		sort(edges.begin(), edges.end());
		int edgesUsed = 0;
		FOR0(i, p) parent[i] = i;
		FOR0(i, p) Rank[i] = 0;
		double ans;
		FOR0(i, edges.size()) {
			int u = edges[i].second.first, v = edges[i].second.second;
			if(!sameSet(u,v)) {
				unionSet(u,v);
				edgesUsed++;
			}
			if(edgesUsed == p-s) {ans = sqrt((double)edges[i].first); break;}
		}
		printf("%.2f\n", ans);
	}
}