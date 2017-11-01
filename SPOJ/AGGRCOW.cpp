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
int t, n, c, x[1000010];
bool check(int d) {
	int p = 0, nxt = 0;
	FOR0(i, c-1) {
		while(nxt < n && x[nxt]- x[p] < d) {
			nxt++;
		}
		p = nxt;
		if(nxt == n) return false;
	}
	return true;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &c);
		FOR0(i, n) scanf("%d", x + i);
		sort(x,x+n);
		int  l = 0, r = x[n-1], mid;
		while(l < r) {
			mid = (l+r+1)/2;
			if(check(mid)) {
				l = mid;
			}
			else {
				r = mid-1;
			} 
		}
		printf("%d\n", l);
	}
}