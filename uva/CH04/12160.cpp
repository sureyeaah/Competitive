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
#define MOD 10000
int l, u, r, v[10], caseNumber = 0, dist[MOD+10], size;
int *curr;
int *other;
int bfs() {
	int ret = 0;
	FOR0(i, size) {
		int x = curr[i];
		FOR0(j, r) {
			int y = (x+v[j])%MOD;
			if(dist[x] + 1 < dist[y]) {
				dist[y] = dist[x] + 1;
				other[ret++] = y;
			}
		}
	}
	swap(curr, other);
	return ret;
}

int main() {
	curr = (int*) malloc(sizeof(int)*(10+MOD));
	other = (int*) malloc(sizeof(int)*(10+MOD));
	while(scanf("%d%d%d", &l, &u, &r)) {
		if(l==0 && u == 0 && r == 0) break;
		FOR0(i, r) scanf("%d", v + i);
		FOR0(i, MOD) dist[i] = INF;
		dist[l] = 0;
		curr[size++] = l;
		do {
			size = bfs();
		} while(size);
		cout << "Case " << ++caseNumber << ": ";
		if(dist[u] < INF) cout << dist[u] << endl;
		else cout << "Permanently Locked" << endl;
	}
	free(curr);
	free(other);
	return 0;
}