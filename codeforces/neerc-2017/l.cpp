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
const int N = 1e5 + 5, LOGN = 19;
vvi g(N);
vector<vii> qq(N);
int n, f, dep[N], par[N][LOGN] = {}, done[N] = {}, anc[N];
void dfs(int u, int pre) {
    dep[u] = pre ? dep[pre]+1: 0;
    par[u][0] = pre;
    for(int v : g[u] ) {
        if(v == pre) continue;
        dfs(v, u);
    }
}
void preprocess() {
    for(int i = 1; i < LOGN; i++) {
        FOR(u, 1, n + 1) {
            par[u][i] = par[par[u][i-1]][i-1];
        }
    }
}
int goup(int u, int dist) {
    for(int i = LOGN - 1; i >= 0; i--) {
        if(dist & (1 << i)) u = par[u][i]; 
    }
    return u;
}
int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    int L = LOGN;
    for(int i = L - 1; i >= 0; i--) {
        if(par[u][i] && dep[u] - (1 << i) >= dep[v])
            u = par[u][i];
    }
    if(u == v) return u;

    for(int i = L - 1; i >= 0; i--) {
        if(par[u][i] && par[v][i] != par[u][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }
    return par[u][0];
}
int ok(vii& query) {
    stack<int> s({inf});
    sort(query.begin(), query.end(), [&](auto& l, auto& r) {
        return l.ff != r.ff ? l.ff < r.ff: l.ss > r.ss;
    });
    for(auto cur : query) {
        cerr << cur.ff << "  " << cur.ss << newl;
        while(cur.ff > s.top()) s.pop();
        if(cur.ss > s.top()) return 0;
        s.push(cur.ss);
    }
    return 1;
}
int dfs1(int u, int pre) {
    if(!done[u] && SZ(qq[u])) {
        unordered_map<int, vi> m;
        unordered_set<int> pars;
        unordered_map<int, int> index;
        int ptr = 0;
        anc[u] = u;
        index[u] = 0;
        for(auto uv : qq[u]) {
            if(uv.ff != u) {
                int x = goup(uv.ff, dep[uv.ff] - dep[u] - 1);
                anc[uv.ff] = x;
                pars.insert(x);
                m[x].pb(uv.ff);
            }
            if(uv.ss != u) {
                int x = goup(uv.ss, dep[uv.ss] - dep[u] - 1);
                anc[uv.ss] = x;
                pars.insert(x);
                m[x].pb(uv.ss);
            }
        }
        if(SZ(pars) > 2) return 0;
        done[u] = u;
        for(auto& tmp : m) {
            index[tmp.ff] = ++ptr;
            vi & vec = tmp.ss;
            sort(vec.begin(), vec.end(), [&](int l, int r) {return dep[l] > dep[r];});
            FOR0(i, SZ(vec) - 1) {
                done[vec[i]] = done[vec[i+1]] = u;
                if(vec[i] == vec[i+1]) continue;
                if(lca(vec[i], vec[i+1]) != vec[i+1]) return 0;
            }
        }
        for(auto& p : qq[u]) {
            if(index[anc[p.ss]] == 1 || index[anc[p.ff]] == 2) swap(p.ff, p.ss);
            p.ff =  - dep[p.ff] + dep[u]; p.ss = (dep[p.ss] - dep[u]);
        }
        vii chain = qq[u];
        for(auto& tmp : m) {
            int bottom = tmp.ss[0], v = bottom, fac = index[anc[bottom]] == 2 ? 1 : -1;
            while(v != u) {
                done[v] = u;
                for(auto nxt : qq[v]) {
                    if(done[nxt.ff] != u || done[nxt.ss] != u) return 0;
                    if((dep[nxt.ff] < dep[nxt.ss] && fac == -1) || (dep[nxt.ff] > dep[nxt.ss] && fac == 1)) {
                        swap(nxt.ff, nxt.ss);
                    }
                    nxt.ff = fac*(dep[nxt.ff] - dep[u]); nxt.ss = fac*(dep[nxt.ss] - dep[u]);
                    chain.pb(nxt);
                }
                v = par[v][0];
            }
        }
        if(!ok(chain)) return 0;
    }
    for(int v : g[u]) {
        if(v != pre) {
            if(!dfs1(v, u)) return 0;
        }
    }
    return 1;
}
int main() {
    SYNC
    int u, v;
    cin >> n >> f;
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    preprocess();
    FOR0(i, f) {
        cin >> u >> v;
        if(u == v) continue;
        int l = lca(u, v);
        qq[l].pb(mp(u, v));
    }
    cout << (dfs1(1, 0) ? "Yes": "No");
}