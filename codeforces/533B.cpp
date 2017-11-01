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
#define N 200005
vvi g(N);
int a[N]; ll dp[N][2] = {}, pre[N][2];
void dfs(int u) {
    pre[0][0] = 0; pre[0][1] = -(ll)1e16;
    for(int v : g[u]) dfs(v);
    FOR0(i,SZ(g[u])) {
        int v = g[u][i];
        pre[i+1][1] = max(pre[i][1] + dp[v][0], pre[i][0] + dp[v][1]);
        pre[i+1][0] = max(pre[i][1] + dp[v][1], pre[i][0] + dp[v][0]);
    }
    dp[u][0] = pre[SZ(g[u])][0];
    dp[u][1] = max(dp[u][0] + a[u], pre[SZ(g[u])][1]);
}
int main() {
    SYNC
    int n, p;
    cin >> n;
    //g[0].pb(1); a[0] = 0;
    FOR(i, 1, n+1) {
        cin >> p >> a[i];
        if(p > -1) g[p].pb(i);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}