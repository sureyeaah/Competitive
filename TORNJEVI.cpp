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
#define castle '#'
#define tower 'T'
#define att 'n'
#define nt(x) (x^1)
#define ind(x,y,dir) ((dir&1) ? ((x*s+y)<<1): ((x*s+y)<<1)^1)
#define valid(x,y) (x>=0 && y>=0 && x < r && y < s)
int r, s, ans[20000 + 5];
char grid[101][101];
vvi graph(40000+5);
int main() {
	SYNC;
	cin >> r >> s;
	int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};
	FOR0(i, r) FOR0(j, s) cin >> grid[i][j];
	FOR0(x, r) FOR0(y, s) ans[ind(x,y,0)] = ans[ind(x,y,1)] = -1;
	FOR0(i, r) FOR0(j ,s) {
		if(grid[i][j] == tower) {
			FOR0(dir,2) FOR(len,1,INF) {
				int ni = i+len*dr[dir], nj = j+len*dc[dir];
				if (!valid(ni,nj) || grid[ni][nj] == castle) break;
				if(grid[ni][nj] == tower) {
					if(dir&1) {ans[ind(i,j,dir)] = 1; ans[ind(ni,nj,dir)] = 0;}
					else {cout << ind(i,j,dir) << endl; ans[ind(i,j,dir)] = 0; ans[ind(ni,nj,dir)] = 1;}
					break;
				}
			}
		}
	}

	FOR0(i, r) FOR0(j ,s) {
		if(grid[i][j] == att) {
			ii vt,ht; int dest = 0;
			FOR0(dir,4) FOR(len,1,INF) {
				int ni = i+len*dr[dir], nj = j+len*dc[dir];
				if (!valid(ni,nj) || grid[ni][nj] == castle) break;
				if(grid[ni][nj] == tower) {
					if(ans[ind(ni,nj,dir)]==-1) {
						if(dir&1==0) ht=mp(ni,nj);
						else vt=mp(ni,nj);
					}
					else if(ans[ind(ni,nj,dir)]==(dir&1?(dc[dir]<0):(dr[dir]>0)))
						{dest=1; DEBUG(ni); DEBUG(nj);}
					break;
				}
			}
			if(!dest) {
				//int x = hor(ht.ff,ht.ss), y=ver(vt.ff,vt.ss);

			}
		}
	}
}