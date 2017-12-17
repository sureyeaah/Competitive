#define _CRT_SECURE_NO_WARNINGS
#include "grader.h"
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
const int N = 2e5 + 5, K = 1e6 + 5;
int n, k, d[N], sz[N], lvl[N] = {}, par[N], ans = inf;
multiset<int> cnt[K];
vector<vii> g(N);
int dfs(int u, int pre) {
    sz[u] = 1;
    for(auto v : g[u]) {
        if(v.ff != pre && !lvl[v.ff]) {
            dfs(v.ff, u); sz[u] += sz[v.ff];
        }
    }
}
template <typename L>
void dfs1(int u, int pre, int dep, L op) {
    op(d[u], dep);
    for(auto v : g[u]) {
        if(v.ff != pre && !lvl[v.ff]) {
            d[v.ff] = d[u] + v.ss;
            if(d[v.ff] <= k) dfs1(v.ff, u, dep+1, op);
        }
    }
}
void solve(int u) {
    for(auto v : g[u]) {
        if(!lvl[v.ff]) {
            d[v.ff] = v.ss;
            dfs1(v.ff, u, 1, [&](int x, int dep) {cnt[x].insert(dep);});
        }
    }
    for(auto v : g[u]) {
        if(!lvl[v.ff]) {
            dfs1(v.ff, u, 1, [&](int x, int dep) {cnt[x].erase(cnt[x].find(dep));});
            dfs1(v.ff, u, 1, [&](int x, int dep) {
                if(k > x && !cnt[k-x].empty()) ans = min(ans, dep + *(cnt[k-x].begin()));
                else if(k==x) ans = min(ans, dep);
            });
        }
    }
}
int centroid(int u, int pre, int tot) {
    for(auto v : g[u]) {
        if(v.ff != pre && !lvl[v.ff] && sz[v.ff] > tot/2) {
            return centroid(v.ff, u, tot);
        }
    }
    return u;
}
void decompose(int u) {
    if(!u) {
        dfs(1, 0); u = centroid(1, 0, sz[1]);
        par[u] = 0;
    }
    lvl[u] = lvl[par[u]] + 1;
    solve(u);
    for(auto v : g[u]) {
        if(!lvl[v.ff]) {
            dfs(v.ff, 0); v.ff = centroid(v.ff, 0, sz[v.ff]);
            par[v.ff] = u;
            decompose(v.ff);
        }
    }
}
int best_path(int N, int K, int e[][2], int l[]){
    n = N; k = K;
    FOR0(i, n-1) {
        g[e[i][0]+1].pb(mp(e[i][1]+1, l[i]));
        g[e[i][1]+1].pb(mp(e[i][0]+1, l[i]));
    }
    decompose(0);
    return ans == inf ? -1: ans;
}