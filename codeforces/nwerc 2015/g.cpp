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
const int N = 2e5 + 5;
int n, a[N], b[N], c[N];
vector<int> st[4*N], ft[4*N];
void ftupd(int i, vector<int> & ft) {
    for(;i<SZ(ft);i+=i&-i) ft[i]++;
}
int ftquery(int i, vector<int> & ft) {
    int ans = 0;
    for(;i;i-=i&-i) ans += ft[i];
    return ans;
}
void build(int p, int l, int r) {
    ft[p].resize(r-l+2, 0);
    if(l == r) {st[p].pb(c[l]); return;}
    int mid = (l+r)>>1;
    build(p<<1,l,mid); build(p<<1|1,mid+1,r);
    st[p].resize(r-l+1);
    merge(st[p<<1].begin(), st[p<<1].end(), st[p<<1|1].begin(), st[p<<1|1].end(),
        st[p].begin());
}
void update(int p, int l, int r, int i) {
    if(i < l || i > r) return;
    int ind = upper_bound(st[p].begin(), st[p].end(), c[i]) - st[p].begin();
    ftupd(ind, ft[p]);
    if(l == r) return;
    int mid = (l+r) >> 1;
    update(p<<1,l,mid,i); update(p<<1|1,mid+1,r,i);
}
int query(int p, int l, int r, int lq, int rq, int x) {
    if(lq > r || rq < l || lq > rq) return 0;
    if(lq <= l && r <= rq) {
        int ind = lower_bound(st[p].begin(), st[p].end(), x) - st[p].begin();
        return ind - ftquery(ind, ft[p]);
    }
    int mid = (l+r) >> 1;
    return query(p<<1, l, mid, lq, rq, x) +
    query(p<<1|1, mid + 1, r, lq, rq, x);
}
int main() {
    SYNC
    cin >> n;
    FOR(i, 1, n + 1) {
        int tmp; cin >> tmp;
        a[tmp] = i;
    }
    FOR(i, 1, n+1) {
        cin >> b[i];
        b[i] = a[b[i]];
        // cerr << b[i] << " ";
    }
    cerr << endl;
    FOR(i, 1, n+1) {
        cin >> c[i];
        c[i] = a[c[i]];
        // cerr << c[i] << " ";
    }
    FOR(i, 1, n + 1) a[c[i]] = i;
    build(1,1,n);
    ll ans = 0;
    FORD(i, 1, n + 1) {
        ans += query(1,1,n,1,a[b[i]]-1, b[i]);
        update(1,1,n,a[b[i]]);
    }
    cout << ans;
}