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
    std::ios::sync_with_stdio(false);
	ll b, q, l, m, a[100000+5];
	cin >> b >> q >> l >> m;
	FOR0(i, m) cin >> a[i];
	if(!b || !q) {
		if(b) {
			if(find(a,a+m,0)-a == m && abs(b)<=l) cout << "inf" << endl;
			else if(find(a,a+m,b)-a==m && abs(b) <= l) cout << 1 << endl;
			else cout << 0 << endl;
		} else {
			if(find(a,a+m,0)-a == m) cout << "inf" << endl;
			else cout << 0 << endl;
		}
	}
	else if(q==1) {
		if(abs(b)<=l && find(a,a+m,b)-a == m) cout << "inf" << endl;
		else cout << 0 << endl;
	}
	else if(q==-1) {
		if(abs(b) > l) cout << 0 << endl;
		else if((find(a,a+m,b)-a == m || find(a,a+m,-b)-a == m)) cout << "inf" << endl;
		else cout << 0 << endl;
	}
	else {
		int ans = 0;
		ll curr = b;
		while(abs(curr) <= l) {
			if(find(a,a+m,curr)-a == m) ans++;
			curr *= q;
		}
		cout << ans << endl;
	}
}