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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ll n, a[100000+10], diff[100000 + 10];
	cin  >> n;
	FOR0(i, n) cin >> a[i];
	FOR0(i, n-1) diff[i] = abs(a[i] - a[i+1]);
	diff[n-1] = 0;
	ll ans = *max_element(diff, diff+n-1);
	ll curr = 0;
	FOR0(i, n-1) {
		if(curr < 0) curr = 0;
		if(i%2) curr += diff[i];
		else curr += -diff[i];
		ans = max(ans, curr);
	}
	curr = 0;
	FOR0(i, n-1) {
		if(curr < 0) curr = 0;
		if(!(i%2)) curr += diff[i];
		else curr += -diff[i];
		ans = max(ans, curr);
	}
	cout << ans << endl;
}