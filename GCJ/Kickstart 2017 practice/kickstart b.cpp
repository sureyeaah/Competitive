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

int t,n,m;
long double dp[2011][2011];

int main() {
    scanf("%d", &t);
    FOR(casenum, 1, t+1) {
        scanf("%d%d" , &n, &m);
        FOR0(i, n+2) {
            FOR0(j, m+2) {
                dp[i][j] = 0;
            }
        }
        if(n < m) dp[1][0] = 0;
        else {
            dp[n][m] = 1.0/(n+m);
            FORD(j,0,min(n,m)) {
                int i = n;
                dp[i][j] = ((n-i)*dp[i+1][j] + (m-j)*dp[i][j+1])/(i+j);
            }
            FORD(i,0,n) {
                FORD(j,0,min(i,m+1)) {
                    dp[i][j] = ((n-i)*dp[i+1][j] + (m-j)*dp[i][j+1])/(i+j);
                }
            }
        }
        cout << "case #" << casenum << ": " << fixed << setprecision(6) << dp[1][0]*n << endl;
    }
}