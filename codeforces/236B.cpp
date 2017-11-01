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
#define MOD 1073741824
int main() {
	int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int pf[101][25] = {};
	FOR(i,1,101) {
		int x = i;
		FOR0(j, 25) {
			int cnt = 0;
			while(!(x%primes[j])) {x/=primes[j]; cnt++;}
			pf[i][j] = cnt;
		}
	}
	int a, b, c;
	int ans = 0;
	cin >> a >> b >> c;
	FOR(i, 1, a+1) FOR(j, 1, b+1) FOR(k, 1, c+1) {
		int d = 1;
		FOR0(l, 25) d=(d*(1+pf[i][l]+pf[j][l]+pf[k][l]))%MOD;
		ans = (ans+d)%MOD; 
	}
	cout << ans << endl;
}