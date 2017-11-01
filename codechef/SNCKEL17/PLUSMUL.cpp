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
#define mod ((ll)1e9 + 7LL)
#define invMOd ((mod + 1) >> 1)
#define addmod(x,y) (((((x)%mod) + ((y)%mod) % mod) + mod) % mod)
ll t, n, a[100005], pow2[100005];
ll fromStart() {
	ll cur = 1, ret = 0;
	FOR0(i, n-1) {
		cur = (cur * a[i]) % mod;
		ret = addmod(ret, pow2[n-i-2]*cur);
	}
	return ret;
}
ll prod() {
	ll cur = 1;
	FOR0(i, n) {
		cur = (cur * a[i]) % mod;
	}
	return cur;
}
int main() {
	SYNC;
	pow2[0] = 1;
	FOR(i, 1, 100005) pow2[i] = (2*pow2[i-1]) % mod;
	cin >> t;
	while(t--) {
		cin >> n;
		FOR0(i, n) cin >> a[i];
		ll ans = 0, cur = 0;
		FORD(i, 1, n-1) {
			if(cur & 1) cur = addmod(cur*invMOd, pow2[n-3]);
			else cur = addmod(cur/2, pow2[n-3]);
			cur = (cur * a[i]) % mod;
			ans = addmod(cur, ans);
		}
		ans = addmod(ans, fromStart());
		reverse(a, a+n);
		ans = addmod(ans, fromStart());
		ans = addmod(ans, prod());
		cout << ans << endl;
	}
}