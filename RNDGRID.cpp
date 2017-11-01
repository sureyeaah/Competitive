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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define valid(curr) (curr >= 0 && curr < n)
int main() {
	int t, l, n;
	char moves[5000 + 5], grid[1005][1005];
	int coldp[1005], rowdp[1005];
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &l, &n);
		while(getchar() != '\n') {}
		scanf("%s", moves);
		FOR0(i, n) scanf("%s", grid[i]);
		FOR0(i, n) {
			int curr = i, j = 0;
			do {
				if(moves[j] == 'L') curr--;
				else if(moves[j] == 'R') curr++;
			} while(valid(curr) && ++j < l);
			coldp[i] = j;
		}
		FOR0(i, n) {
			int curr = i, j = 0;
			do {
				if(moves[j] == 'U') curr--;
				else if(moves[j] == 'D') curr++;
			} while(valid(curr) && ++j < l);
			rowdp[i] = j;
		}
		int ans = 0;
		FOR0(i, n) {
			FOR0(j, n) {
				if(grid[i][j] == '.') {
					ans ^= min(rowdp[i], coldp[j]);
				}
			}
		}
		cout << ans << endl;
	}
}