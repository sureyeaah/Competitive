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
typedef pair<ii,int> iii;
#define VALID(r,c) (r >= 1 && c >= 1 && r < m && c < n)
int main() {
	int m, n, x, b1, b2, e1, e2, d1[4] = {0,1,0,-1}, d2[4] = {1,0,-1,0}, d, rotCost[4] = {0,1,2,1};
	string initDir;
	int point[55][55][4];
    bool FREE[55][55];
	map <string,int> dirmap;
	dirmap["north"] = 3; dirmap["south"] = 1; dirmap["west"] = 2; dirmap["east"] = 0;
    while(scanf("%d%d", &m, &n) && n && m) {
    	memset(FREE, true, sizeof FREE);
        FOR0(i, m) {
            FOR0(j, n) {
                scanf("%d", &x);
                if(x) {
                    int next_r = i, next_c = j, next_dir = 1;
                    FOR0(k, 4) {
                        if(next_r < 0 || next_c < 0) continue;
                        FREE[next_r][next_c] = false;
                        next_r += d1[next_dir]; next_c += d2[next_dir];
                        next_dir = (next_dir+3)%4;
                    }
                }
            }
        }
    	scanf("%d%d%d%d", &b1, &b2, &e1, &e2);
    	cin >> initDir;
    	d = dirmap[initDir];
    	FOR0(i,m) FOR0(j, n) FOR0(k, 4) point[i][j][k] = INF;
    	point[b1][b2][d] = 0;
    	queue<iii> q;
    	q.push(mp(mp(b1, b2),d));
    	while(!q.empty()) {
    		iii curr = q.front(); q.pop();
    		int row = curr.first.first, col = curr.first.second,dir = curr.second;
    		FOR0(add, 4) {
    			int newDir = (dir+add)%4;
    			FOR(move,1,4) {
    				int next_r = d1[newDir]*move+row, next_c = d2[newDir]*move + col;
                    if(VALID(next_r, next_c) && FREE[next_r][next_c]) {
    					int cost = point[row][col][dir]+rotCost[add]+1;
    					if(cost < point[next_r][next_c][newDir]) {
    						point[next_r][next_c][newDir] = cost;
    						q.push(mp(mp(next_r,next_c),newDir));
    					}
    				} else break;
    			}
    		}
    	}
        int ans = *min_element(point[e1][e2], point[e1][e2]+4);
    	if(ans < INF) cout << ans << endl;
    	else cout << -1 << endl;
    }
}