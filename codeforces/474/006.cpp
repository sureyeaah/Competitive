// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 1e5 + 5; int n, m, a[N], b[N], w[N], dp[N];
V<V<int>> g(N), st(N);
int query(int p, int l, int r, int lq, int rq, V<int>& st) {
    if(l > rq || r < lq || lq > rq) return 0;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l + r) >> 1;
    return max(query(p<<1,l,mid,lq,rq,st),query(p<<1|1,mid+1,r,lq,rq,st));
}
int query(int u, int l, int r) {
    return query(1, 0, SZ(g[u]) - 1, l, r, st[u]);
}
void update(int p, int l, int r, int i, int val, V<int>& st) {
    if(l > i || r < i) return;
    if(l == r){
        st[p] = val; return;
    }
    int mid = (l + r) >> 1;
    update(p<<1,l,mid,i,val,st); update(p<<1|1,mid+1,r,i,val,st);
    st[p] = max(st[p<<1], st[p<<1|1]);
}
void update(int u, int i, int val) {
    update(1, 0, SZ(g[u]) - 1, i, val, st[u]);
}
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, m) {
        cin >> a[i] >> b[i] >> w[i];
        g[a[i]].pb(i);
    }
    FOR(i, 1, n + 1) sort(g[i].begin(), g[i].end(), [&](int l, int r) {
        return w[l] > w[r];
    });
    unordered_map<int, int> ind;
    FOR(i, 1, n + 1) {
        FOR0(j, SZ(g[i])) {
            ind[g[i][j]] = j;
        }
    }
    FOR(i, 1, n + 1) st[i].resize(4*SZ(g[i]), 0);
    FORD(i, 0, m + 1) {
        V<int> & cur = g[b[i]];
        int l = 0, r = SZ(cur) - 1, x = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(w[cur[mid]] > w[i]) l = mid + 1, x = mid;
            else r = mid - 1;
        }
        dp[i] = 1 + query(b[i], 0, x);
        update(a[i], ind[i], dp[i]);
    }
    cout << *max_element(dp, dp + m) << endl;
}