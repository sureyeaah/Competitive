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
vi primes;
bitset<1000001> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i < 1000001; i++) {if(bs[i]) {
		for(ll j = i*i; j < 1000001; j+=i) bs[j] = 0;
		primes.pb((int)i);
	}}
}
int a, b, k;
bool possible(int l) {
	int stored = 0;
	FOR(i,a,a+l) if(bs[i]) stored++;
	int i = a+1;
	while(stored >= k && i <= b-l+1) {
		if(bs[i-1]) stored--;
		if(bs[i+l-1]) stored++;
		i++;
	} 
	if(stored >= k) return true;
	return false;
}
int main() {
	cin >> a >> b >> k;
	sieve();
	int l = 0, r = b-a+1;
	int ans = -1;
	while(l <= r) {
		int mid = (l+r+1)/2;
		if(possible(mid)) {r = mid-1; ans = mid;}
		else l = mid + 1;
	}
	cout << ans;
}