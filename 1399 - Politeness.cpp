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
#define MOD 1000000007
vi primes;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i < 1000001; i++) {if(bs[i]) {
		for(ll j = i*i; j < 1000001; j+=i) bs[j] = 0;
		primes.pb((int)i);
	}}
}
int main() {
	SYNC;
	int t; ll p;
	cin >> t;
	double dp[2000000][40] = {};
	while(t--) {
		cin >> p;
		int ans = 1;
		ll n = p + 1;
		for(int i = 2, x = (int)ceil(sqrt((double)n)); i <= x; i++) if(!(n%i)) {factors.pb(i); factors.pb(n/i);}
		factors.pb(n);
		sort(factors.begin(), factors.end());
		FOR0(i,1,40) {
			FOR0(j, factors.size()) {
				dp[i]dp[j] = dp[i-1]
			}
		}
	}
}