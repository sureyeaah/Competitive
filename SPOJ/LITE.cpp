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
int n, m, operation, s, e, st[4000000 + 5], lazy[4000000 + 5];
int query(int p, int l, int r) {
	if(lazy[p]) {
		st[p] = r-l+1-st[p];
		if(l != r) {
			lazy[left(p)] = !lazy[left(p)];
			lazy[right(p)] = !lazy[right(p)];
		}
		lazy[p] = 0;
	}
	if(s > r || e < l) return 0;
	if(s <= l && e >= r) return st[p];
	return query(left(p),l,(l+r) >> 1) + query(right(p),((l+r) >> 1) + 1, r);
}
void update(int p, int l, int r) {
	if(lazy[p]) {
		st[p] = r-l+1-st[p];
		if(l != r) {
			lazy[left(p)] = !lazy[left(p)];
			lazy[right(p)] = !lazy[right(p)];
		}
		lazy[p] = 0;
	}
	if(s > r || e < l) return ;
	if(s <= l && e >= r) {
		st[p] = r-l+1-st[p];
		if(l != r) {
			lazy[left(p)] = !lazy[left(p)];
			lazy[right(p)] = !lazy[right(p)];
		}
		return;
	}
	update(left(p),l,(l+r) >> 1);
	update(right(p),((l+r) >> 1) + 1,r);
	st[p] = st[left(p)]+st[right(p)];
}
int main() {
	scanf("%d%d",&n, &m);
	memset(st,0,sizeof(int)*(4*n + 5));
	memset(lazy,0,sizeof(int)*(4*n + 5));
	while(m--) {
		scanf("%d%d%d",&operation,&s,&e);
		if(operation) printf("%d\n",query(1,1,n));
		else update(1,1,n);
	}
}