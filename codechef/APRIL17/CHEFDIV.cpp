#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
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
bitset<1000000 + 10> bs;
vi primes;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	FOR(i,2,1000000) { if(bs[i]) {
			primes.pb(i);
			for(ll j = (ll)i*(ll)i; j <= 1000000; j+=i) {
				bs[j] = 0;
			}
		}
	}
}
vvi cnt;
ll num[100000 + 10];

int main() {
	sieve();
	ll a, b;
	cin >> a >> b;
	int n = b-a+1;
	FOR0(i, n) num[i] = a+(ll)i;
	cnt.assign(n, vi(0));
	ll ans = 0;
	for (auto it = primes.begin(), last = upper_bound(primes.begin(), primes.end(), (int)ceil(pow((double) b,0.5))); it != last; it++) {
		int p = *it;
		int start = (a%p) ? (p-(a%p)): 0;
		for(int j = start; j < n; j += p) {
			int curr = 1;
			while(!(num[j]%p)) {
				num[j] /= p;
				curr++;
			}
			cnt[j].pb(curr);
		}
	}
	FOR0(i, n) if(num[i] != 1) cnt[i].pb(2);
	FOR0(i, n) {
		ll prod = 1;
		repi(it, cnt[i]) prod *= (ll)(*it);
		priority_queue<int> pq;
		repi(it, cnt[i]) pq.push(*it);
		ans += prod;
		while(!pq.empty()) {
			int x = pq.top(); pq.pop();
			prod = (prod/(ll)x)*(ll)(x-1);
			ans += prod;
			if(x>2) pq.push(x-1); 
		}
	}
	cout << ans-n << endl;
}