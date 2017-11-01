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
int n, m, ans;
#define valid(x,y) (x >= 0 & y >= 0 && x < n && y < m && grid[x][y]=='.')
char grid[10][10], output[10][10];
bool addPiece(int type, int sign, int x, int y, char val) {
	if(type) {
		if(valid(x+1,y) && valid(x-1,y) && valid(x,y+sign) && valid(x,y+2*sign)) {
			grid[x+1][y] = grid[x-1][y] = grid[x][y] = grid[x][y+sign] = grid[x][y+2*sign] = val;
			return true;
		}
	} else {
		if(valid(x,y+1) && valid(x,y-1) && valid(x+sign,y) && valid(x+2*sign,y)) {
			grid[x][y+1] = grid[x][y-1] = grid[x][y] = grid[x+sign][y] = grid[x+2*sign][y] = val;
			return true;
		}
	}
	return false;
}
void remove(int type, int sign, int x, int y) {
	if(type) {
		grid[x+1][y] = grid[x-1][y] = grid[x][y] = grid[x][y+sign] = grid[x][y+2*sign] = '.';
	} else {
		grid[x][y+1] = grid[x][y-1] = grid[x][y] = grid[x+sign][y] = grid[x+2*sign][y] = '.';
	}
}
void backtrack(int pieces, int prevX, int prevY) {
	if(pieces > ans) {FOR0(i, n) FOR0(j, m) output[i][j] = grid[i][j]; ans = max(ans, pieces);}
	if(((n-prevX+1)*(m-prevY+1))/5 + pieces < ans) return;
	//if(pieces > (n*m)/5) return;
	FOR(x, 0, min(n,prevX+4)) {
		FOR(y, 0, min(m,prevY+4)) {
			if(grid[x][y] != '.') continue;
			if(addPiece(1,1,x,y,'A'+pieces)) {backtrack(pieces+1,x,y); remove(1,1,x,y);}
			if(addPiece(1,-1,x,y,'A'+pieces)) {backtrack(pieces+1,x,y); remove(1,-1,x,y);}
			if(addPiece(0,1,x,y,'A'+pieces)) {backtrack(pieces+1,x,y); remove(0,1,x,y);}
			if(addPiece(0,-1,x,y,'A'+pieces)) {backtrack(pieces+1,x,y); remove(0,-1,x,y);}
		}
	}
}
int main() {
	SYNC;
	ans = 0;
	cin >> n >> m;
	FOR0(i, n) FOR0(j, m) grid[i][j] = output[i][j] = '.';
	backtrack(0,0,0);
	cout << ans << endl;
	FOR0(i, n) {FOR0(j, m) cout << output[i][j]; cout << endl;}
}