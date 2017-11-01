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
#define MAXN 30005
int n, q, lq, rq, k, st[4*MAXN], x;
int a[MAXN];
void update(int p, int l, int r, int i) {
	if(l > i || r < i) return;
	st[p]++;
	if(l == r) return;
	update(p<<1, l, (l+r)>>1, i);
	update(p<<1|1,((l+r)>>1) + 1, r, i);
}
int query(int p, int l, int r) {
	if(rq < l || lq > r) return 0;
	if(lq <= l && r <= rq) return st[p];
	return query(p << 1, l, (l+r)>>1) + query(p<<1|1,((l+r)>>1) + 1, r);
}
int main() {
	scanf("%d", &n);
	vii num;
	FOR0(i, n) {
		scanf("%d", &x);
		num.pb(mp(x,i+1));
	}
	sort(num.begin(), num.end());
	scanf("%d", &q);
	vector<pair<ii,ii> > qq; int ans[200000 + 10];
	FOR0(i, q) {
		scanf("%d%d%d",&lq,&rq,&k);
		qq.pb(mp(mp(-k,i), mp(lq, rq)));
	}
	sort(qq.begin(), qq.end());
	int last_k = INF;
	repi(i, qq) {
		k = -i->ff.ff;
		if(k < last_k) {
			for(auto it = upper_bound(num.begin(), num.end(), mp(k+1,-1)); it != num.end() && !a[it->ss]; it++) {
				//cout << k << "-" << it->ff << "-" << it->ss << endl;
				a[it->ss] = 1;
				update(1,1,n,it->ss);
			}
			last_k = k;
		}
		lq = i->ss.ff; rq = i->ss.ss;
		ans[i->ff.ss] = query(1,1,n);
	}
	FOR0(i, q) printf("%d\n", ans[i]);
}