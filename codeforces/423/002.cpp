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
#define val(i,j,I,J) (grid[I][J] - grid[i-1][J] - grid[I][j-1] + grid[i-1][j-1])
int main() {
    SYNC
    int n, m, grid[105][105] = {}; char x;
    cin >> n >> m;
    FOR0(i, n) FOR0(j, m) {
        cin >> x;
        grid[i+1][j+1] = x == 'B';
    }
    FOR(i, 1, n+1) FOR(j,1,m+1) {
        grid[i][j] += grid[i][j-1] + grid[i-1][j] -grid[i-1][j-1];
    }
    int ans = INF;
    FOR(i,1,n+1) FOR(j,1,m+1) FOR(I,i,n+1) {
        int J = I-i+j;
        if(J <= 0 || J > m) continue;
        int tot = val(i,j,I,J);
        if(grid[n][m] == tot) {ans = min(ans, (I-i+1)*(J-j+1)-tot);}
    }
    cout << (ans < INF ? ans : -1);
}