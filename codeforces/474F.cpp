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
int gcd(int a, int b) {
	return (b) ? gcd(b,a%b) : a;
}
ii st[(100000 + 10)*4];
int s[100000 + 5];
bitset<(100000 + 10)*4> bs;
ii combine(const ii &a, const ii &b, bool hasOne) {
	ii ret;
	ret.ss = gcd(a.ss, b.ss);
	if (ret.ss == a.ss) ret.ff +=  a.ff;
	if (ret.ss == b.ss) ret.ff +=  b.ff;
	if(ret.ss == 1 && !hasOne) ret.ff = 0;
	return ret;
}
void build(int p, int l, int r) {
	if(l == r) {
		st[p] = mp(1,s[l]);
		if(s[l] == 1) bs[p] = 1;
		return;
	}
	build(p<<1,l,(l+r)>>1);
	build(p<<1|1,((l+r)>>1)+1,r);
	bs[p] = bs[p<<1] || bs[p<<1|1];
	st[p] = combine(st[p<<1],st[p<<1|1], bs[p]);
}
pair<ii,bool> query(int p, int l, int r, int lq, int rq) {
	if(lq > r || rq < l)
		return mp(mp(-1,0),false);
	if(lq <= l && r <= rq)
		return mp(st[p],bs[p]);
	pair<ii,bool> q1 = query(p<<1,l,(l+r)>>1,lq,rq);
	pair<ii,bool> q2 = query(p<<1|1,((l+r)>>1)+1,r,lq,rq);
	//if(q1.ff.ff==-1) return q2;
	//else if(q2.ff.ff==-1) return q1;
	return mp(combine(q1.ff,q2.ff,q1.ss||q2.ss), q1.ss||q2.ss);
}
int main() {
	int n, t, l, r;
	scanf("%d", &n);
	FOR0(i, n) scanf("%d", s+i+1);
	build(1,1,n);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &l, &r);
		printf("%d\n",r-l+1-query(1,1,n,l,r).ff.ff);
	}
}