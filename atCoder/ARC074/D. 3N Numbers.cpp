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
int main() {SYNC;
	ll ans = -(1e16);
	int n, a[3*100000 + 5];
	ll sl[3*100000 + 5] = {}, sr[3*100000 + 5] = {};
	cin >> n; FOR0(i, 3*n) cin >> a[i];
	priority_queue<int,vi,greater<int>> pq;
	FOR0(i, 3*n) {
		sl[i] += a[i];
		pq.push(a[i]);
		if(i >= n) {
			sl[i] -= pq.top(); pq.pop();
		}
		sl[i+1] = sl[i];
	}
	priority_queue<int,vi> pq2;
	FORD(i, 1, 3*n) {
		sr[i] += a[i];
		pq2.push(a[i]);
		if(i < 2*n) {
			sr[i] -= pq2.top(); pq2.pop();
		}
		sr[i-1] = sr[i];
	}
	FOR(i,n-1,2*n) ans = max(ans, sl[i] - sr[i+1]);
	cout << ans << endl;
}