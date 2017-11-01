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
#define BS 60
vvi v(2505);
int main() {
	SYNC;
	int t, n, k, len, x, cnt[2505];
	bitset<2505> has[2501];
	cin >> t;
	while(t--) {
		cin >> n >> k;
		FOR0(i, k+1) v[i].clear();
		FOR0(i, n) has[i].reset();
		FOR0(i, n) {
			cin >> len;
			while(len--) {
				cin >> x;
				v[x].pb(i);
				has[i][x] = 1;
			}
		}
		int ans = 0;
		FOR0(i, n) {
			memset(cnt, 0, sizeof cnt);
			len = 0;
			FOR(j, 1, k+1) {
				if(has[i][j]) continue;
				len++;
				for(int z : v[j]) cnt[z] ++;
			}
			FOR(j, i+1, n) if(cnt[j] == len) ans ++;
		}
		cout << ans << endl;
	}
}