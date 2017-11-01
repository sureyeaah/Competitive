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

int main() {
	SYNC;
	ll h, w; cin >> h >> w;
	if(h*w % 3 == 0) cout << 0 << endl;
	else if(h==2 || w==2) cout << 1 << endl;
	else {
		ll ans = 100000000000000;
		FOR(i, 1, w) {
			ll a = h*(ll)i, b = (w-i)*((h)/2), c = h*w-a-b;
			ll smax = max(max(a,b), c), smin = min(min(a,b), c); 
			ans = min(ans, smax - smin);
		}
		FOR(i, 1, w-1) {
			ll a = h*(ll)i, b = ((w-i)/2)*(h), c = h*w-a-b;
			ll smax = max(max(a,b), c), smin = min(min(a,b), c); 
			ans = min(ans, smax - smin);
		}
		swap(h, w);
		FOR(i, 1, w) {
			ll a = h*(ll)i, b = (w-i)*((h)/2), c = h*w-a-b;
			ll smax = max(max(a,b), c), smin = min(min(a,b), c); 
			ans = min(ans, smax - smin);
		}
		FOR(i, 1, w-1) {
			ll a = h*(ll)i, b = ((w-i)/2)*(h), c = h*w-a-b;
			ll smax = max(max(a,b), c), smin = min(min(a,b), c); 
			ans = min(ans, smax - smin);
		}
		cout << ans << endl;
	}
}