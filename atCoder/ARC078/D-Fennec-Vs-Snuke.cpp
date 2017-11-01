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
vvi g(N);
int n, a, b, ans; int par[N], sub[N], depth[N];
int dfs(int u, int p) {
    sub[u] = 1;
    par[u] = p;
    depth[u] = depth[p] + 1;
    for(int v : g[u]) {
        if(p == v) continue;
        dfs(v,u);
        sub[u] += sub[v];
    }
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n-1) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    depth[0] = 0;
    dfs(1, 0);
    int u = n;
    while(u != 1) {
        if(depth[u] == (depth[n]+1)/2 + 1) ans = sub[u] >= n-sub[u];
        u = par[u];
    }
    cout << (ans ? "Snuke": "Fennec");
}