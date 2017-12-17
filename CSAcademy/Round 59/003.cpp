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
const int N = 3000 + 5;
int main() {
    SYNC
    int n, dp[N][N], rank[N][N];
    ii sorted[N];
    char a[N][N];
    // memset(better, -1, sizeof better);
    cin >> n;
    FOR0(i, n) {
        FOR0(j, i + 1) {
            cin >> a[i][j];
        }
    }
    FORD(i, n-1, n) {
        FOR0(j, i + 1) {
            dp[i][j] = -1;
            sorted[j] = mp((int)a[i][j], j);
        }
        sort(sorted, sorted + i + 1);
        FOR0(j, i + 1) {
            rank[i][sorted[j].ss] = j;
        }
    }
    FORD(i, 0, n-1) {
        FOR0(j, i + 1) {
            dp[i][j] = rank[i+1][j] < rank[i+1][j+1] ? j: j+1;
            sorted[j] = mp((int)a[i][j], j);
        }
        sort(sorted, sorted + i + 1, [&](ii l, ii r) {return l.ff != r.ff ? l.ff < r.ff: rank[i+1][dp[i][l.ss]] < rank[i+1][dp[i][r.ss]];});
        FOR0(j, i + 1) {
            rank[i][sorted[j].ss] = j;
        }
    }
    int cur = 0;
    FOR0(i, n) {
        cout << a[i][cur];
        cur = dp[i][cur];
    }
}