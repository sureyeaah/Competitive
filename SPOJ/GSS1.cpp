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
#define left(p) (p << 1)
#define right(p) ((p<<1)+1)
struct i4 {
	int lsum;
	int rsum;
	int tsum;
	int msum;
	i4(int x, int y) {
		lsum = rsum = msum = x;
		tsum = y;
	}
	i4() {
		i4(0, 0);
	}
	void add(i4 l, i4 r) {
		lsum = max(l.tsum+r.lsum,l.lsum);
		rsum = max(r.tsum+l.rsum,r.rsum);
		msum = max(l.rsum+r.lsum,max(l.msum,r.msum));
		tsum = l.tsum + r.tsum;
	}
};

int n, m, x, y, a[50000 + 10];
i4 sumtree[(1 << 17) + 10];

void build(int p, int l, int r) {
	if(l == r) {
		sumtree[p] = i4(a[l],a[l]);
		return;
	}
	build(left(p),l,(l+r) >> 1);
	build(right(p),((l+r) >> 1) + 1, r);
	sumtree[p].add(sumtree[left(p)], sumtree[right(p)]);
}

i4 query(int p, int l, int r) {
	if(l > r || x > r || y < l) {
		return i4(-INF,0);
	}
	if(l >= x && r <= y) return sumtree[p];
	i4 tmp;
	tmp.add(query(left(p),l,(l+r) >> 1), query(right(p),((l+r) >> 1) + 1, r));
	return tmp;
}
int main() {
	scanf("%d",&n);

	FOR0(i, n) scanf("%d", a + i + 1);
	build(1,1,n);
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d",&x,&y);
		printf("%d\n",query(1,1,n).msum);
	}
}