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

int main() {
	SYNC;
	int n, k, a[100005];
	ll preSum[100005];
	cin >> n >> k;
	FOR0(i,n) cin >> a[i];
	map<ll,vi> m;
	ll sum = 0;
	m[0].pb(-1);
	FOR0(i, n) {
		sum += a[i];
		m[sum].pb(i);
		preSum[i] = sum;
	}
	ll ans = 0;
	ll pk = 1;
	ll inf = pow(10L,14);
	while(abs(pk) <= inf) {
		FOR0(i,n) {
			int currVal = 0;
			for(int curr: m[preSum[i]-pk]) {
				if(curr >= i) break;
				currVal++;
			}
			ans += currVal;
		}
		pk *= k;
		if(abs(k)==1 && pk==1) break;
	}
	cout << ans << endl;
}