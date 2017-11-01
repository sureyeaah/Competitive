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
int n, m, a[100000 + 1], x, y, st[400000 + 5], st2[400000 + 5];
char type;
void build(int p, int l, int r) {
	if(l == r) {
		st[p] = st2[p] = l;
		return ;
	}
	build(left(p),l,(l+r) >> 1);
	build(right(p),((l+r) >> 1) + 1, r);
	st[p] = (a[st[left(p)]] >= a[st[right(p)]]) ? st[left(p)]: st[right(p)];
	st2[p] = (a[st2[left(p)]] >= a[st2[right(p)]]) ? st2[left(p)]: st2[right(p)];
	int val = st[left(p)] + st[right(p)] - st[p];
	st2[p] = (a[st2[p]] >= a[val] && st[p] != st2[p]) ? st2[p]: val;
}
ii query(int p, int l, int r) {
	if(y < l || x > r) return mp(0,0);
	if(l >= x && r <= y) return mp(st[p],st2[p]);
	ii c1 = query(left(p),l,(l+r) >> 1);
	ii c2 = query(right(p),((l+r) >> 1) + 1, r);
	int val1 = ((a[c1.first] >= a[c2.first]) ? c1.first: c2.first);
	int val2 = ((a[c1.second] >= a[c2.second]) ? c1.second: c2.second);
	int val3 = c1.first + c2.first - val1;
	val2 = (a[val2] >= a[val3] && val1 != val2) ? val2 : val3;
	return mp(val1,val2);
}
void update(int p, int l, int r) {
	if(x < l || x > r) return;
	if(l == r) {
		return ;
	}
	update(left(p),l,(l+r) >> 1);
	update(right(p),((l+r) >> 1) + 1, r);
	st[p] = (a[st[left(p)]] >= a[st[right(p)]]) ? st[left(p)]: st[right(p)];
	st2[p] = (a[st2[left(p)]] >= a[st2[right(p)]]) ? st2[left(p)]: st2[right(p)];
	int val = st[left(p)] + st[right(p)] - st[p];
	st2[p] = (a[st2[p]] >= a[val] && st[p] != st2[p]) ? st2[p]: val;
}
int main() {
	scanf("%d", &n);
	a[0] = -INF;
	FOR0(i, n) scanf("%d", a + i + 1);
	build(1,1,n);
	scanf("%d", &m);
	while(m--) {
		scanf("%*c%c%d%d",&type,&x,&y);
		if(type == 'Q') {
			ii ans = query(1,1,n);
			printf("%d\n",a[ans.first] + a[ans.second]);
		} else {
			a[x] = y;
			update(1,1,n);
		}
	}
}