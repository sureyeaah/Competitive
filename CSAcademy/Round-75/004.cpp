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
int n, c[N]; ll t[N], ans[N];
int st[4*N];
void build(int p, int l, int r) {
    if(l == r) {st[p] = l; return;}
    int mid = (l + r) >> 1;
    build(p<<1, l , mid); build(p<<1|1, mid + 1, r);
    st[p] = t[st[p<<1]] < t[st[p<<1|1]] ? st[p<<1]: st[p<<1|1];
}

void update(int p, int l, int r, int i, ll val) {
    if(l > i || r < i || l == r) return;
    int mid = (l + r) >> 1;
    update(p << 1, l, mid, i, val); update(p<<1|1, mid + 1, r, i ,val);
    st[p] = t[st[p<<1]] < t[st[p<<1|1]] ? st[p<<1]: st[p<<1|1];
}
void update(int i, ll val) {
    t[i] = val; update(1, 0, n - 1, i, val);
}
int query(int p, int l, int r,ll x) {
    if(l==r) return t[l] <= x ? l : n;
    int mid = (l + r) >> 1;
    return (t[st[p<<1]] <= x ?
        query(p<<1, l, mid, x): query(p<<1|1, mid+1, r, x));
}
int main() {
    SYNC
    cin >> n;
    t[n] = 1e18;
    FOR0(i, N) {
        cin >> c[i] >> t[i];
    }
    ll curt = 0, rem = n;
    build(1, 0, n-1);
    while(rem) {
        int cur = query(1, 0, n-1, curt);
        if(cur == n) cur = st[1], curt = t[cur];
        t[cur] = curt;
        ll l = t[cur], r = t[cur] + c[cur];
        ll val = t[cur];
        update(cur, 1e18);
        while(l <= r) {
            ll mid = (l + r) >> 1;
            int nxt = query(1, 0, n-1, mid - 1);
            if(nxt == n || nxt >= cur) l = mid+1, val = mid;
            else r = mid - 1;
        }
        if(val < curt + c[cur]) {
            update(cur, val);
            c[cur] -= val - curt;
            curt = val;
        }
        else ans[cur] = val, rem--, curt = val;
    }
    FOR0(i, n) cout << ans[i] << " ";
}