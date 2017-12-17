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
const int N = 1e4 + 5;
vector<vector<pair<int,ii>>> g(N);
vi order;
bitset<N> vis;
int b, n, dp[2][N], c[N], p[N];
void dfs(int u) {
    vis[u] = 1;
    for(auto v : g[u]) {
        if(vis[v.ff]) continue;
        dfs(v.ff);
    }
    order.pb(u);
}
int main() {
    SYNC
    unordered_map<string, int> dish;
    string s1, s2, ing; int u, v, x, y, cnt = 0;
    cin >> b >> n;
    memset(c, 0, sizeof c);
    memset(p, 0, sizeof p);
    FOR0(i, n) {
        cin >> s1 >> s2 >> ing >> x >> y;
        u = dish[s1]; if(!u) u = dish[s1] = ++cnt;
        v = dish[s2]; if(!v) v = dish[s2] = ++cnt;
        g[v].pb(mp(u, mp(x, y)));
        c[u] = inf; p[u] = inf;
    }
    FOR(i, 1, cnt + 1) {
        if(!vis[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
    for(int cur : order) {
        // cout << c[cur] << " " << p[cur] << newl;
        for(auto& nxt : g[cur]) {
            if(c[cur] + nxt.ss.ff < c[nxt.ff]) {
                c[nxt.ff] = c[cur] + nxt.ss.ff;
                p[nxt.ff] = p[cur] + nxt.ss.ss;
            } else if(c[cur] + nxt.ss.ff == c[nxt.ff]) {
                p[nxt.ff] = max(p[nxt.ff], p[cur] + nxt.ss.ss);
            }
        }
    }
    memset(dp, 0, sizeof dp);
    int cur = 1;
    // DEBUG(cnt);
    FOR(i, 1, cnt + 1) {
        FOR0(j, b + 1) {
            dp[cur][j] = dp[cur ^ 1][j];
            if(j >= c[i]) dp[cur][j] = max(dp[cur][j], dp[cur^1][j-c[i]] + p[i]);
        }
        cur ^= 1;
    }
    cur ^= 1;
    int ans = 0;
    FOR(i, 1, b + 1) if(dp[cur][i] > dp[cur][ans]) ans = i;
    cout << (dp[cur][ans]) << newl;
    cout << ans;
}