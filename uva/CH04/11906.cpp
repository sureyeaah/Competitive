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



char grid[110][110];
int dir[4][2] = {{1, 1},{-1, -1},{1, -1}, {-1, 1}}, ahead[2][2];
int t, r, c, m, n, w, x, y;
void traverse(int row, int col) {
    grid[row][col] = 'v';
    FOR0(i,2) {
        int start = (ahead[i][0] == 0) ? 2: 0;
        int end   = (ahead[i][1] == 0) ? 2: 4;
        FOR(j, start, end) {
            int next_r = row + dir[j][0]*ahead[i][0];
            int next_c = col + dir[j][1]*ahead[i][1];
            if(next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && grid[next_r][next_c] == 'u')
                traverse(next_r, next_c);
        }
        if(m == n) break;
    }
}

int count(int row, int col) {
    int ret = 0;
    FOR0(i,2) {
        int start = (ahead[i][0] == 0) ? 2: 0;
        int end   = (ahead[i][1] == 0) ? 2: 4;
        FOR(j, start, end) {
            int next_r = row + dir[j][0]*ahead[i][0];
            int next_c = col + dir[j][1]*ahead[i][1];
            if(next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && grid[next_r][next_c] == 'v')
                ret++;
        }
        if(m == n) break;
    }
    return ret;
}

int main() {
    scanf("%d" , &t);
    FOR(caseNumber, 1, t+1) {
        scanf("%d %d %d %d", &r, &c, &m, &n);
        ahead[0][0] = n; ahead[0][1] = m;
        ahead[1][0] = m; ahead[1][1] = n;
        scanf("%d", &w);
        FOR0(i, r) {
            FOR0(j, c)  {
                grid[i][j] = 'u';
            }
        }
        FOR0(i, w) {
            scanf("%d%d", &x, &y);
            grid[x][y] = 'w';
        }
        traverse(0, 0);
        int evens = 0, odds = 0;
        FOR0(i, r) {
            FOR0(j, c) {
                if(grid[i][j] == 'v') {
                    int k = count(i, j);
                    if(k%2 == 0) evens++;
                    else odds++;
                }
            }
        }
        printf("Case %d: %d %d\n", caseNumber, evens, odds);
    }
}