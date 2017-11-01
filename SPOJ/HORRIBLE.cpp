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
#define left(v) (v << 1)
#define right(v) ((v<<1)+1)
int T,n,c,p,q,v,type;
ll st[262154],lazy[262154];
ll query(int p, int l, int r, int i, int j) {
	if(l > r || l > j || r < i) return 0;
	if(lazy[p]) {
		st[p] += (r-l+1)*lazy[p];
		if(l!=r) {
			lazy[left(p)] += lazy[p];
			lazy[right(p)] += lazy[p];
		}
		lazy[p] = 0;
	}
	if(l >= i && r <= j) return st[p];
	return query(left(p),l,(l+r)/2,i,j)
			+ query(right(p),(l+r)/2 + 1, r, i, j);
}
void update(int p, int l, int r, int i, int j, int val) {
	if(lazy[p]) {
		st[p] += (r-l+1)*lazy[p];
		if(l!=r) {
			lazy[left(p)] += lazy[p];
			lazy[right(p)] += lazy[p];
		}
		lazy[p] = 0;
	}
	if(l > r || l > j || r < i) return;
	if(l >= i && r <= j) {
		st[p] += (r-l+1)*(ll)val;
		if(l!=r) {
			lazy[left(p)] += val;
			lazy[right(p)] += val;
		}
		return;
	}
	update(left(p),l,(l+r)/2,i,j,val);
	update(right(p),(l+r)/2+1,r,i,j,val);
	st[p] = st[left(p)] + st[right(p)];
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&c);
		memset(st,0,sizeof st);
		memset(lazy,0,sizeof lazy);
		FOR0(i, c) {
			scanf("%d%d%d",&type,&p,&q);
			if(type) {
				printf("%lld\n",query(1,1,n,p,q));
			}
			else {
				scanf("%d",&v);
				update(1,1,n,p,q,v);
			}
		}
	}
}