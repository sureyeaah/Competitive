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

int main() {
	SYNC;
	int n, k, a[100000 + 5]; cin >> n >> k;
	if(n&1) {
		FOR(i,1,n+1) {
			if(i&1) {
				if(k&1) a[n-i+1] = i;
				else a[i] = i;
			} else a[i] = i;
		}
	} else {
		FOR(i,1,n+1) {
			if(i&1) {
				if(k%4==1) a[n-i+1] = i;
				else if(k%4==2) a[n-i] = i;
				else if(k%4==3) a[i+1] = i;
				else a[i] = i;
			}
			else {
				if(k%4==1) a[i-1] = i;
				else if(k%4==2) a[n-i+2] = i;
				else if(k%4==3) a[n-i+1] = i;
				else a[i] = i;
			}
		}
	}
	FOR(i,1,n+1) cout << a[i] << " ";
	cout << endl;
}