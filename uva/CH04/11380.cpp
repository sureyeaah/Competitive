#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
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
#define iceberg '@'
#define water '~'
#define ice '.'
#define wood '#'
#define people '*'
#define valid(r,c) ((r)>=0 && (c)>=0 && (r)<x && (c)<y)
#define index(r,c) (r*y+c)
vector<map<int,int> > res;
int x,y,p,f,s,t,par[1805],sz;
void augment(int u, int minEdge) {
	if(u == s) {f = minEdge; return;}
	else if (par[u]!=-1) {
		augment(par[u], min(minEdge, res[par[u]][u]));
     	res[par[u]][u] -= f; res[u][par[u]] += f;
	}	
}
int main() {
	int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
	SYNC;
	char grid[35][35];
	while(cin >> x >> y >> p) {
		FOR0(i, x) cin >> grid[i];
		sz = x*y; s = sz << 1; t = s+1;
		res.clear(); res.resize(x*y*2 + 5);
		int mf = 0;
		FOR0(r,x) FOR0(c,y) {
			if(grid[r][c]!=water) {
				if(grid[r][c] == people) res[s][index(r,c)] = res[index(r,c)][index(r,c)+sz] = 1;
				else if (grid[r][c] == wood) {
					res[sz+index(r,c)][t] = p;
					res[index(r,c)][sz+index(r,c)] = INF;
				} else if (grid[r][c] == ice) res[index(r,c)][sz+ index(r,c)] = 1;
				else res[index(r,c)][index(r,c)+sz] = INF; 
				FOR0(i, 4) {
					int nr = r+dx[i], nc = c+dy[i];
					if (!valid(nr,nc) || grid[nr][nc] == water) continue;
					res[index(r,c)+sz][index(nr,nc)] = INF;
				}
			}
		}
		while(1) {
			queue<int> q; q.push(s);
			f = 0;
			FOR0(i, t+1) par[i] = -1;
			par[s] = s;
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(u == t) break;
				repi(i, res[u]) if(i->ss && par[i->ff]==-1) {
					par[i->ff] = u;
					q.push(i->ff);
				}
			}
			augment(t, INF);
			if(!f) break;
			mf += f;
		}
		cout << mf << endl;
	}
}