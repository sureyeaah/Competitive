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
vi primes; bitset<100005> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll i = 2; i < 100005; i++) {if(bs[i]) {
		for(ll j = i*i; j < 100005; j+=i) bs[j] = 0;
	}}
}
int main() {
	SYNC; sieve();
	int n,ans=1; cin >> n;
	int a[100000 + 5] = {};
	FOR(i,2,n+2) {
		if(bs[i]) {
			for(int j = i*2; j < n+2; j+=i) {a[j] = 1; ans=2;}
		}
	}
	cout << ans << endl;
	FOR(i,2,n+2) cout << a[i] + 1 << " ";
}