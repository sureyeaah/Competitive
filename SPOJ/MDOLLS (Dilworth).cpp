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
int t, m, h[20001], w[20001], dolls[20001], top[20001];
bool comp(const int & l, const int & r) {
	return (w[l]==w[r])?h[l]<h[r]: w[l] > w[r];
}
int main() {
	SYNC;
	cin >> t;
	while(t-- ) {
		cin >> m;
		FOR0(i, m) cin >> w[i] >> h[i];
		FOR0(i, m) dolls[i] = i;
		sort(dolls, dolls+m, comp);
		int ans = 0;
		FOR0(i, m) {
			int loc = upper_bound(top, top+ans, h[dolls[i]]) - top;
			if(loc == ans) {
				top[ans++] = h[dolls[i]];
			} else top[loc] = h[dolls[i]];
		}
		cout << ans << endl;
 	}
}