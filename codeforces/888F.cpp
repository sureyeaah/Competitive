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
const int N = 505;
int n, dp1[N][N] = {}, dp2[N][N] = {}, a[N][N];
inline int add(int x, int y) {return (x + y) % mod;}
inline int mul(int x, int y) {return x*1LL*y % mod;}
int main() {
    SYNC
    cin >> n;
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            cin >> a[i][j];
        }
    }
    // FOR(i, 1, n+1) {
    //     a[0][i] = a[i][0] = a[n][i];
    // }
    // a[0][n] = 1;
    FOR(i, 1, n+1) dp1[i][i] = dp2[i][i] = 1;
    FOR(i, 1, n + 1) dp1[i][i+1] = dp2[i][i+1] = a[i][i+1];
    FOR(len, 2, n) {
        FOR(i, 1, n - len + 1) {
            int j = i + len;
            if(a[i][j]) {
                FOR(k, i, j) dp1[i][j] = add(dp1[i][j], mul(dp2[i][k], dp2[k+1][j]));
            }
            FOR(k, i, j + 1) dp2[i][j] = add(dp2[i][j], mul(dp1[i][k], dp2[k][j]));
        }
    }
    cout << dp2[1][n];
}