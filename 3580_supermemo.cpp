// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
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
// template<typename T> using V = vector<T>;
// template<typename T, typename U> using P = pair<T,U>;
// using ld = long double;
#define ll long long
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
// const ld EPS = 1e-9, PI = acosl(-1.0);
struct node {
    int prior, size, rev; ll val, f, lazy;
    node *l, *r;
};
typedef node* pnode;
node nodes[200005]; int ptr = 0;
inline int sz(pnode t) { return t ? t->size: 0; }
void upd_sz(pnode t) { if(t) t->size = sz(t->l) + 1 + sz(t->r); }

void lazy(pnode t) {
    if(!t) return;
    t->f+=t->lazy,t->val+=t->lazy;
    if(t->rev) swap(t->l,t->r);
    if(t->l) t->l->rev^=t->rev,t->l->lazy+=t->lazy;
    if(t->r) t->r->rev^=t->rev,t->r->lazy+=t->lazy;
    t->lazy=t->rev=0;
}
void print(pnode t) {
    if(!t) return;
    lazy(t);
    print(t->l);
    cout << t->val << " ";
    print(t->r);
}
void combine(pnode &t, pnode l, pnode r) {
    if(!l || !r) return void(t=l?l:r);
    t->f = min(l->f,r->f);
}
void reset(pnode t) {
    if(t) t->f=t->val;
}
void operation(pnode t) {
    if(!t) return;
    reset(t);
    lazy(t->l); lazy(t->r);
    combine(t,t->l,t); combine(t,t,t->r);
}
void split(pnode t, pnode& l, pnode &r, int pos, int add=0) {
    if(!t) return void(l=r=NULL);
    lazy(t);int cur_pos = sz(t->l) + add + 1;
    if(pos<cur_pos) split(t->l,l,t->l,pos,add),r=t;
    else split(t->r,t->r,r,pos,cur_pos),l=t;
    upd_sz(t); operation(t);
}
void merge(pnode& t, pnode l, pnode r) {
    lazy(l); lazy(r);
    if(!l||!r) t=l?l:r;
    else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t); operation(t);
}
pnode init(ll x) {
    pnode ret = &(nodes[++ptr]);
    ret->val=x,ret->rev=ret->lazy=0,ret->prior=rand(),ret->l=ret->r=NULL,ret->size=1;
    reset(ret);
    return ret;
}
void insert(pnode& t, ll val, int pos) {
    pnode l;
    split(t,l,t,pos-1); merge(l,l,init(val)); merge(t,l,t);
}
ll query(pnode& t, int lq, int rq) {
    pnode l, r;
    split(t, l, t, lq-1); split(t, t, r, rq-lq+1);
    ll ans = t->f;
    merge(t,l,t); merge(t,t,r);
    return ans;
}
void range_upd(pnode& t, int l, int r, int val, int rev) {
    pnode L, R;
    split(t, L, t, l-1); split(t, t, R, r-l+1);
    t->lazy+=val; t->rev ^= rev;
    merge(t,L,t);merge(t,t,R);
}
void del(pnode& t, int pos) {
    pnode l, r;
    split(t, l, t, pos-1); split(t, r, t, 1);
    merge(t, l, t);
}
void rot(pnode& t, int l, int r, int d) {
    pnode L,R,M; int len = r - l + 1; d %= len;
    split(t,L,t,l-1); split(t,t,R,len); split(t,t,M,len-d);
    merge(t,M,t); merge(t,L,t); merge(t,t,R);
}
int n, q; ll a;
pnode treap=NULL;
int main() {
    srand(12451);
    scanf("%d", &n);
    FOR0(i, n) {
        scanf("%lld", &a);
        insert(treap, a, i+1);
    }
    int x,y,d; char type[20];
    scanf("%d", &q);
    while(q--) {
        scanf("%s", type);
        if(type[0]=='A') {
            scanf("%d", &x);scanf("%d", &y);scanf("%d", &d);
            range_upd(treap, x, y, d, 0);
        }
        else if(type[0]=='M') {
            scanf("%d", &x);scanf("%d", &y);
            cout << query(treap, x, y) << endl;
        } else if(type[0]=='D') {
            scanf("%d", &x);
            del(treap, x);
        } else if(type[0]=='I') {
            scanf("%d", &x);scanf("%d", &y);
            insert(treap, y, x+1);
        } else if(type[3]=='E') {
            scanf("%d", &x); scanf("%d", &y);
            range_upd(treap, x, y, 0, 1);
        } else {
            scanf("%d", &x);scanf("%d", &y);scanf("%d", &d);
            rot(treap, x, y, d);
        }
    }
    // print(treap);
}