#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
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
int n, x, cnt[10000001] = {}, f[10000001] = {};
bitset<10000001> bs;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for(int i = 2; i <= 10000000; i++) {
		if(bs[i]) {
			for(int j = i; j <= 10000000; j+=i) {bs[j] = 0; f[i] += cnt[j];}
		}
	}
}
int main() {
	SYNC;
	cin >> n;
	FOR0(i, n) {cin >> x; cnt[x]++;}
	sieve();
	int m, l, r;
	cin >> m;
	FOR0(i,10000000) f[i+1] += f[i];
	while(m--) {
		cin >> l >> r;
		l=min(10000000,l); r=min(10000000,r);
		cout << f[r] - f[l-1] << endl;
	}
}