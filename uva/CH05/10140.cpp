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
vi primes; bitset<46341> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i < 46341; i++) {
		if(bs[i]) {
			for(ll j = i*i; j < 46341; j+=i)
				bs[j] = 0;
			primes.pb((int)i);
		}
	}
}
int main() {
	int l, u;
	sieve();
	bitset<1000001> isPrime;
	while(scanf("%d%d", &l, &u) != EOF) {
		isPrime.set(); if(l==1) isPrime[0] = 0;
		for(int p : primes) {
			for(int j = ((int)(u/p))*p, x = max(l, p+1); j >= x; j -= p)
				isPrime[j-l] = 0;
		}
		int c = 0, d = 0, closest = INF, farthest = 0, prev = 0;
		for(int i = u; i >= l; i--) {
			if(isPrime[i-l]) {
				if(prev) {
					if(prev - i <= closest) {c = i; closest = prev - i;}
					if(prev - i >= farthest) {d = i; farthest = prev - i;}
				}
				prev = i;
			}
		}
		if(c) printf("%d,%d are closest, %d,%d are most distant.\n",c,c+closest,d,d+farthest);
		else printf("There are no adjacent primes.\n");
	}
}