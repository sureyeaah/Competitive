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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 100005;
vvi g(N);
int n, a[N], ind[N], par[N] = {},st[N], nd[N] = {}, cnt = 0, x, y, m, ft[N] = {};
void upd(int i, int val) {
    for(;i<=n;i+=i&-i)
        ft[i] = (ft[i] + val) % mod;
}
int query(int i) {
    int ans = 0;
    for(;i;i-=i&-i)
        ans = (ans + ft[i]) % mod;
    return (ans + mod) % mod;
}
void bfs() {
    FOR(i,1,n+1) {
        st[i] = n+2;
    }
    queue<int> q({1});
    par[1] = n+2;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ind[u] = ++cnt;
        st[par[u]] = min(st[par[u]], ind[u]);
        nd[par[u]] = max(nd[par[u]], ind[u]);
        upd(ind[u], a[u]);
        upd(ind[u]+1, -a[u]);
        for(int v : g[u]) {
            if(par[u] == v) continue;
            par[v]= u;
            q.push(v);
        }
    }
}
int main() {
    SYNC
    cin >> n;
    FOR(i,1,n+1)
        cin >> a[i];
    FOR0(i, n-1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs();
    cin >> m;
    while(m--) {
        cin >> x >> y;
        int v = query(ind[y]);
        if(x == 1) {
            if(y != 1) {
                upd(ind[par[y]], v); upd(ind[par[y]] + 1, -v);
            }
            if(nd[y]) {
                upd(st[y], v); upd(nd[y] + 1, -v);
            }
        } else {
            // if(v < 0) v += mod;
            cout << v << '\n';
        }
    }
}