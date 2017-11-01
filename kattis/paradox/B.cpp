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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 1005
#define SEA 2
int di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
int n, m, grid[N][N] = {}, ans = 0;
inline bool valid(int i, int j) {return i >= 0 && j >= 0 && i <= n + 1 && j <= m+1;}
void flood(int i, int j) {
    grid[i][j] = SEA;
    FOR0(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if(valid(ni, nj)) {
            if(!grid[ni][nj]) flood(ni, nj);
            else if(grid[ni][nj] == 1) ans++;
        }
    }
}
int main() {
    SYNC
    char c;
    cin >> n >> m;
    FOR(i,1,n+1) {
        FOR(j,1,m+1) {
            cin >> c;
            grid[i][j] = c-'0';
        }
    }
    flood(0, 0);
    cout << ans;
}