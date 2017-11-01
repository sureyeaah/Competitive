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
int st[100000*8 + 10];
bitset<100000 + 10> bs;
void check(int p, int l, int r) {
	bs[st[p]] = 1;
	if(l == r || st[p]) return;
	check(p<<1,l,(l+r)>>1);
	check(p<<1|1,((l+r)>>1)+1,r);
}
void build(int p, int l, int r, int val, int x, int y) {
	if(y < l || x > r) return;
	if(x <= l && r <= y) {
		st[p] = val;
		return;
	}
	if(st[p]) {
		st[p<<1] = st[p<<1|1] = st[p];
		st[p] = 0;
	}
	build(p<<1,l,(l+r)>>1,val,x,y);
	build(p<<1|1,((l+r)>>1)+1,r,val,x,y);
}
int main() {
	int t, n, l, r, start[100000 + 10], coordinates, end[100000 + 10];
	scanf("%d", &t);
	FOR(caseNum,1,t+1) {
		scanf("%d", &n);
		coordinates = 2*n;
		bs.reset();
		FOR(i, 1, n+1)
			scanf("%d%d", start + i, end + i);
		memset(st,0,sizeof(int)*(coordinates*4 + 5));
		FOR(i,1,n+1)
			build(1,1,coordinates,i,start[i],end[i]);
		check(1,1,coordinates);
		printf("Case %d: %d\n", caseNum,bs.count() - bs[0]);
	}
}