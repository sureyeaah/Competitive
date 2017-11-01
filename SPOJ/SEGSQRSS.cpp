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
#define MAXN 1000005
#define mid(l,r) (((l)+(r))>>1)
int t, n, q, a[MAXN], lazy[4*MAXN][2], type, x, start, nd;
ll sst[4*MAXN], st[4*MAXN];
void build(int p, int l, int r) {
	if(l == r) {st[p] = a[l]; sst[p] = a[l]*a[l]; return;}
	build(p<<1,l,mid(l,r));
	build(p<<1|1, mid(l,r)+1, r);
	st[p] = st[p<<1] + st[p<<1|1];
	sst[p] = sst[p<<1] + sst[p<<1|1];
}
void lazyUpd(int p, int l, int r) {
	if(lazy[p][0]) {
		st[p] = ((ll)lazy[p][0])*(ll)(r-l+1);
		sst[p] =((ll)lazy[p][0])*((ll)lazy[p][0])*(ll)(r-l+1);
		if(l != r) {
			lazy[p<<1][1] = lazy[p<<1|1][1] = 0;
			lazy[p<<1][0] = lazy[p<<1|1][0] = lazy[p][0];
		}
		lazy[p][0] = 0;
	} else if(lazy[p][1]) {
		sst[p] += 2*st[p]*lazy[p][1] + ((ll)lazy[p][1])*((ll)lazy[p][1])*(ll)(r-l+1);
		st[p] += ((ll)lazy[p][1])*(ll)(r-l+1);
		if(l != r) {
			if(lazy[p<<1][0]) lazy[p<<1][0]+= lazy[p][1];
			else lazy[p<<1][1]+= lazy[p][1];
			if(lazy[p<<1|1][0]) lazy[p<<1|1][0]+= lazy[p][1];
			else lazy[p<<1|1][1]+= lazy[p][1];
		}
		lazy[p][1] = 0;
	}
}
void update(int p, int l, int r) {
	lazyUpd(p,l,r);
	if(start > r || nd < l) return;
	if(start <= l && r <= nd) {
		lazy[p][type] = x;
		lazyUpd(p,l,r);
		return;
	}
	update(p << 1, l, mid(l, r));
	update(p<<1|1, mid(l,r)+1, r);
	st[p] = st[p<<1] + st[p<<1|1];
	sst[p] = sst[p<<1] + sst[p<<1|1];
}

ll query(int p, int l, int r) {
	lazyUpd(p,l,r);
	if(start > r || nd < l) return 0;
	if(start <= l && r <= nd) return sst[p];
	return query(p<<1,l,mid(l,r)) + query(p<<1|1,mid(l,r)+1,r);
}
int main() {
	scanf("%d", &t);
	FOR(caseNo, 1, t+1) {
		scanf("%d %d", &n, &q);
		FOR0(i, n) scanf("%d", a + i + 1);
		memset(lazy, 0, 2*(sizeof(int)*4*n+5));
		build(1,1,n);
		printf("Case %d:\n", caseNo);
		while(q--) {
			scanf("%d%d%d", &type, &start, &nd);
			if(type == 2) printf("%lld\n", query(1,1,n));
			else {
				scanf("%d", &x);
				update(1,1,n);
			}
		}
	}
}