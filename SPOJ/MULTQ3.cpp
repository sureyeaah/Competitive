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
int n, q, type, a, b, lazy[400000 + 5];
int st[400000 + 5][3];
void build(int p, int l, int r) {
	st[p][0] = st[p][1] = 0;
	st[p][2] = r-l+1;
	if(l==r) return;
	build(p<<1,l,(l+r)>>1);
	build(p<<1|1,((l+r)>>1)+1, r);
}

void update(int p, int l, int r) {
	if(lazy[p]) {
		swap(st[p][0], st[p][lazy[p]]);
		swap(st[p][0], st[p][3-lazy[p]]);
		if(l!=r) {
			lazy[p<<1] = (lazy[p<<1] + lazy[p])%3;
			lazy[p<<1|1] = (lazy[p<<1|1] + lazy[p])%3;
		}
		lazy[p] = 0;
	}
	if(b < l || a > r) return;
	if(a <= l && r <= b) {
		swap(st[p][0], st[p][1]);
		swap(st[p][0], st[p][2]);
		if(l!=r) {
			lazy[p<<1] = (lazy[p<<1] + 1)%3;
			lazy[p<<1|1] = (lazy[p<<1|1] + 1)%3;
		}
		return;
	}
	update(p<<1, l, (l+r)>>1);
	update(p<<1|1, ((l+r)>>1) + 1, r);
	st[p][0] = st[p<<1][0] + st[p<<1|1][0];
	st[p][1] = st[p<<1][1] + st[p<<1|1][1];
	st[p][2] = st[p<<1][2] + st[p<<1|1][2];
}
int query(int p, int l, int r) {
	if(lazy[p]) {
		swap(st[p][0], st[p][lazy[p]]);
		swap(st[p][0], st[p][3-lazy[p]]);
		if(l!=r) {
			lazy[p<<1] = (lazy[p<<1] + lazy[p])%3;
			lazy[p<<1|1] = (lazy[p<<1|1] + lazy[p])%3;
		}
		lazy[p] = 0;
	}
	if(b < l || a > r) return 0;
	if(a <= l && r <= b) {
		return st[p][2];
	}
	return query(p<<1, l, (l+r)>>1) + query(p<<1|1, ((l+r)>>1) + 1, r);	
}
int main() {
	scanf("%d%d", &n, &q);
	memset(lazy,0,sizeof(lazy));
	build(1,1,n);
	while(q--) {
		scanf("%d%d%d",&type, &a, &b);
		a++; b++;
		if(type)
			printf("%d\n",query(1,1,n));
		else
			update(1,1,n);
	}
}