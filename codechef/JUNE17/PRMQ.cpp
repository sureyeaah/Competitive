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
#define pb emplace_back
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
#define maxn 100005
#define maxa 1000001
int n, a[maxn], q, lq[maxn], rq[maxn], xq[maxn], yq[maxn], ans[maxn]={}, ps[maxn];
bitset<1001> bs;
void solve() {
	bs.set(); bs[0]  = bs[1] = 0;
	FOR(i,2,1001) {
		if(!bs[i]) continue;
		for(int j = i*i; j <= 1000; j+= i) {
			bs[j] = 0;
		}
		ps[0] = 0;
		FOR(k, 1, n+1) {
			int cur = 0;
			while(a[k] % i == 0) {cur++; a[k] /= i;}
			ps[k] = ps[k-1] + cur;
		}
		FOR0(k, q) {
			if(i >= xq[k] && i <= yq[k]) ans[k] += ps[rq[k]] - ps[lq[k]-1];
		}
	}
}
int ft[maxn];
void update(int i) {
	while(i <= n) {
		ft[i]++;
		i += (i&(-i));
	}
}
int query(int i) {
	int ret = 0;
	while(i) {
		ret += ft[i];
		i -= (i&(-i));
	}
	return ret;
}
int main() {
	SYNC;
	scanf("%d", &n);
	FOR(i,1,n+1) scanf("%d", a+i);
	scanf("%d", &q);
	FOR0(i, q) scanf("%d%d%d%d", lq+i,rq+i,xq+i,yq+i);
	solve();
	vii arr;
	arr.reserve(n+q+q+2);
	FOR(i, 1, n+1) {
		if(a[i] > 1) arr.pb(mp(a[i], -i));
		else arr.pb(mp(-INF,-i));
	}
	FOR0(i, q) arr.pb(mp(yq[i], i));
	FOR0(i, q) arr.pb(mp(xq[i]-1, i+q));
	sort(arr.begin(), arr.end());
	for(ii & cur : arr) {
		if(cur.ss < 0)
			update(-cur.ss);
		else {
			if(cur.ss < q) ans[cur.ss] += (query(rq[cur.ss])-query(lq[cur.ss]-1));
			else ans[cur.ss-q] -= (query(rq[cur.ss-q])-query(lq[cur.ss-q]-1));
		}
	}
	FOR0(i, q) cout << ans[i] << '\n';
}