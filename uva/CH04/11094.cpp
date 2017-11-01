#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ? (a) :(b))
#define MIN(a,b) ((a < b) ? (a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int m,n,x,y;
int mvX[] = {1,-1,0,0}, mvY[] = {0,0,1,-1};
char grid[21][21], land, done;


int recurse(int r, int c) {
    if(r < 0 || r > m-1) return 0;
    c = (c + n) % n;
    if(grid[r][c] != land) return 0;
    grid[r][c] = done;
    int ans = 1;
    FOR0(i, 4)
        ans += recurse(r+mvY[i], c+mvX[i]);
    return ans;
}

int main() {
    while(cin >> m) {
        scanf("%d", &n);
        while(getchar() != '\n') { }
        FOR0(i, m) {
            FOR0(j, n)
                scanf("%c", &grid[i][j]);
            while(getchar() != '\n') { }
        } 
        scanf("%d %d", &x, &y);
        while(getchar() != '\n') { }
        while(getchar() != '\n') { }
        land = grid[x][y];
        done = (land == '.') ? ',' : '.';
        int biggestLand = 0;
        recurse(x, y);
        FOR0(i, m) {
            FOR0(j, n) {
                if(grid[i][j] == land) {
                    int curr = recurse(i, j);
                    biggestLand = MAX(biggestLand, curr);
                }

            }
        }
        cout << biggestLand << endl;
    }    
}