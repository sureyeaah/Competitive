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
int t, n[3], q, type, st[3][4*100000 + 10], lazy[3][4*100000 + 10], lq[3], rq[3];
void update(int p, int l, int r, int x, int y, int i) {
	if(lazy[i][p]) {
		st[i][p] = r-l+1-st[i][p];
		if(l != r) {
			lazy[i][p<<1] ^= 1;
			lazy[i][p<<1|1] ^= 1;
		}
		lazy[i][p] = 0;
	}
	if(r < x || l > y) return;
	if(x <= l && r <= y) {
		st[i][p] = r-l+1-st[i][p];
		if(l != r) {
			lazy[i][p<<1] ^= 1;
			lazy[i][p<<1|1] ^= 1;
		}
		return;
	}
	update(p<<1,l,(l+r)>>1,x,y,i);
	update(p<<1|1,((l+r)>>1)+1,r,x,y,i);
	st[i][p] = st[i][p<<1]+st[i][p<<1|1];
}
int query(int p, int l, int r, int i) {
	if(lazy[i][p]) {
		st[i][p] = r-l+1-st[i][p];
		if(l != r) {
			lazy[i][p<<1] ^= 1;
			lazy[i][p<<1|1] ^= 1;
		}
		lazy[i][p] = 0;
	}
	if(r < lq[i] || l > rq[i]) return 0;
	if(lq[i] <= l && r <= rq[i]) {
		return st[i][p];
	}
	return query(p<<1,l,(l+r)>>1,i)+query(p<<1|1,((l+r)>>1)+1,r,i);
}
int main() {
	scanf("%d", &t);
	while(t--) {
		FOR0(i, 3) scanf("%d", n+i);
		scanf("%d", &q);
		FOR0(i, 3) FOR0(j, 4*(n[i]+1)+1) lazy[i][j] = st[i][j] = 0;
		while(q--) {
			scanf("%d", &type);
			if(type==3) {
				FOR0(i, 3) scanf("%d", &lq[i]);
				FOR0(i, 3) scanf("%d", &rq[i]);
				FOR0(i, 3) lq[i]++;
				FOR0(i, 3) rq[i]++;
				int red[3] = {};
				FOR0(i, 3) red[i] = query(1,1,n[i],i);
				//FOR0(i, 3) printf("%d ", red[i]);
				ll ans = 0;
				FOR0(i, 3) ans += (ll)red[i]*(ll)(rq[(i+1)%3]-lq[(i+1)%3]+1)*(ll)(rq[(i+2)%3]-lq[(i+2)%3]+1);
				FOR0(i, 3) ans -= 2L*(ll)red[i]*(ll)red[(i+1)%3]*(ll)(rq[(i+2)%3]-lq[(i+2)%3]+1);
				ans += 4L*(ll)red[0]*(ll)red[1]*(ll)red[2];
				printf("%lld\n", ans);
			} else {
				int i, j;
				scanf("%d%d", &i, &j);
				update(1,1,n[type],i+1,j+1,type);
			}
		}
	}
}