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
	int n, m, q, x1, x2, y1, y2;
	char x;
	bitset<2005> grid[2005];
	cin >> n >> m >> q;
	FOR(i,1,n+1) FOR(j,1,m+1) {
		cin >> x;
		if(x=='1') grid[i][j] = 1;
	}
	int ver[2005][2005] = {}, he[2005][2005] = {}, ve[2005][2005] = {};
	FOR(i,1,n+1) {
		FOR(j,1,m+1) {
			ver[i][j] = ver[i][j-1]+ver[i-1][j]-ver[i-1][j-1];
			he[i][j] = he[i][j-1]+he[i-1][j]-he[i-1][j-1];
			ve[i][j] = ve[i][j-1]+ve[i-1][j]-ve[i-1][j-1];
			if(grid[i][j]) {
				ver[i][j]++;
				if(grid[i][j-1]) he[i][j]++;
				if(grid[i-1][j]) ve[i][j]++;
			}

		}
	}
	while(q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		int vc =  (ver[x2][y2] + ver[x1-1][y1-1] - ver[x1-1][y2] - ver[x2][y1-1]);
		int hec = (he[x2][y2] + he[x1-1][y1] - he[x1-1][y2] - he[x2][y1]);
		int vec = (ve[x2][y2] + ve[x1][y1-1] - ve[x1][y2] - ve[x2][y1-1]);
		//DEBUG(vc); DEBUG(hec); DEBUG(vec);
		cout << vc - hec - vec << endl;
	}
}