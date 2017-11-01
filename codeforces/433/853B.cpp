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
#define N 100005
#define TOT (10 + (int)1e6)
int n, m, k, d[N], dest[N][2], c[N];
int cost[N][2];
ll dp[TOT][2];
vvi v[2];
void solve(int ind) {
    int done = 0, start = TOT;
    dp[0][ind] = 0;
    FOR(i, 1, TOT) {
        dp[i][ind] = dp[i - 1][ind];
        for(int j : v[ind][i]) {
            int x = dest[j][ind];
            if(!cost[x][ind]) done++;
            if(!cost[x][ind] || cost[x][ind] > c[j]) {
                dp[i][ind] += c[j] - cost[x][ind];
                cost[x][ind] = c[j];
            }
        }
        if(done == n) start = min(i, start);
    }
    FOR0(i, start) dp[i][ind] = 1e16;
}
void solve2(int ind) {
    int done = 0, start = 0;
    dp[TOT-1][ind] = 0;
    FORD(i, 1, TOT-1) {
        dp[i][ind] = dp[i + 1][ind];
        for(int j : v[ind][i]) {
            int x = dest[j][ind];
            if(!cost[x][ind]) done++;
            if(!cost[x][ind] || cost[x][ind] > c[j]) {
                dp[i][ind] += c[j] - cost[x][ind];
                cost[x][ind] = c[j];
            }
        }
        if(done == n) start = max(i, start);
    }
    FOR(i, start + 1, TOT) dp[i][ind] = 1e16;
}
int main() {
    SYNC
    v[0].resize(TOT);
    v[1].resize(TOT);
    memset(cost, 0, sizeof cost);
    memset(dp, 63, sizeof dp);
    cin >> n >> m >> k;
    FOR0(i, m) {
        cin >> d[i] >> dest[i][0] >> dest[i][1] >> c[i];
        if(dest[i][0]) v[0][d[i]].pb(i);
        else if(dest[i][1]) v[1][d[i]].pb(i);
    }
    solve(0); solve2(1);
    ll ans = 1e18;
    FOR(i, 1, TOT) if(i+k+1 < TOT) ans = min(ans, dp[i][0] + dp[i+k+1][1]);
    cout << (ans > (ll)1e13 ? -1 : ans);
}