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


int main() {
    int r,c,rowBombs,row,bombs,bombCol,x,y;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    ii start, dest;
    int grid[1001][1001];
    while(scanf("%d%d", &r, &c) && r && c) {
        FOR0(i, r) {
            FOR0(j, c) {
                grid[i][j] = 0;
            }
        }
        scanf("%d", &rowBombs);
        while(rowBombs--) {
            scanf("%d%d", &row, &bombs);
            while(bombs--) {
                scanf("%d", &bombCol);
                grid[row][bombCol] = INF;
            }
        }
        scanf("%d%d",&x,&y);
        start = mp(x,y);
        scanf("%d%d",&x,&y);
        dest = mp(x,y);
        queue<ii> q; q.push(start);
        grid[start.first][start.second] = 1;
        bool finished = false;
        while(!q.empty() && !finished) {
            ii curr = q.front(); q.pop();
            FOR0(i, 4) {
                int next_r = curr.first+dir[i][0];
                int next_c = curr.second+dir[i][1];
                if(next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && !grid[next_r][next_c]) {
                    grid[next_r][next_c] = grid[curr.first][curr.second] + 1;
                    q.push(mp(next_r,next_c));
                    if(next_r == dest.first && next_c == dest.second) finished = true;
                }
            }
        }
        cout << grid[dest.first][dest.second] - 1 << endl;
    }
}