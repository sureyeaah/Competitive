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
#define mod 1000000007
#define modAdd(x) ((curr + ((x) % mod)) % mod)
#define modMul(x) ((curr * (x)) % mod)
int main() {
	SYNC;
	int t, p, q, r, a[100005], b[100005], c[100005], sa[100005], sc[100005];
	cin >> t;
	while(t--) {
		cin >> p >> q >> r;
		FOR0(i, p) cin >> a[i];
		FOR0(i, q) {
			cin >> b[i];
			b[i] %= mod;
		}
		FOR0(i, r) cin >> c[i];
		sort(a, a+p); sort(c,c+r);
		sa[0] = 0; FOR0(i, p) sa[i+1] = (sa[i]+a[i])%mod;
		sc[0] = 0; FOR0(i, r) sc[i+1] = (sc[i]+c[i])%mod;
		int ans = 0;
		FOR0(i, q) {
			int j = upper_bound(a, a+p, b[i])-a, k = upper_bound(c, c+r, b[i])-c;
			ll curr = b[i];
			curr = modMul(((ll)j * (ll)k) % mod);
			curr = modAdd((ll)k * (ll)sa[j]);
			curr = modAdd((ll)j * (ll)sc[k]);
			curr = (curr * b[i]) % mod;
			curr = modAdd((ll)sa[j] * (ll)sc[k]);
			ans = modAdd(ans);
		}
		cout << ans << endl;
	}	
}