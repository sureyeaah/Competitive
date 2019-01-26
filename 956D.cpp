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
const int N = 1e5 + 5;
int n,w;
V<P<int,int>> v1, v2;
int search(P<int,int>& x) {
    int l = 0, r = SZ(v1) - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r )>> 1;
        if(abs(v1[mid].ff * 1LL * (x.ss + w)) <= abs(x.ff * 1LL * (v1[mid].ss + w)))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
V<int> st[4*N];
void build(int p, int l, int r) {
    if (l == r) {
        st[p].pb(l);
        return;
    }
    st[p].resize(r-l+1);
    int mid = (l + r) >> 1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    merge(st[p<<1].begin(), st[p<<1].end(),
        st[p<<1|1].begin(), st[p<<1|1].end(), st[p].begin(), [&](int l, int r) {
            return abs(v1[l].ff * 1LL * (v1[r].ss - w)) < abs(v1[r].ff * 1LL * (v1[l].ss - w));
        });
}
int search(V<int> &v, P<int,int>& x) {
    int l = 0, r = SZ(v) - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1, midx = v[mid];
        if(abs(v1[midx].ff * 1LL * (x.ss - w)) >= abs(x.ff * 1LL * (v1[midx].ss - w)))
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans==-1 ? 0: ans+1;
}
int query(int p, int l, int r, int lq, int rq, P<int,int>& x) {
    if(l > rq || r < lq || lq > rq) return 0;
    if(lq <= l && r <= rq) return search(st[p], x);
    int mid = (l + r) >> 1;
    return query(p<<1, l, mid, lq, rq, x) + 
           query(p<<1|1, mid + 1, r, lq, rq, x);
    return 0;
}
int main() {
    SYNC
    int n; P<int, int> tmp;
    cin >> n >> w;
    FOR0(i, n) {
        cin >> tmp.ff >> tmp.ss;
        if(tmp.ff<0) v1.pb(tmp);
        else v2.pb(tmp);
    }
    ll ans = 0;
    if(SZ(v1) && SZ(v2)) {
        sort(v1.begin(), v1.end(), [](const auto & l, const auto & r) {
        return abs(l.ff * 1LL * (r.ss + w)) < abs(r.ff * 1LL * (l.ss + w));});
        build(1, 0, SZ(v1) - 1);
        // for(auto&cur:v1) cout << cur.ff << " " << cur.ss << endl;
        for(auto & cur : v2) {
            int ind = search(cur);
            if(ind == -1) continue;
            ans += query(1, 0, SZ(v1)-1, 0, ind, cur);
        }
    }
    if(SZ(v2)) {

    }
    cout << ans;
}