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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t, a[100000 + 5], n;
vector<pair<int,ll> >  st[400000 + 5];
void build(int p, int l, int r) {
	if(l == r) {
		st[p].assign(1,mp(l,0));
		return;
	}
	build(p<<1,l,(l+r)>>1); build(p<<1|1,((l+r)>>1)+1,r);
	st[p].clear();
	int i = 0; int j = 0, lsiz = st[p<<1].size(), rsiz = st[p<<1|1].size();
	st[p<<1].pb(mp(0,0)); st[p<<1|1].pb(mp(0,0));
	ll toAdd = 0;
	while(i < lsiz || j < rsiz) {
		int x = st[p<<1][i].ff; int y = st[p<<1|1][j].ff;
		if(a[x] < a[y]) {
			toAdd += (ll)a[x];
			st[p].pb(st[p<<1][i]);
			i++;
		} else {
			st[p<<1|1][j].ss += toAdd;
			st[p].pb(st[p<<1|1][j]);
			j++;
		}
	}
}
int main() {
	a[0] = INF;
	scanf("%d", &t);
	while(t--) {
		scanf("%d" ,&n);
		FOR(i,1,n+1) scanf("%d", a+i);
		build(1,1,n);
		ll ans = 0;
		repi(i, st[1]) ans += i->ss;
		printf("%lld\n", ans);
	}
}