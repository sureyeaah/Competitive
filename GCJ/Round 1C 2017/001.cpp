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
	const double PI = 2*acos(0.0);
	SYNC;
	int t, n, k, r[1001], h[1001];
	pair<ll,int> rh[1001];
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> n >> k;
		FOR0(i, n) cin >> r[i] >> h[i];
		FOR0(i, n) rh[i] = mp((ll)r[i]*(ll)h[i],r[i]);
		sort(rh,rh+n,greater<pair<ll,int>>());
		ll ans = 0;
		FOR0(i, k) ans += 2L*rh[i].ff;
		int bestR = 0;
		FOR0(i, k) bestR = max(bestR, rh[i].ss);
		ans += (ll)bestR*(ll)bestR;
		cout << printCase() << fixed << setprecision(7) << PI*(double)(ans) << endl;
	}
}