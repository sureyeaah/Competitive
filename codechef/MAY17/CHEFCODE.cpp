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
ll k;
void generate(ll *a, int n, vector<ll> & v) {
	FOR(j, 1, 1 << n) {
		ll x = 1;
		FOR0(i, n) {
			if(j & (1 << i)) {
				if(x <= k/a[i]) x*= a[i];
				else {x = 0; break;}
			}
		}
		if(x) v.pb(x);
	}
}
int main() {
	SYNC;
	int n;
	ll a[35];
	cin >> n >> k;
	FOR0(i, n) cin >> a[i];
	vector<ll> x(1,1L),y(1,1L);
	generate(a,n/2,x);
	generate(a+n/2,n-n/2,y); sort(y.begin(), y.end());
	ll ans = -1;
	for(ll i : x) {
		ans += (ll) (upper_bound(y.begin(), y.end(), k/i) - y.begin());
	}
	cout << ans;
}