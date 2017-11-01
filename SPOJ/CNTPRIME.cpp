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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAXN 1000000
bitset<MAXN + 10> isPrime;
void sieve() {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	FOR(i, 2, 1+MAXN) {
		if(isPrime[i]) {
			for(ll j = (ll)i*(ll)i; j <= MAXN; j += i) isPrime[j] = 0;
		}
	}
}
int T, n, q, type, x, y, v, a[10000 + 5], lazy[40000 + 5], st[40000 + 5];
int build(int p, int l, int r) {
	if(l == r) return st[p] = isPrime[a[l]];
	return st[p] = build(p << 1, l, (l+r)>>1) + build(p<<1|1, ((l+r)>>1) + 1, r);
}
void update(int p, int l, int r) {
	if(lazy[p]) {
		st[p] = (lazy[p]+1) ? r-l+1: 0;
		if(l!=r) lazy[p<<1] = lazy[p<<1|1] = lazy[p];
		lazy[p] = 0;
	}
	if(x > r || y < l) return;
	if(x <= l && r <= y) {
		st[p] = (isPrime[v]) ? r-l+1: 0;
		if(l!=r) lazy[p<<1] = lazy[p<<1|1] = ((int)isPrime[v]<<1)-1;
		return;
	}
	update(p<<1,  l,(l+r)>>1);
	update(p<<1|1,((l+r)>>1)+1,r);
	st[p] = st[p<<1] + st[p<<1|1];
}
int query(int p, int l, int r) {
	if(lazy[p]) {
		st[p] = (lazy[p]+1) ? r-l+1: 0;
		if(l!=r) lazy[p<<1] = lazy[p<<1|1] = lazy[p];
		lazy[p] = 0;
	}
	if(x > r || y < l) return 0;
	if(x <= l && r <= y)
		return st[p];
	return query(p<<1,l,(l+r)>>1) + query(p<<1|1,((l+r)>>1)+1,r);
}
int main() {
	sieve();
	scanf("%d", &T);
	FOR(caseNum, 1, T+1) {
		printf("Case %d:\n", caseNum);
		scanf("%d%d",&n, &q);
		FOR0(i, n) scanf("%d", a+i+1);
		build(1,1,n);
		memset(lazy,0,sizeof(int)*(4*n + 5));
		while(q--) {
			scanf("%d%d%d",&type,&x,&y);
			if(type) {
				printf("%d\n", query(1,1,n));
			}  else {
				scanf("%d",&v);
				update(1,1,n);
			}
		}
	}
}