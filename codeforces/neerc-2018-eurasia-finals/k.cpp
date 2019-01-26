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
const int N = 3e5 + 5;
ll st[4*N], st2[4*N], lazy[4*N]; int n, q;
V<P<int, int>> v;
int search(int t) {
    int lt = 0, rt = n - 1, ans = -1;
    while(lt <= rt) {
        int mid = (lt + rt) >> 1;
        if(v[mid].first > t) {
            rt = mid - 1;
        } else ans = mid, lt = mid + 1;
    }
    return ans;
}
ll build(int p, int l, int r) {
    if(l == r) return st[p] = v[l].first;
    int mid = (l + r) >> 1;
    return st[p] = max(build(p << 1, l, mid) , build(p << 1 | 1, mid + 1, r));
}
void lazyUpd(int p, int l, int r) {
    if(lazy[p]) {
        st[p] += lazy[p];
        // st2[p] += lazy[p];
        if(l!=r) {
            lazy[p << 1] += lazy[p];
            lazy[p << 1|1] += lazy[p];
        }
        lazy[p] = 0;
    }
}
void update(int p, int l, int r, int lq, int rq, ll val) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return;
    if(lq <= l && r <= rq) {
        st[p] += val;
        if(l != r) {
            lazy[p << 1] += val;
            lazy[p << 1 | 1] += val;
        }
        return;
    }
    int mid = (l+r) >> 1;
    update(p << 1, l, mid, lq, rq, val);
    update(p << 1 | 1, mid + 1, r, lq, rq, val);
    st[p] = max(st[p << 1] , st[p << 1|1]);
}
void update(int p, int l, int r, int lq, ll val) {
    int rq = lq;
    if(lq > r || rq < l) return;
    if(lq <= l && r <= rq) {
        st2[p] += val;
        return;
    }
    int mid = (l+r) >> 1;
    update(p << 1, l, mid, lq, val);
    update(p << 1 | 1, mid + 1, r, lq, val);
    st2[p] = st2[p<<1] + st2[p<<1|1];
}
ll query(int p, int l, int r, int lq, int rq) {
    lazyUpd(p, l, r);
    if(lq > r || rq < l) return 0;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l+r) >> 1;
    return max(query(p << 1, l, mid, lq, rq) , query(p << 1|1, mid + 1, r, lq, rq));
}
ll query2(int p, int l, int r, int lq, int rq) {
    // lazyUpd(p, l, r);
    if(lq > r || rq < l) return 0;
    if(lq <= l && r <= rq) return st2[p];
    int mid = (l+r) >> 1;
    return query2(p << 1, l, mid, lq, rq) + query2(p << 1|1, mid + 1, r, lq, rq);
}
int main() {
    SYNC
    cin >> q;
    char c; int t1, t2;
    V<P<int, int>> Q;
    set<int> ts;
    FOR(i, 1, q + 1) {
        cin >> c;
        if(c == '+') {
            cin >> t1 >> t2;
            Q.push_back(make_pair(t1, t2));
            ts.insert(t1);
        } else if (c == '-') {
            cin >> t1;
            Q.push_back({Q[t1-1].first, 0});
        } else {
            cin >> t2;
            ts.insert(t2);
            Q.push_back({-1, t2});
        }
    }
    
    for(int t : ts) v.push_back(make_pair(t, 0));
    n = v.size();
    build(1, 0, n-1);
    for(auto q: Q) {
        if(q.first == -1) {
            int i = search(q.second);
            if(i == -1) {cout << 0 << endl; continue;}
            ll t = max((ll)q.second, query(1, 0, n - 1, 0, i)-query2(1, 0, n - 1, i+1, n-1));
            // cerr << query(1, 0, n - 1, 0, i) << ' ' << query2(1, 0, n - 1, i+1, n-1) << endl;
            // cerr << t << endl;
            cout << t - q.second << endl;
        } else {
            int t = q.first, d = q.second;
            int i = search(t);
            update(1, 0, n - 1, 0, i, d-v[i].second);
            update(1, 0, n - 1, i, d-v[i].second);
            v[i].second = d;
        }
    }
}