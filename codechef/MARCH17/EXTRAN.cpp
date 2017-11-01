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
	int t, n, x, ans, a[100000 + 10];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		FOR0(i, n) scanf("%d", a + i);
		sort(a, a + n);
		ans = 0;
		FOR0(i, n-2) {
			if(a[i]+1 != a[i+1]) {ans = a[i]; break;}
		}
		if(!ans) {
			ans = a[n-1];
		}
		printf("%d\n", ans);
	}
}