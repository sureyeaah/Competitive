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
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
int n, a[100000 + 5], m, t, li, ri, x;
int st[20][400000 + 5];
bitset<400000 + 5> lazy[20];
void build(int p, int l, int r) {
	if(l == r) {
		FOR0(i, 20) st[i][p] = (a[l]>>i)&1;
		return;
	}
	build(p << 1, l, (l+r)>>1);
	build(p<<1|1,((l+r)>>1)+1,r);
	FOR0(i, 20) st[i][p] = st[i][p<<1] + st[i][p<<1|1];
}
void update(int p, int l, int r, int i) {
	if(lazy[i][p]) {
		st[i][p] = r-l+1-st[i][p];
		if(l!=r) {
			lazy[i].flip(p<<1);
			lazy[i].flip(p<<1|1);
		}
		lazy[i][p] = 0;
	}
	if(li > r || ri < l) return;
	if(li <= l && r <= ri) {
		st[i][p] = r-l+1-st[i][p];
		if(l!=r) {
			lazy[i].flip(p<<1);
			lazy[i].flip(p<<1|1);
		}
		return;
	}
	update(p<<1,l,(l+r)>>1,i);
	update(p<<1|1,((l+r)>>1)+1,r,i);
	st[i][p] = st[i][p<<1] + st[i][p<<1|1];
}
int query(int p, int l, int r, int i) {
	if(lazy[i][p]) {
		st[i][p] = r-l+1-st[i][p];
		if(l!=r) {
			lazy[i].flip(p<<1);
			lazy[i].flip(p<<1|1);
		}
		lazy[i][p] = 0;
	}
	if(li > r || ri < l) return 0;
	if(li <= l && r <= ri) return st[i][p];
	return query(p<<1,l,(l+r)>>1,i)+query(p<<1|1,((l+r)>>1)+1,r,i);
}
int main() {
	int t;
	scanf("%d", &n);
	FOR0(i, n) scanf("%d", a+i+1);
	build(1,1,n);
	scanf("%d", &m);
	while(m--) {
		scanf("%d",&t);
		if(t-1) {
			scanf("%d%d%d",&li,&ri,&x);
			FOR0(i, 20) if(x&(1<<i)) update(1,1,n,i);
		} else {
			scanf("%d%d",&li,&ri);
			ll ans = 0;
			FOR0(i, 20)
				ans += (ll)query(1,1,n,i)*(1L << i);
			printf("%I64d\n",ans);
		}
	}
}