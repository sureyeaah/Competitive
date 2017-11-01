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
#define maxn 100005
int q, n, a, b, par[maxn], depth[maxn], subsz[maxn],  type, color[maxn], st[4*maxn];
vi g[maxn];
int pathPos[maxn], ptr = 0, chain = 0, head[maxn], pos[maxn], ind[maxn], len[maxn];

void dfs(int u, int dep, int prev) {
    subsz[u] = 1;
    depth[u] = dep;
    par[u] = prev;
    for(int v : g[u]) {
        if(prev == v) continue;
        dfs(v, dep + 1, u);
        subsz[u] += subsz[v];
    }
}

void hld(int u) {
    if(!len[chain]) {
        head[chain] = u;
    }
    pathPos[u] = ptr++;
    ind[u] = chain;
    pos[u] = len[chain]++;
    int special = 0;
    for(int v : g[u]) {
        if(v == par[u]) continue;
        if(subsz[special] < subsz[v]) special = v;
    }
    if(special)
        hld(special);

    for(int v : g[u]) {
        if(v != special && v != par[u]) {
            chain++;
            hld(v);
        }
    }
}

void update(int p, int l, int r, int i) {
    if(i > r || i < l) return;
    if(l == r) {
        st[p] = (color[a]) ? a : 0;
        return;
    }
    int mid = (l+r) >> 1;
    update(p<<1,l,mid,i); update(p<<1|1,mid+1,r,i);
    st[p] = depth[st[p << 1]] < depth[st[p << 1 | 1]] ? st[p << 1] : st[p << 1 | 1];
}

int rmq(int p, int l, int r, int lq, int rq) {
    if(lq > r || rq < l || rq < lq) return 0;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l+r) >> 1;
    int lans = rmq(p<<1,l,mid,lq,rq), rans = rmq(p<<1|1,mid+1,r,lq,rq);
    return depth[lans] < depth[rans] ? lans : rans;    
}

int query() {
    int ans = 0;
    while(a) {
        int uchain = ind[a];
        int x = rmq(1,0,n-1,pathPos[head[uchain]],pathPos[a]);
        if(x) ans = x;
        a = par[head[uchain]];
    }
    return ans;
}
int main() {
    scanf("%d%d", &n, &q);
    depth[0] = -1; subsz[0] = 0;
    FOR(i, 1, n) {
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0, 0);
    hld(1); chain++;
    depth[0] = INF;
    while(q--) {
        scanf ("%d", &type);
        scanf ("%d", &a);
        if(type) {
            int ans = query();
            if(!ans) ans = -1;
            printf("%d\n", ans);
        } else {
            color[a] ^= 1;
            update(1,0,n-1,pathPos[a]);
        }
    }
}