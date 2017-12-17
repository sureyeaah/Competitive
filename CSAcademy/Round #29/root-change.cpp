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
int n;
int ans[N] = {};
ii up[N], down[N];
vvi g(N);
ii relax(ii  u, ii v, int d) {
    if(u.ff < v.ff + d) {
        u.ff = v.ff + d;
        u.ss = v.ss + d;
    } else if(u.ff == v.ff + d) {
        u.ss = 0;
    }
    return u;
}
void dfs(int u, int prev) {
    down[u] = mp(0, 0);
    for(int v : g[u]) {
        if(v == prev) continue;
        dfs(v, u);
        down[u] = relax(down[u], down[v], 1);
    }
}
void dfs2(int u, int prev = 0) {
    ii l = mp(0, 0), r = mp(0, 0);
    for(int v : g[u]) {
        if(v == prev) continue;
        up[v] = l;
        l = relax(l, down[v], 1);
    
    }
    reverse(g[u].begin(), g[u].end());
    for(int v : g[u]) {
        if(v == prev) continue;
        up[v] = relax(up[v], r, 0);
        up[v] = relax(up[u], up[v], 0);
        up[v].ff++; up[v].ss++;
        r = relax(r, down[v], 1);
        dfs2(v, u);
    }
    // DEBUG(u); DEBUG(up[u].ff); DEBUG(up[u].ss);
    down[u] = relax(down[u], up[u], 0);
    ans[u] = n - 1 - down[u].ss;
}
int main() {
    SYNC;
    cin >> n;
    int x, y;
    FOR0(i, n-1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    dfs2(1);
    FOR(i, 1, n+1) cout << ans[i] << newl;
}