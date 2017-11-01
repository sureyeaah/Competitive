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
#define N 200005
int n, q, a, b, c, toRoot[N] = {}, type, p = 0, ett[N << 1], st[N], nd[N], wt[N];
ll ft[N << 1] = {}, seg[N*8], lazy[N*8] = {};
vector<vii> g(N);
vi edges;
void update(int i, int val) {
    for(;i <= (n << 1); i+=i&(-i)) ft[i] += val;
}
ll query(int i) {
    ll ret = 0;
    for(;i;i-=i&(-i)) ret += ft[i];
    return ret;
}
// segment
ll build(int p, int l, int r) {
    if(l == r)
        return seg[p] = toRoot[ett[l]] + query(st[ett[l]]);
    int mid = (l + r) >> 1;
    return seg[p] = min(build(p << 1, l, mid), build(p << 1|1, mid + 1, r));
}

void stupdate(int p, int l, int r, int lq, int rq, ll val) {
    if(lazy[p]) {
        seg[p] += lazy[p];
        if(l != r) {
            lazy[p << 1] += lazy[p];
            lazy[p << 1|1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(l > rq || r < lq) return;
    if(lq <= l && r <= rq) {
        seg[p] += val;
        if(l != r) {
            lazy[p << 1] += val;
            lazy[p << 1|1] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    stupdate(p << 1, l, mid, lq, rq, val);
    stupdate(p << 1|1, mid+1, r, lq, rq, val);
    seg[p] = min(seg[p << 1], seg[p << 1 | 1]);
}

ll stquery(int p, int l, int r, int lq, int rq) {
    if(lazy[p]) {
        seg[p] += lazy[p];
        if(l != r) {
            lazy[p << 1] += lazy[p];
            lazy[p << 1|1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(l > rq || r < lq) return (ll)1e18;
    if(lq <= l && r <= rq) {
        return seg[p];
    }
    int mid = (l + r) >> 1;
    return min(stquery(p << 1, l, mid, lq, rq), stquery(p << 1|1, mid+1, r, lq, rq));
}
void dfs(int u) {
    ett[++p] = u;
    st[u] = p;
    for(ii v : g[u]) {
        dfs(v.ff);
        wt[v.ff] = v.ss;
        update(st[v.ff], v.ss);
        update(nd[v.ff], -v.ss);
    }
    ett[++p] = u;
    nd[u] = p;
}
int main() {
    SYNC
    cin >> n >> q;
    FOR0(i, n-1) {
        cin >> a >> b >> c;
        g[a].pb(mp(b, c));
        edges.pb(b);
    }
    FOR0(i, n-1) {
        cin >> a >> b >> c;
        toRoot[a] = c;
        edges.pb(a);
    }
    dfs(1);
    build(1,1,2*n);
    while(q--) {
        cin >> type >> a >> b;
        if(type == 1) {
            a--;
            if(a < n-1) {
                a = edges[a];
                update(st[a], b-wt[a]);
                update(nd[a], -b+wt[a]);
                stupdate(1,1,2*n,st[a], nd[a], b-wt[a]);
                wt[a] = b;
            } else {
                a = edges[a];
                stupdate(1,1,2*n,st[a],st[a], b-toRoot[a]);
                stupdate(1,1,2*n,nd[a],nd[a], b-toRoot[a]);
                toRoot[a] = b;
            }
        } else {
            if(a == b) cout << 0 << '\n';
            else cout << query(st[b]) - query(st[a]) + (st[a] < st[b] && nd[b] < nd[a] ? 0 : stquery(1,1,2*n,st[a],nd[a])) << '\n';
        }
    }
}