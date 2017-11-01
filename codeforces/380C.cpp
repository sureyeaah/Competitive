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
typedef struct node {
	int correct = 0;
	int l = 0;
	int r = 0;
	node() {
		correct = l = r = 0;
	}
	node(int x, int y, int z) {
		correct = x;
		l = y;
		r = z;
	}
} node;
node combine(node a, node b) {
	node ret;
	ret.correct = a.correct + b.correct + min(a.r,b.l);
	ret.l = a.l + max(b.l - a.r, 0);
	ret.r = b.r + max(a.r - b.l, 0);
	return ret;
}
int n;
node st[2000000 + 5];
string s;
int query(int l, int r) {
	node resl = node(), resr = node();
	for(l+=n-1, r+=n-1; l <= r; l >>= 1, r>>=1) {
		if(l&1) resl = combine(resl, st[l++]);
		if(!(r&1)) resr = combine(st[r--], resr);
	}
	return combine(resl, resr).correct;
}
int main() {
	int l, r,m;
	cin >> s;
	n = s.length();
	FOR0(i, n) st[n+i] = s[i]=='(' ? node(0,0,1) : node(0,1,0);
	FORD(i,1,n) st[i] = combine(st[i<<1],st[i<<1|1]);
	cin >> m;
	while(m--) {
		cin >> l >> r;
		printf("%d\n", 2*query(l ,r));
	}
}