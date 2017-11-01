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
vi factors[1000001];
bitset<1000001> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(int i = 2; i < 350; i++) {if(bs[i]) {
		for(int j = i; j < 1000001; j+=i) {bs[j] = 0; factors[j].pb(i);}
	}}
}
int main() {
	SYNC;
	sieve();
	int n, a[100000 + 5];
	cin >> n;
	FOR0(i, n) cin >> a[i+1];
	a[0] = 1;
	int dp[100000 + 5] = {}, ans = 0;
	FORD(i,1,n+1) {
		int x = a[i], curr= 0;
		for(int j: factors[a[i]]) {
			dp[j]++;
			curr = max(dp[j], curr);
			while(!(x%j)) x/=j; 
		}
		if(x > 1) {dp[x]++; curr = max(dp[x], curr); dp[x] = curr;}
		for(int j: factors[a[i]]) dp[j] = curr;
		ans = max(ans, curr);
	}
	cout << max(ans,1) << endl;
}