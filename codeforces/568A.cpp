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
vi primes; bitset<10000001> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i < 5000001; i++) {
		if(bs[i]) {
			for(ll j = i*i; j < 5000001; j+=i)
				bs[j] = 0;
		}
	}
}
int main() {
	sieve();
	ll p,q;
	cin >> p >> q;
	int x = 0, y = 0; int ans = 1;
	FOR(i,1,5000001) {
		if(bs[i]) x++;
		int num1 = i, num2 = 0;
		while(num1) {
			num2 = num2*10 + (num1%10);
			num1/=10;
		}
		if(num2 == i) y++;
		if(q*x <= p*y) ans = i;
	}
	cout << ans;
}