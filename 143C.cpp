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
#define eval(x,y,z) ((x+1)*(y+2)*(z+2) - x*y*z)

int main() {
	SYNC;
	int n;
	cin >> n;
	ll mina = (ll)(9e18), maxa = 0;
	for(ll a = 1; pow(a,3) <= n; a++) {
		if(n%a) continue;
		ll d = n/a;
		for(ll b = 1; b*b <= d; b++) {
			if(d%b==0) {
				ll c = d/b;
				ll v[3] = {eval(a,b,c), eval(b,a,c), eval(c,a,b)};
				maxa = max(maxa, *max_element(v,v+3));
				mina = min(mina, *min_element(v,v+3));
			}
		}
	}
	cout << mina << " " << maxa << endl;
}