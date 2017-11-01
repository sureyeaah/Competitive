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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 10005
#define lmaxn 16
int t, n, a, b, c, wt[maxn], par[maxn], depth[maxn], subsz[maxn], dp[maxn][lmaxn], edgeEnd[maxn];
char type[lmaxn];
vii g[maxn];
int st[maxn*4], path[maxn], pathPos[maxn], ptr = 0;
ii edges[maxn];

void dfs(int u, int dep, int prev) {
    subsz[u] = 1;
    depth[u] = dep;
    par[u] = prev;
    FOR0(i, SZ(g[u])) {
        int v = g[u][i].ff;
        if(prev == v) continue;
        edgeEnd[g[u][i].ss] = v;
        dfs(v, dep + 1, u);
        subsz[u] += subsz[v];
    }
}
void lcainit() {
    FOR(i,1,n+1) {
        for(int j = 0; 1 << j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    FOR(i,2,n+1) dp[i][0] = par[i];
    for(int j = 1; 1 << j <= n; j++) {
        FOR(i,1,n+1) {
            if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}
int LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    FOR0(i,lmaxn) if((diff>>i)&1) u = dp[u][i];
    if(u == v) return u;
    FORD(i,0,lmaxn) if(dp[u][i] != dp[v][i]) {
        u = dp[u][i];
        v = dp[v][i];
    }
    return dp[u][0];
}

int chain = 0, head[maxn], pos[maxn], ind[maxn], len[maxn];
void hld(int u, int prevWt = 0) {
    if(!len[chain]) {
        head[chain] = u;
        pathPos[u] = ptr;
        path[ptr++] = prevWt;
    }
    ind[u] = chain;
    pos[u] = len[chain];
    len[chain]++;
    int special = 0, nxtwt;
    FOR0(i, SZ(g[u])) {
        ii& nxt = g[u][i];
        if(nxt.ff != par[u] && subsz[nxt.ff] > subsz[special]) {special = nxt.ff; nxtwt = wt[nxt.ss];}
    }
    if(special) {
        pathPos[special] = ptr;
        path[ptr++] = nxtwt;
        hld(special);
    }
    FOR0(i, SZ(g[u])) {
        ii& nxt = g[u][i];
        if(nxt.ff != special && nxt.ff != par[u]) {
            chain++;
            hld(nxt.ff, wt[nxt.ss]);
        }
    }
}

int build(int p, int l, int r) {
    if(l == r) return st[p] = path[l];
    return st[p] = max(build(p<<1,l,(l+r)>>1),build(p<<1|1,((l+r)>>1) + 1,r));
}

void update(int p, int l, int r, int i, int val) {
    if(i > r || i < l) return;
    if(l == r) {st[p] = val; return;}
    update(p<<1,l,(l+r)>>1,i,val);
    update(p<<1|1,((l+r)>>1) + 1,r,i,val);
    st[p] = max(st[p<<1], st[p<<1|1]);
}
int stquery(int p, int l, int r , int lq, int rq) {
    if(lq > r || rq < l || lq > rq) return -2*INF;
    if(lq <= l && r <= rq) return st[p];
    return max(stquery(p<<1,l,(l+r)>>1,lq,rq), stquery(p<<1|1,((l+r)>>1) +1,r,lq,rq));
}
int query(int u, int v) {
    int uchain, ans = 0;
    while (ind[u] != ind[v]) {
        uchain = ind[u];
        ans = max(ans, stquery(1,0,ptr-1,pathPos[head[uchain]], pathPos[u]));
        u = par[head[uchain]];
    }
    return max(ans, stquery(1,0,ptr-1,pathPos[v]+1, pathPos[u]));
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        depth[0] = -1; subsz[0] = 0;
        memset(st, 0, sizeof st);
        memset(len, 0, sizeof len);
        chain = 0; ptr = 0;
        FOR0(i,n+1) g[i].clear();
        FOR(i, 1, n) {
            scanf("%d%d%d", &a, &b, &c);
            g[a].pb(mp(b,i));
            g[b].pb(mp(a,i));
            wt[i] = c;
            edges[i] = mp(a,b);
        }
        dfs(1, 0, 0);
        hld(1, 0); chain++;
        lcainit();
        build(1,0,ptr-1);
        while(1) {
            scanf("%s", type);
            if(type[0] == 'D') break;
            scanf("%d%d", &a, &b);
            if(type[0] == 'C') {
                update(1,0,ptr-1,pathPos[edgeEnd[a]],b);
            } else {
                int lca = LCA(a, b);
                printf("%d\n", max(query(a,lca), query(b,lca)));
            }
        }
    }
}