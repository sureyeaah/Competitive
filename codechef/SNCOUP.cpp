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
	int t, n; char grid[2][100005];
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = 0;
		FOR0(i, 2) FOR0(j, n) cin >> grid[i][j];
		FOR0(i, n) {
			if(grid[0][i] == '*' && grid[1][i] == '*') {
				ans = INF;
				break;
			}
			if(grid[0][i] == '*' || grid[1][i] == '*')
				ans++;
		}
		ans = max(ans-1, 0);
		int cur = 1, last[2] = {-5,-5}, lastfence = -1;
		FOR0(i, n) {
			FOR0(j, 2) {
				if(grid[j][i] == '*') {
					if(lastfence < last[j]) {
						lastfence = i-1;
						cur++;
					}
					last[j] = i;
				}
			}
		}
		ans = min(cur, ans);
		cout << ans << endl;
	}
} 