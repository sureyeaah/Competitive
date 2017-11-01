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
#define printCase() "Case " << ++caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define H 205
#define W 210
#define bl 1
#define wh 0
#define vis 2
#define valid(x, y) (x >= 0 && y >= 0 && x < h && y < w)
int h, w, grid[H][W], x, dx[4], dy[4];
void dfs(int i, int j) {
    grid[i][j] = vis;
    FOR0(k, 4) {
        int x= dx[k] + i, y = dy[k] + j;
        if(valid(x,y) && grid[x][y] == wh) dfs(x, y);
    }
}
int piece(int i, int j) {
    int ret = 0;
    grid[i][j] = vis;
    FOR0(k, 4) {
        int x= dx[k] + i, y = dy[k] + j;
        if(valid(x,y)) {
            if(grid[x][y] == wh) {
                dfs(x, y);
                ret ++;
            } else if(grid[x][y] == bl) {
                ret += piece(x,y);
            }
        }
    }
    return ret;    
}
int main() {
    SYNC
    dx[0] = dx[2] = dy[1] = dy[3] = 0; dx[1] = dy[0] = 1; dx[3] = dy[2] = -1;
    int caseNum = 0;
    char heiro[6] = {'W', 'A', 'K', 'J', 'S', 'D'};
    while(cin >> h >> w && (h || w)) {
        FOR0(i, h) {
            FOR0(j, w) {
                char c; cin >> c;
                x = c >= '0' && c <= '9' ? c - '0' : c - 'a' + 10;
                FOR0(k, 4) grid[i][j*4 + 3 - k] = (x & (1 << k)) != 0;
            }
        }
        w <<= 2;
        FOR0(i, w) {
            if(grid[0][i] == wh) {
                dfs(0,i);
            }
            if(grid[h-1][i] == wh) {
                dfs(h-1,i);
            }
        }
        FOR0(i, h) {
            if(grid[i][0] == wh) {
                dfs(i,0);
            }
            if(grid[i][w-1] == wh) {
                dfs(i,w-1);
            }
        }
        multiset<char> ans;
        FOR0(i, h) {
            FOR0(j, w) {
                if(grid[i][j] == bl) {
                    ans.insert(heiro[piece(i, j)]);
                }
            }
        }
        cout << printCase();
        for(char x : ans) cout << x;
        cout << "\n";
    }
}