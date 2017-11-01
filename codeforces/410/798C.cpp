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
int gcd(int a, int b) {
	return b ? gcd(b, a%b): a;
}
int main() {
	SYNC;
	int n, a[100000 + 5];
	cin >> n; FOR0(i, n) cin >> a[i];
	int val = a[n-1];
	int ans = 0;
	FOR0(i, n-1) val = gcd(val, a[i]);
	if(val == 1) {
		FOR0(i, n-1) {
			int x = a[i]&1, y = a[i+1]&1;
			if(x == y && x) {a[i] = a[i+1] = 2; ans++;}
			else if(x != y && (x || (i==n-2 || a[i+2]%2==0))) {a[i] = a[i+1] = 2; ans+=2;}
		}
		FOR0(i, n) {
			if((a[i]&1)) {ans = -1;}
		}
	}
	cout << (ans == -1 ? "NO": "YES") << endl;
	if(ans != -1) cout << ans << endl;
}