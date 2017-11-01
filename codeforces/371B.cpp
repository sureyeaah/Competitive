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
	int primes[3] = {2,3,5};
	int a[2], b[2], cnt[2][3] = {};
	cin >> a[0] >> a[1];
	b[0] = a[0]; b[1] = a[1];
	FOR0(i, 2) {
		FOR0(j, 3) {
			while(!(b[i]%primes[j])) {b[i]/=primes[j]; cnt[i][j]++;}
		}
	}
	int ans = -1;
	if(b[1] == b[0]) {
		ans = 0;
		FORD(j,0,3) {
			FOR0(i, 2) if(cnt[i][j] > cnt[1-i][j]) {
				ans += cnt[i][j] - cnt[1-i][j];
				//cnt[i][0] += i*(cnt[i][j] - cnt[1-i][j]);
			}
		}
	}
	cout << ans << endl;
}