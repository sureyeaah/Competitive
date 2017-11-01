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
#define MOD 1000000007
vi primes; bitset<1000001> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i <= 1000000; i++) {if(bs[i]) {
		for(ll j = i*i; j <= 1000000; j+=i) bs[j] = 0;
		primes.pb((int)i);
	}}
}
int main() {
	SYNC; sieve();
	ll n, k;
	cin>>n>>k;
	k=(k+1)/2;
	while(k && n>1) {
		ll x = n;
		for(int p : primes) {
			if(x%p == 0) {
				n=(n/p)*(p-1);
				while(x%p == 0) x/=p;
			}
		}
		if(x > 1) n = (n/x)*(x-1);
		k--;
	}
	cout << n%MOD << endl;
}