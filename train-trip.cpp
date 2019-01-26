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
ll a, b, c; int x, y, t, n, st[3], par[N], dep[N], r[N], anc[N], lca[3][3], dad;
bitset<N> vis;
vvi g(N);

int findset(int i) {
    return i == par[i] ? i : (par[i] = findset(par[i]));
}
int sameSet(int i, int j) {return findset(i) == findset(j);}
void unite(int x, int y) {
    int px = findset(x), py = findset(y);
    if(px != py) {
        if(r[px] < r[py]) par[py] = px;
        else {
            par[px] = py;
            r[py] += r[px] == r[py];
        }
    }
}
void dfs(int u, int p, int d = 0) {
    par[u] = anc[u] = u; r[u] = 0;
    dep[u] = d;
    for(int v : g[u]) {
        if(p == v) continue;
        dfs(v, u, d + 1);
        unite(u, v);
        anc[findset(u)] = u;
    }
    vis[u] = 1;
    FOR0(i, 3) {
        if(st[i] == u) {
            FOR0(j, 3) {
                if(i != j && vis[st[j]]) {
                    lca [i][j] = lca[j][i] = anc[findset(st[j])];
                }
            }
        }
    }
}
// void process() {
//     FOR(j, 1, LOGN) {
//         FOR(i, 1, n + 1) {
//             par[i][j] = par[i][j-1] ? par[par[i][j-1]][j-1]: 0;
//         }
//     }
// }
// int lca(int u, int v) {

// }
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> c;
        FOR0(i, 3) cin >> st[i];
        FOR0(i, n+1) g[i].clear();
        FOR0(i, n-1) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        vis.reset();
        dfs(1, 0);
        dad = st[0];
        FOR0(i, 3) FOR0(j, i) if(dep[lca[i][j]] < dep[dad]) dad = lca[i][j];
        ll ans = INF, cur = 0, cur1 = (c-3*a)*1LL*dep[dad];
        FOR0(i, 3) {
            cur += 1LL * a * dep[st[i]];
        }
        cur1 += cur;
        ans = min(ans, cur);
        ans = min(ans, cur1);
        FOR0(i, 3) {
            FOR0(j, i) {
                ll nxt = cur + (b - 2*a)*1LL*(dep[lca[i][j]]);
                ans = min(ans, nxt + (c-b-a) * 1LL * dep[dad]);
                ans = min(ans, nxt);
                ans = min(ans, nxt + (-2*a) * 1LL * dep[dad] + (a + c - b)*1LL*dep[lca[i][j]]);
            }
        }
        cout << ans << newl;
    }
}