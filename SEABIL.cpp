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
typedef struct move {
	int x;
	int y;
	int vx;
	int vy;
	int e;
} move;
int main() {
	int t, n, m, x, y, z;
	map<ii, int> board, diagonal;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		FOR0(i, m) {
			scanf("%d %d %d", &x, &y, &z);
			board[mp(x, y)] = z;
		}
		move output;
		repi(i, board) {
			if(i->ss > 1) {
				x = i->ff.ff; y = i->ff.ss;
				if(x == y) continue;
				
			}
		}
	}
}