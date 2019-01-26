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
inline int add(int x, int y) {return (x + y) % mod;}
inline int mult(int x, int y) {return (x * 1LL * y) % mod;}
const int L = 255;
const int S = 255 * 9;
int len = 0; char x;
int dp[L][S][15] = {}, pre[L][S] = {}, a[L], ans = 0;
int getval(int l, int s) {
    int ret = 0;
    if(!l) return s==0;
    if(s < 0) return 0;
    FOR(d, 0, a[len]) ret = add(ret, dp[l][s][d]);
    ret = add(ret, getval(l-1, s-a[len]));
    return ret;
}
int main() {
    SYNC
    while(cin >> x) {
        a[++len] = x - '0';
    }
    reverse(a + 1, a + 1 + len);
    dp[0][0][0] = dp[0][0][10] = pre[0][0] = 1;
    FOR(i, 1, len+1) {
        FOR(j, i, 9*i + 1) {
            FOR(d, 0, 1+min(9, j)) {
                if(i == len && d >= a[len]) {
                    if(d == a[len]) dp[i][j][d] = getval(i-1, j-d);
                    else break;
                }
                else {
                    dp[i][j][d] = dp[i-1][j-d][10];
                }
                dp[i][j][10] = add(dp[i][j][10], dp[i][j][d]);
                if(d) {
                    dp[i][j][11] = add(dp[i][j][11], dp[i][j][d]);
                    ans = add(ans, mult(dp[i][j][d], pre[i-1][j-d]));
                }
            }
        }
    }
    cout << ans;
}