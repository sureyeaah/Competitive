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
vvi g(N); int dp[N][2][3];
void dfs(int u, int prev) {
    for(int v: g[u])
        if(v != prev) dfs(v,u);
    if(u!= 1 && prev != 1) {
        dp[u][1][2] = 1;
        for(int v : g[u]) {
            if(v == prev) continue;
            int val = INF;
            FOR0(i, 2) FOR0(j, 2) val = min(dp[v][i][j], val);
            if(val >= INF) {dp[u][1][2] = INF; break;}
            else dp[u][1][2] += val;
        }
    }
    
    dp[u][1][1] = 1;
    for(int v : g[u]) {
        if(v == prev) continue;
        int val = INF;
        FOR0(i, 2) FOR0(j, 3) val = min(dp[v][i][j], val);
        if(val == INF) {dp[u][1][1] = INF; break;}
        else dp[u][1][1] += val;
    }

    dp[u][0][1] = 0; int best = INF;
    for(int v : g[u]) {
        if(v == prev) continue;
        int val = INF;
        FOR0(i, 2) FOR0(j, 2) val = min(dp[v][i][j<<1], val);
        if(val == INF) {dp[u][0][1] = INF; break;}
        else dp[u][0][1] += val;
        best = min(best, min(dp[v][1][0],dp[v][1][2])-val);
    }
    if(best < INF && dp[u][0][1] < INF) dp[u][0][1] += best;
    else dp[u][0][1] = INF;

    dp[u][1][0] = 1;
    for(int v : g[u]) {
        if(v == prev) continue;
        int val = INF;
        FOR0(i, 2) FOR0(j, 2) val = min(dp[v][i][j], val);
        if(val >= INF) {dp[u][1][0] = INF; break;}
        else dp[u][1][0] += val;
    }
    if(dp[u][1][0] == 1) dp[u][1][0] = INF;
    
    dp[u][0][0] = 0;
    priority_queue<int> pq;
    for(int v : g[u]) {
        if(v == prev) continue;
        int val = INF;
        FOR0(i, 2) FOR0(j, 1) val = min(dp[v][i][j], val);
        if(val >= INF) {dp[u][0][0] = INF; break;}
        else dp[u][0][0] += val;
        pq.push(dp[v][1][0] - val); if(pq.size() > 2) pq.pop();
    }
    if(pq.size() == 2 && dp[u][0][0] < INF) {
        while(!pq.empty()) {dp[u][0][0] += pq.top(); pq.pop();}
    } else dp[u][0][0] = INF;
}
int main() {
    SYNC
    int t, n, u, v;
    cin >> t;
    while(t--) {
        cin >> n;
        FOR0(i, n+1) g[i].clear();
        memset(dp, 63, sizeof dp);
        FOR0(i, n-1) {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1,0);
        int ans = min(dp[1][0][0], dp[1][1][0]);
        if(ans >= INF) ans = -1;
        cout << ans << endl;
    }
}