#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 300005
#define maxq 1000000001
int n, m, o, p[maxn], k, lq[maxn], rq[maxn], a[maxn], lt[maxn], rt[maxn], ans[maxn];
ll ft[maxn];
void update(int i, int val) {
	while(i <= m) {
		ft[i] += val;
		i += i&(-i);
	}
}
ll query(int i) {
	ll ret = 0;
	while(i) {
		ret += ft[i];
		i -= i&(-i);
	}
	return ret;
}
int main() {
	vvi s(maxn), check(maxn);
	scanf("%d%d", &n, &m);
	FOR0(i, m) {
		scanf("%d", &o);
		s[o].pb(i+1);
	}
	FOR0(i, n) scanf("%d", p+i+1);
	scanf("%d", &k);
	FOR(i, 1, k+1) scanf("%d%d%d", lq+i, rq+i, a+i);
	FOR0(i, n) lt[i+1] = 1;
	FOR0(i, n) rt[i+1] = k;
	while(1) {
		bool done = true;
		FOR(i, 1, n+1) {
			if(lt[i] <= rt[i]) {
				check[(lt[i] + rt[i]) >> 1].pb(i);
				done = false;
			}
		}
		if(done) break;
		memset(ft, 0, sizeof ft);
		FOR(i, 1, k+1) {
			if(lq[i] <= rq[i]) {
				update(lq[i],a[i]);
				update(rq[i]+1,-a[i]);
			}
			else {
				update(1,a[i]);
				update(rq[i]+1,-a[i]);
				update(lq[i],a[i]);
			}
			for(int cur : check[i]) {
				ll amt = 0;
				for(int memb: s[cur]) {
					amt += query(memb);
					if(amt >= p[cur]) {
						ans[cur] = i;
						rt[cur] = i-1;
						break;
					}
				}
				if(amt < p[cur]) lt[cur] = i+1;
			}
			check[i].clear();
		}
	}
	FOR(i,1,n+1)
		if(ans[i]) printf("%d\n",ans[i]);
		else printf("NIE\n");
}