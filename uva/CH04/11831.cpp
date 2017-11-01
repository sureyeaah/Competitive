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
    map<char, int> dirmap = {{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
    int n, m, s, move_c[4] = {0, 1, 0, -1}, move_r[4] = {-1, 0, 1, 0}, dir, pos_c, pos_r;
    char grid[105][105];
    string moves;
    while(true) {
        scanf("%d %d %d", &n, &m, &s);
        if(n == 0 && m == 0 && s == 0) break;
        while(getchar() != '\n') {}
        FOR0(i, n) {scanf("%s", grid[i]); while(getchar() != '\n') {}}
        getline(cin, moves);
        FOR0(i, n) {
            FOR0(j, m) {
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                    pos_r = i; pos_c = j;
                    dir = dirmap[grid[i][j]];
                    i = INF;
                    break;
                }
            }
        }
        int stickers = 0;
        FOR0(i, s) {
            char currMove = moves[i];
            if(currMove == 'D') dir = (dir+1)%4;
            else if(currMove == 'E') dir = (dir+3)%4;
            else {
                int next_c = pos_c + move_c[dir];
                int next_r = pos_r + move_r[dir];
                if(next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && grid[next_r][next_c] != '#') {
                    
                    if(grid[next_r][next_c] == '*') {
                        grid[next_r][next_c] = '.';
                        stickers++;
                    }
                    pos_r = next_r;
                    pos_c = next_c;
                }
            } 
        }
        cout << stickers << endl;
    }
}