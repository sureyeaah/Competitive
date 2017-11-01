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
	int t, n, q, l[100005], k;
	ll sum[100005];
	SYNC;
	cin >> t;
	while(t--) {
		cin >> n >> q;
		FOR0(i, n) cin >> l[i];
		sort(l, l+n, greater<int>());
		sum[0] = 0;
		FOR0(i, n) sum[i+1] = sum[i]+l[i];
		while(q--) {
			cin >> k;
			int ans = lower_bound(l, l+n, k, [](int a, int b) {return a >= b;}) - l;
			int lt = 0, rt = n-ans-1, r = 0;
			while(lt <= rt) {
				int mid = (lt+rt)>>1;
				if(ans + (mid*1LL)*(k+1)-(sum[ans+mid]-sum[ans]) <= n) {r = mid; lt = r+1;}
				else rt = mid-1;
			}
			cout << ans+r << endl;
		}
	}
}