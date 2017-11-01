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
#define FLUSH fflush(stdout) 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define endl '\n'
#define TRYEND(x,y) if(grid[x][y] == 'F') return 0;
int main() {
	SYNC;
	int n, m, d[105][105], fx, fy, dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
	char grid[105][105];
	cin >> n >> m;
	FOR0(i, n) FOR0(j, m) {
		cin >> grid[i+1][j+1];
		if(grid[i+1][j+1] == 'F') {fx=i+1; fy=j+1;}
	}
	int x=1, y=1, xcon = -1, ycon = -1, nx, ny;
	if(grid[x+1][y] != '*') {
		cout << "U" << endl;
		FLUSH;
		cin >> x >> y;
		TRYEND(x,y)
		xcon = x == 1;
		if(!xcon) {
			cout << "D" << endl;
			cin >> x >> y;
		}
	}
	if(grid[x][y+1] != '*') {
		cout << "L" << endl;
		FLUSH;
		cin >> x >> y;
		TRYEND(x,y)
		ycon = y == 1;
		if(!ycon) {
			cout << "R" << endl;
			cin >> x >> y;
		}
	}
	while(xcon == -1 || ycon == -1) {
		if(xcon > -1) {
			if(grid[x][y+1] != '*') {
				cout << "L" << endl;
				FLUSH;
				cin >> x >> y;
				TRYEND(x,y)
				ycon = y == 1;
				if(!ycon) {
					cout << "R" << endl;
					cin >> x >> y;
				}
				break;
			}
			cout << (xcon?"D":"U") << endl; FLUSH;
			cin >> x >> y;
			TRYEND(x,y)
		} else {
			if(grid[x+1][y] != '*') {
				cout << "U" << endl;
				FLUSH;
				cin >> x >> y;
				TRYEND(x,y)
				xcon = x == 1;
				if(!xcon) {
					cout << "D" << endl;
					cin >> x >> y;
				}
				break;
			}
			cout << (ycon?"R":"L") << endl; FLUSH;
			cin >> x >> y;
			TRYEND(x,y)
		}
	}
	queue<ii> q; q.push(mp(fx,fy));
	FOR0(i,n+1) FOR0(j,m+1) d[i][j] = INF;
	d[fx][fy] = 0;
	while(!q.empty()) {
		ii curr = q.front(); q.pop();
		FOR0(i, 4) {
			nx = curr.ff+dx[i]; ny = curr.ss+dy[i];
			if((nx>0 && ny>0 && nx<=n && ny<=m)&& grid[nx][ny]=='.' && d[nx][ny]==INF) {
				d[nx][ny] = d[curr.ff][curr.ss]+1;
				q.push(mp(nx,ny));
			}
		}
	}
	while(1) {
		TRYEND(x,y)
		FOR0(i, 4) {
			nx = x + dx[i], ny = y + dy[i];
			 if((nx>0 && ny>0 && nx<=n && ny<=m) && d[x][y]-1 == d[nx][ny]) {
			 	cout << ((i&1) ? ((i==1)^xcon?"U": "D"): ((i==0)^ycon?"L": "R")) << endl; FLUSH;
			 	cin >> x >> y;
			 	break;
			 }
		}
	}
}