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
V<string> ans;
int a[N], b[N], n;
P<int, int> st[4*N]; int lazy[N*4];
void relax(int p) {
    st[p].ff = min(st[p<<1].ff, st[p<<1|1].ff);
    st[p].ss = max(st[p<<1].ss, st[p<<1|1].ss);
}
void build(int p, int l, int r) {
    if(l == r) {st[p] = make_pair(a[l], a[l]); return;}
    int mid = (l + r) >> 1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    relax(p);
}
void lazyUpd(int p, int l, int r) {
    if(lazy[p]) {
        st[p] = make_pair(lazy[p], lazy[p]);
        if(l!=r) {
            lazy[p << 1] = lazy[p];
            lazy[p << 1|1] = lazy[p];
        }
        lazy[p] = 0;
    }
}
void update(int p, int l, int r, int lq, int rq, int val) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return;
    if(lq <= l && r <= rq) {
        st[p] = make_pair(val, val);
        if(l != r) {
            lazy[p << 1] = val;
            lazy[p << 1 | 1] = val;
        }
        return;
    }
    int mid = (l+r) >> 1;
    update(p << 1, l, mid, lq, rq, val);
    update(p << 1 | 1, mid + 1, r, lq, rq, val);
    relax(p);
}
int qmin(int p, int l, int r, int lq, int rq) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return inf;
    if(lq <= l && r <= rq) return st[p].ff;
    int mid = (l+r) >> 1;
    return min(qmin(p << 1, l, mid, lq, rq) , qmin(p << 1|1, mid + 1, r, lq, rq));
}
int qmax(int p, int l, int r, int lq, int rq) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return 0;
    if(lq <= l && r <= rq) return st[p].ss;
    int mid = (l+r) >> 1;
    return max(qmax(p << 1, l, mid, lq, rq) , qmax(p << 1|1, mid + 1, r, lq, rq));
}
int oper(int st, int nd) {
    int x = qmin(1, 0, n-1, st, nd);
    update(1, 0, n-1, st, nd, x);
    ans.push_back("m " + to_string(st+1) + " " + to_string(nd+1));
    return x;
}
void op(int x, int y, int st, int nd) {
    string c = x < y ? "m" : "M";
    update(1, 0, n-1, st, nd, x);
    ans.push_back(c + " " + to_string(st+1) + " " + to_string(nd+1));
}
void re(int st, int nd) {
    if(nd<=st) return;
    else if(st == nd-1) {
        int x = qmin(1, 0, n-1, nd, nd);
        op(a[st], x, st, nd);
    } else {
        op(a[st], oper(st+1,nd), st, nd);
    }
}
void le(int st, int nd) {
    if(nd<=st) return;
    else if(st == nd-1) {
        int x = qmin(1, 0, n-1, st, st);
        op(a[nd], x, st, nd);
    } else {
        op(a[nd], oper(st,nd-1), st, nd);
    }
}

int main() {
    SYNC
    cin >> n;
    FOR0(i, n) cin >> a[i];
    FOR0(i, n) cin >> b[i];
    build(1, 0, n-1);
    V<int> vs({0}), ve, ind;
    FOR(i, 1, n) if(b[i] != b[vs.back()]) {vs.push_back(i); ve.push_back(i-1); }
    ve.push_back(n-1);
    int k = 0;
    FOR0(i, n) {
        if(b[vs[k]] == a[i]) {
            ind.push_back(i);
            k++;
        }
        if(k == vs.size()) break;
    }
    if(k != vs.size()) {cout << -1; return 0;}
    FORD(i, 0, k) {
        re(ind[i], max(ve[i], i==k-1?n-1:ind[i+1]-1));
    }
    le(0, ind[0]);
    FOR(i, 1, k) {
        int st = vs[i]; int nd = max(ve[i], ind[i]);
        if(st != nd) {
            int x = qmin(1, 0, n-1, st, st);
            op(b[st], x, st, nd);
        }
    }
    cout << ans.size() << endl;
    for(string s : ans) cout << s << endl;
}