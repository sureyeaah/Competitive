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
#define MOD 4294967296L
map<int,ll> f;
bitset<100000001> bs;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for(int i = 2; i<10000; i++) {
		if(bs[i]) {
			for(int j = i*i; j <= 100000000; j+= i) bs[j] = 0;
			for(ll j = i; j <= 100000000; j*=i) f[(int)j] = i;
		}
	}
	for(int i = 10000; i<=100000000; i++) if(bs[i]) f[i] = i;
}
int main() {
	SYNC;
	sieve();
	f[1] = 1;
	int t;
	ll n;
	cin >> t;
	ll previous = 1; 
	repi(i, f) {i->ss = (i->ss*previous)%MOD; previous = i->ss; }
	while(t--) {
		cin >> n;
		cout << (--(f.upper_bound(n))) -> ss << endl;
	}
}