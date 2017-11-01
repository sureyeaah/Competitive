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

int gcd(int a, int b) {
	return (b==0) ? a : gcd(b,a%b);
}
int main() {
	int ans;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(b < d) {
		swap(b,d); swap(a,c);
	}
	int r = b - d;
	// mc - ka = 0 mod(r)
	int k;
	if(r) {
		if(r%gcd(c,a) != 0) {ans = -1;}
		else {
			k = 0;
			while(1) {
				double m = (double)(a*k+r)/(double)c;
				if(m == (int)m) {
					ans = c*m+d;
					break;
				}
				k++;
			}
		}
	} else {
		ans = b;
	}
	printf("%d\n", ans);
}