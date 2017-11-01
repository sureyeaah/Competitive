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
#define mod (7 + (int)1e9)
#define N 105
int main() {
    SYNC
    int n, k, d, dp[N][N] = {};
    cin >> n >> k >> d;
    FOR(i,1,k+1) FOR(j,1,i+1) dp[i][j] = 1;
    FOR(sum,2,n+1) {
        FORD(least,1,k+1) {
            //dp[sum][least] += dp[sum][least+1];
            FOR(i,max(1,sum-k),sum)
                if(sum - i < least) dp[sum][least] = (dp[sum][least] + dp[i][least]) % mod;
                else dp[sum][least] = (dp[sum][least] + dp[i][1]) % mod;
        }
    }
    cout << dp[n][d] << endl;
}