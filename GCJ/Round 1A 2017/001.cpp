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

int main() {
	SYNC;
	int t, r, c;
	char grid[30][30], ans[30][30];
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> r >> c;
		FOR0(i, r) cin >> grid[i];
		FOR0(i, r) FOR0(j, c) ans[i][j] = '.';
		FOR0(i, r) FOR0(j, c) {
			if(grid[i][j] != '?') {
				if(j > 0 && ans[i][j-1]=='.') {
					FOR0(next,j) ans[i][next] = grid[i][j];
				}
				FOR(next,j,c) {
					ans[i][next] = grid[i][j];
				}
			}
		}
		int index = 0;
		while(ans[index][0] == '.') index++;
		FOR0(i, index) strcpy(ans[i], ans[index]);
		FOR(i, index+1, r) if(ans[i][0] == '.') strcpy(ans[i],ans[i-1]);
		cout << "Case #" << caseNum << ":" << endl;
		FOR0(i, r) {
			FOR0(j, c) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
}