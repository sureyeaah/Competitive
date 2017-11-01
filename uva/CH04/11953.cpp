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

int t, n;
char grid[105][105];
// dir - 0 both, 1 right, 2 down
bool isShip(int r, int c, bool alive, int dir) {
    if(grid[r][c] == '.')
        return false;
    if(grid[r][c] == 'x')
        alive = true;
    grid[r][c] = '.';
    if(dir == 0)
        return (isShip(r+1, c, alive, 2) || isShip(r, c+1, alive, 1) || alive);
    else if(dir == 2)
        return (isShip(r+1, c, alive, 2) || alive);
    else
        return (isShip(r, c+1, alive, 1) || alive);
}

int main() {
    scanf("%d", &t);
    FOR0(i, 105) grid[0][i] = '.';
    FOR0(caseNumber, t) {
        scanf("%d", &n);
        while(getchar() != '\n') { }
        FOR(i, 1, n+1) {
            scanf("%s", grid[i]);
            grid[i][n+1] = '.';
        }
        FOR0(i, n+1) grid[n+1][i] = '.';
        int aliveShips = 0;
        FOR(i, 1, n+1) {
            FOR(j, 0, n) {
                aliveShips += (int)(isShip(i, j, false, 0));
            }
        }
        printf("Case %d: %d\n", caseNumber+1, aliveShips);
    }
}