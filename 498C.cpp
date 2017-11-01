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
int n, m, a[105], ik, jk;
vi primes; bitset<100000>;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i < 100000; i++) {if(bs[i]) {
		for(ll j = i*i; j < 100000; j+=i) bs[j] = 0;
		primes.pb((int)i);
	}}
}
vector<vii> graph[101], vis[101];
vvi pf(101);
int main() {
	SYNC;
	sieve();
	cin >> n >> m;
	FOR(i, 1, n+1) cin >> a[i];
	FOR(i, 1, n+1) {
		for(int p: primes) {
			while(a[i] % p == 0) {pf[i].pb(p); a[i]/=p;}
		}
		if(a[i]) pf[i].pb(a[i]);
	}
	FOR0(k, m) {
		cin >> ik, jk;
		if(ik & 1) swap(ik, jk);
		FOR0(i, SZ(pf[ik])) FOR0(j, SZ(pf[jk])) {
			if(pf[ik][i] == pf[jk][j]) graph[ik][i].pb(mp(jk, j));
		}
	}
	for(int i = 2; i <= n; i+=2) {
		FOR0(j, SZ([]))
	}
}