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
#define VALID(x, y) ((x>=0) && (y>=0) && (x<n) && (y<m))

int t, n, m, p, k, end[2], moveType, moves[2][4][2] = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}}};
bool visited[101][101] = {false};
double recurse (int x, int y, int player) {
    visited[x][y] = true;
    double totalProb = 0;
    int movesPoss = 0;
    FOR0(i, 4) {
        int nx = moves[moveType][i][0], ny = moves[moveType][i][1];
        if(VALID(x+nx, y+ny) && !visited[x+nx][y+ny]) {
            totalProb += 1 - recurse(x+nx, y+ny, 1 - player);
            movesPoss++;
        }
    }
    if(!movesPoss) return 0;
    return totalProb;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &p, &k);
        // end[0] = end[1] = 0;
        long double a = 0;
        moveType = 0;
        a += 0.5*recurse(0,0,0);
        // end[0] = end[1] = 0;
        moveType = 1;
        a += 0.5*recurse(0,0,0);
        long double currProb = pow(a, k);
        long double totalProb = currProb;
        if(a!=0) {
                FORD(i,p,k) {
                currProb *= (i+1)*(1-a);
                currProb /= a*(k-i);
                totalProb += currProb;
            }
        }
        if(!p) totalProb = 1;
        printf("%.6Lf\n", totalProb);
    }
}