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

int main() {
	SYNC;
	int a, x, y;
	cin >> a >> x >> y;
	int l = ceil(y/(double)a);
	int ans = 1;
	if(l*a == y) ans = 0;
	int type = (l > 2 && (l&1));
	if(type) {
		if(!x || x>=a || x<=-a) ans  =0;
	} else if(abs(x) >= ((double)a)/2.0) ans = 0;
	if(ans) ans = (l<=2) ? l: (!type)? 3*(l-2)/2+2: 3*(l-1)/2+(x>0);
	else ans = -1;
	cout << ans;
}