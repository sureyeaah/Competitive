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
#define N 400005
vvi g(N);
int sub[N], pos[N], cnt = 0, ind[N];
int n, m, c[N], x, y;
int dfs(int u, int prev) {
    ind[u] = sub[u] = ++cnt;
    pos[cnt] = u;
    for(int v : g[u])
        if(v != prev) sub[u] = max(sub[u], dfs(v, u));
    return sub[u];
}
ll st[N*4], lazy[4*N] = {};
ll build(int p, int l, int r) {
    if(l == r) return st[p] = 1LL << c[pos[l]];
    int mid = (l + r) >> 1;
    return st[p] = build(p << 1, l, mid) | build(p << 1 | 1, mid + 1, r);
}
void lazyUpd(int p, int l, int r) {
    if(lazy[p]) {
        st[p] = lazy[p];
        if(l!=r) {
            lazy[p << 1] = lazy[p];
            lazy[p << 1|1] = lazy[p];
        }
        lazy[p] = 0;
    }
}
void update(int p, int l, int r, int lq, int rq, ll val) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return;
    if(lq <= l && r <= rq) {
        st[p] = val;
        if(l != r) {
            lazy[p << 1] = val;
            lazy[p << 1 | 1] = val;
        }
        return;
    }
    int mid = (l+r) >> 1;
    update(p << 1, l, mid, lq, rq, val);
    update(p << 1 | 1, mid + 1, r, lq, rq, val);
    st[p] = st[p << 1] | st[p << 1|1];
}
ll query(int p, int l, int r, int lq, int rq) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return 0;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l+r) >> 1;
    return query(p << 1, l, mid, lq, rq) | query(p << 1|1, mid + 1, r, lq, rq);
}
int main() {
    SYNC
    int type;
    cin >> n >> m;
    FOR0(i, n) cin >> c[i+1];
    FOR0(i, n-1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,0);
    build(1,1,cnt);
    while(m--) {
        cin >> type;
        if(type == 1) {
            cin >> x >> y;
            update(1,1,cnt,ind[x],sub[x],1LL<<y);
        } else {
            cin >> x;
            int ret = 0;
            ll ans = query(1,1,cnt,ind[x],sub[x]);
            FOR0(i,61) if(ans & (1LL << i)) ret++;
            cout << ret << '\n';
        }
    }
}