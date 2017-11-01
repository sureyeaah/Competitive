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
int st[(100000+10)*8], lazy[(100000+10)*8];
void update(int p, int l, int r, int x, int y) {
	if(lazy[p]) {
		st[p] += lazy[p];
		if(l!=r) {
			lazy[p<<1] += lazy[p];
			lazy[p<<1|1] += lazy[p];
		}
		lazy[p] = 0;
	}
	if(y < l || x > r) return;
	if(x <= l && r <= y) {
		st[p]++;
		if(l!=r) {
			lazy[p<<1]++;
			lazy[p<<1|1]++;
		}
		return;
	}
	update(p<<1,l,(l+r)>>1,x,y);
	update(p<<1|1,((l+r)>>1)+1,r,x,y);
	st[p] = max(st[p<<1], st[p<<1|1]);
}
int query(int p, int l, int r, int x, int y) {
	if(lazy[p]) {
		st[p] += lazy[p];
		if(l!=r) {
			lazy[p<<1] += lazy[p];
			lazy[p<<1|1] += lazy[p];
		}
		lazy[p] = 0;
	}
	if(y < l || x > r || x > y) return 0;
	if(x <= l && r <= y)
		return st[p];
	return max(query(p<<1,l,(l+r)>>1,x,y), query(p<<1|1,((l+r)>>1)+1,r,x,y));
}
int n,x,y,q,l,r,coordinates = 0;
ii coord[100000+10];
map<int,int> compress;
int main() {
	scanf("%d", &n);
	FOR0(i, n) {
		scanf("%d%d",&x,&y);
		coord[i] = mp(x,y);
		compress[x] = compress[y] = 1;
	}
	repi(i,compress)
		i->second = ++coordinates;
	vi start(coordinates+1, 0), end(coordinates + 1, 0);
	FOR0(i, n) start[compress[coord[i].first]]++;
	FOR0(i, n) end[compress[coord[i].second]]++;
	FOR0(i, n)
		update(1,1,coordinates,compress[coord[i].first],compress[coord[i].second]);
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d", &x, &y);
		auto it1 = compress.lower_bound(x), it2 = compress.lower_bound(y);
		l = (it1->first == x || it1==compress.begin()) ? it1->second : it1->second-1;
		if(it1==compress.end()) l = coordinates + 1;
		r = (it2 == compress.begin() && it2->first != y) ? -100 : it2->second;
		if(it2==compress.end()) r = coordinates;
		int ans = 0;		
		if(l <= r) {
			ans = query(1,1,coordinates,l+1,r-1);
			ans = max(ans, query(1,1,coordinates,l,l)-((it1->first == x)?0:end[l]));
			ans = max(ans, query(1,1,coordinates,r,r)-((it2->first == y)?0:start[r]));

		}
		printf("%d\n", ans);
	}
}