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
int n, ans = 0, a[MAXN], q, lq, rq, k;
int main() {
	scanf("%d", &n);
	int len = (int)ceil(sqrt((double)n)), parts = ceil((double)n/len);
	vvi v(parts);
	FOR0(i, n) scanf("%d", a + i);
	FOR0(i, parts) {
		v[i].insert(v[i].begin(), a+i*len, a+min(n,(i+1)*len));
		sort(v[i].begin(), v[i].end());
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d%d",&lq,&rq,&k);
		lq ^= ans;
		rq   ^= ans;
		k     ^= ans;
		lq--; rq = min(rq, n)-1;
		ans = 0;
		if(!(lq > n-1 || rq < 0)) {
			while(lq<=rq && lq%len) {
				if(a[lq++] > k) ans++;
			}
			while(lq<=rq && (rq+1)%len) {
				if(a[rq--] > k) ans++;
			}
			FOR(i, lq/len, (rq+1)/len) ans += v[i].end() - upper_bound(v[i].begin(), v[i].end(), k);
		}
		printf("%d\n", ans);
	}
}