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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define VALID(x,y) ((x >= 0) && (y >= 0) && (x < r) && (y < c))
int N, r, c, val[101][101], height[101][101],dr[4],dc[4];
string name;
int dfs(int row, int col) {
	if(val[row][col]>0) return val[row][col];
	int ret = 0;
	FOR0(i, 4) {
		int nr = row + dr[i], nc = col + dc[i];
		if(VALID(nr,nc) && height[row][col]>height[nr][nc]) {
			ret = max(ret,dfs(nr,nc));
		}
	}
	return val[row][col] = ret+1;
}
int main() {
	dr[0] = dr[2] = dc[1] = dc[3] = 0;
	dr[1] = dc[0] = 1;
	dr[3] = dc[2] = -1;
	scanf("%d", &N);
	while(N--) {
		cin >> name;
		scanf("%d%d",&r,&c);
		FOR0(i, r) FOR0(j, c)
			val[i][j] = 0;
		FOR0(i, r) FOR0(j, c)
			scanf("%d", &height[i][j]);
		int ans = -INF;
		FOR0(i,r) FOR0(j, c) ans = max(ans,dfs(i,j)) ;
		cout << name << ": " << ans << endl;
	}		
}