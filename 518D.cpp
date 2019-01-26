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
const int N = 2005;
int main() {
    SYNC
    long double p, dp[N][N];
    int n, k;
    cin >> n >> p >> k;
    dp[0][0]=1;
    long double ans = 0;
    FOR(t,1,k+1) {
        ans = 0;
        dp[t][0] = dp[t-1][0] * (1-p);
        FOR(i, 1, min(n, t) + 1) {
            dp[t][i] = p*dp[t-1][i-1];
            if(i < n) dp[t][i] += (1-p)*(dp[t-1][i]);
            else dp[t][i] += (dp[t-1][i]);
            ans += i * dp[t][i];
        }
    }
    cout << fixed << setprecision(10) << ans;
}