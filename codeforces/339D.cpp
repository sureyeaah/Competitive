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
#define left(p) (((p) << 1))
#define right(p) (((p) << 1 ) + 1)
int n, m, a[(1 << 17) + 5], st[(1 << 18) + 5];
int build(int p, int l, int r, int level) {
	if(l == r)
		return st[p] = a[l];
	if(!((n-level) & 1))
		return st[p] = build(left(p), l, (l+r)/2, level + 1) | build(right(p), (l+r)/2 + 1, r, level + 1);
	else
		return st[p] = build(left(p), l, (l+r)/2, level + 1) ^ build(right(p), (l+r)/2 + 1, r, level + 1);
}
int update(int p, int l, int r, int i, int x, int level) {
	if(i < l || i > r)
		return st[p];
	if(l == r)
		return st[p] = x;
	if(!((n-level) & 1))
		return st[p] = update(left(p), l, (l+r)/2, i, x, level + 1) | update(right(p), (l+r)/2 + 1, r, i, x, level + 1);
	else
		return st[p] = update(left(p), l, (l+r)/2, i, x, level + 1) ^ update(right(p), (l+r)/2 + 1, r, i, x, level + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	FOR(i,1,(1 << n) + 1) scanf("%d", a + i);
	build(1,1,(1 << n), 1);
	while(m--) {
		int p, b;
		scanf("%d%d", &p, &b);
		printf("%d\n", update(1,1,(1 << n),p,b,1));
	}
}