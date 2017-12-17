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
const int N = 1e5 + 5;
int n, sz[N], root[N], t = 0, p[N], vis[N]={}, ans[N][2], match[N] = {}, dp[N][2] = {};
vvi g(N);
void dfs(int u, int pre) {
    sz[u] = 1;
    dp[u][0] = dp[u][1] = 0;
    ii best = mp(inf, 0);
    for(int v : g[u]) {
        if(v == pre) continue;
        dfs(v, u); sz[u] += sz[v];
        dp[u][0] += max(dp[v][0], dp[v][1]);
        best = min(best, mp(dp[v][0] - max(dp[v][0], dp[v][1]), u));
    }
    dp[u][1] = best.ff == inf ? 0: dp[u][1] + best.ff;
    if(!pre) {
        ans[u][1] = max(dp[u][1], dp[u][0]);
        ans[u][0] = dp[u][0];
    }
}
set<int> unmatched;
vector<ii> same, better;
void generate(int u, int pre, int m) {
    if(!m) unmatched.insert(u);
    for(int v : g[u]) {
        if(v == pre) continue;
        int nm = (m && match[u] == v) || (!m && dp[v][1] > dp[v][0]);
        generate(v, u, nm);
    }
}
int main() {
    SYNC
    cin >> n;
    p[1] = 0;
    FOR(i, 2, n + 1) {
        cin >> p[i];
        g[p[i]].pb(i);
    }
    FOR(i, 1, n + 1) {
        if(!vis[i] && !p[i]) {
            root[t++] = i;
            dfs(i, 0);
            if(ans[i][0] < ans[i][1]) {
                p[i] = 1;
                generate(i, 0, 0);
            } else if(ans[i][0] == ans[i][1]) same.pb(mp(sz[i]-2*ans[i][0],i));
            else better.pb(mp(sz[i]-2*ans[i][0]-1, i));
        }
    }
    sort(same.begin(), same.end(), greater<ii>());
    sort(better.begin(), better.end(), greater<ii>());
    int i = 0, j = 0;
    while(i < SZ(same) || j < SZ(better)) {
        if(j==SZ(better) || (!SZ(unmatched) && i < SZ(same))) {
            p[same[i].ss] = 1;
            generate(same[i].ss, 0, 0);
            i++;
        } else {
            p[better[j].ss] = (!unmatched.empty() ? *(unmatched.begin()): 1);
            if(!unmatched.empty()) unmatched.clear(unmatched.begin());
            generate(better[j].ss, 0, 0);
            j++;
        }
    }
}