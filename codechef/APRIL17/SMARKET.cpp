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
#define MAXN 100005

typedef struct node {
	int ans = 0;
	int l = 0;
	int r = 0;
	int lc = 0;
	int rc = 0;
	int size = 0;
	node (int a1, int a2, int a3, int a4, int a5, int a6) {
		ans = a1;
		l = a2;
		lc = a3;
		r = a4;
		rc = a5;
		size = a6;
	}
	node () {
		node(0,0,0,0,0,0);
	}
} node;
int lq, rq, k;
vi st[4*MAXN];
pair<ii,ii> lr[4*MAXN];
int a[MAXN];
void build(int p, int l, int r) {
	if(l == r) {
		st[p].assign(2,1);
		lr[p] = mp(mp(a[l],1), mp(a[l], 1));
		return;
	}
	build(p<<1,l,(l+r)>>1); build(p<<1|1,((l+r)>>1) + 1, r);
	st[p].assign(r-l+2, 0);
	FOR0(i,(int)st[p<<1].size()) st[p][i] += st[p<<1][i];
	FOR0(i,(int)st[p<<1|1].size()) st[p][i] += st[p<<1|1][i];
	int x = lr[p<<1].ff.ss, y = lr[p<<1|1].ss.ss;
	if(lr[p<<1].ss.ff == lr[p<<1|1].ff.ff) {
		FOR0(i, min(lr[p<<1].ss.ss, lr[p<<1|1].ff.ss)+1) st[p][i]--;
		FOR(i, max(lr[p<<1].ss.ss, lr[p<<1|1].ff.ss)+1, lr[p<<1].ss.ss+lr[p<<1|1].ff.ss+1) st[p][i]++;
		if(st[p<<1].size()-1 == lr[p<<1].ss.ss) x+= lr[p<<1|1].ff.ss;
		if(st[p<<1|1].size()-1 == lr[p<<1|1].ff.ss) y+= lr[p<<1].ss.ss;
	}
	lr[p] = mp(mp(lr[p<<1].ff.ff, x), mp(lr[p<<1|1].ss.ff, y));
}


node query(int p, int l, int r) {
	if(l > rq || r < lq) return node();
	if(l >= lq && r <= rq) {
		return node((k<=r-l+1 ? st[p][k]: 0),lr[p].ff.ff,lr[p].ff.ss,lr[p].ss.ff,lr[p].ss.ss,r-l+1);
	}
	node left = query(p<<1,l,(l+r)>>1);
	node right = query(p<<1|1,((l+r)>>1)+1,r);
	node ret = node();
	ret.ans = left.ans + right.ans;
	ret.l = left.l; ret.r = right.r; ret.lc = left.lc; ret.rc = right.rc; ret.size = left.size + right.size;
	if(left.r == right.l && left.r) {
		ret.ans += -(int)(left.rc>=k) - (int)(right.lc>=k) + (int)(left.rc+right.lc>=k);
		if(left.lc == left.size) ret.lc += right.lc;
		if(right.rc == right.size) ret.rc += left.rc;
	}
	return ret;
}
int main() {
	int t, n, q;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &q);
		FOR0(i, n) scanf("%d", a+i+1);
		build(1,1,n);
		FOR0(i, q) {
			scanf("%d %d %d", &lq, &rq, &k);
			printf("%d\n", query(1,1,n).ans);
		}
	}
}