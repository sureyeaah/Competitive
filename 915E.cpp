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
const int N = 3e5+5;
int n, q, l[N], r[N], k[N], ptr=0;
vi st;
ll build(int p, int l, int r) {
    if(l == r) return st[p] = 1LL << c[pos[l]];
    int mid = (l + r) >> 1;
    return st[p] = max(build(p << 1, l, mid) , build(p << 1 | 1, mid + 1, r));
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
    st[p] = max(st[p << 1] , st[p << 1|1]);
}
ll query(int p, int l, int r, int lq, int rq) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return 0;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l+r) >> 1;
    return max(query(p << 1, l, mid, lq, rq) , query(p << 1|1, mid + 1, r, lq, rq));
}

int main() {
    SYNC
    unordered_map<int, int> m;
    cin >> n >> q;
    FOR0(i, q) {
        cin >> l[i] >> r[i] >> k[i];
        m[l[i]]=1; m[r[i]]=1; m[r[i]+1]=1;
    }
    m[1]=1;
    for(auto& p : m) p->s==++ptr;
    int pre=1;
    for(auto& p : m) {
        sz.pb(p->ff - pre);
        pre = p->ff;
    }
    int M = (ptr+5);
    st.assign((ptr+5)*4 + 10,0);
    vi ans(ptr+5, 0), work(ptr+5,0);
    FOR0(i, q) {
        if(k==2) {
            update(1, 1, M, m[l[i]], m[r[i]], i);
        }
    }
    FOR(i, 1, ptr + 1) work[i]=query(1, 1, M, i, i);
    st.assign((ptr+5)*4 + 10,0);
    FOR0(i, q) {
        if(k==1) {
            update(1, 1, M, m[l[i]], m[r[i]], i);
        }
    }
    FOR(i, 1, ptr + 1) {
        x=query(1, 1, M, i, i);
        if(x > work[i]) ans[i]=1;
    }
    FOR(i, 1, ptr) if(!ans[i]) days += sz[i];
    cout << days;
}