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
int par[N], val[N], ft[N], sub[N];
vector<vii> g(N);
int dfs(int u, int prev) {
    par[u] = prev;
    sub[u] = 1;
    for(ii & v : g[u]) {
        if(v.ff != prev) {
            val[v.ff] = v.ss;
            sub[u] += dfs(v.ff, u);
        }
    }
    return sub[u];
}
int chain, pos[N], ind[N], len[N], head[N], ftpos[N], ftcnt;
void hld(int u) {
    if(head[chain] == -1) head[chain] = u;
    ind[u] = chain;
    pos[u] = len[chain]++;
    ftpos[u] = ++ftcnt;
    int special = 0, largest = 0;
    for(ii& v : g[u]) {
        if(v.ff != par[u] && sub[v.ff] > largest) {
            largest = sub[v.ff];
            special = v.ff;
        }
    }
    if(special) hld(special);
    for(ii& v : g[u]) {
        if(v.ff != par[u] && v.ff != special) {
            chain++;
            hld(v.ff);
        }
    }
}
void ftupd(int i, int val) {
    for(;i<=ftcnt;i+=(i&(-i))) ft[i] ^= val;
}
void update(int u) {
    ftupd(ftpos[u], val[u]);
}
int ftquery(int i) {
    int ans = 0;
    for(;i;i-=i&(-i)) ans ^= ft[i];
    return ans;
}
int query(int u) {
    int ans = 0, uchain;
    while(u) {
        uchain = ind[u];
        ans ^= ftquery(ftpos[u])^ftquery(ftpos[u]-pos[u]-1);
        u = par[head[uchain]];
    }
    return ans;
}
int main() {
    SYNC
    int t, n, c, qu[N], qv[N], m, k[N], qq[N], ans[N], u, v, ver[N];
    cin >> t;
    val[1] = 0;
    while(t--) {
        cin >> n;
        chain = ftcnt = 0;
        memset(len,0,sizeof len);
        memset(head,-1,sizeof head);
        FOR0(i, n+1) g[i].clear();
        FOR0(i, n-1) {
            cin >> u >> v >> c;
            g[u].pb(mp(v, c));
            g[v].pb(mp(u, c));
        }
        dfs(1, 0);
        hld(1);
        FOR0(i,n) ver[i] = i+1;
        sort(ver, ver + n, [&](int lhs, int rhs) {return val[lhs] <= val[rhs];});
        // queries
        cin >> m;
        FOR0(i, m) {
            cin >> qu[i] >> qv[i] >> k[i];
        }
        FOR0(i, m) qq[i] = i;
        sort(qq,qq+m,[&](int lhs, int rhs) {return k[lhs] <= k[rhs];});
        memset(ft, 0, sizeof ft);
        int ptr = 0;
        FOR0(i,m) {
            while(ptr < n && val[ver[ptr]] <= k[qq[i]]) {
                update(ver[ptr]);
                ptr++;
            }
            ans[qq[i]] = query(qu[qq[i]])^query(qv[qq[i]]);
        }
        FOR0(i,m) cout << ans[i] << '\n';
    }
}