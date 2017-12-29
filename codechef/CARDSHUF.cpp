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
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct node {
    int val; int size; int prior; int lazy;
    node* l; node* r;
};
typedef node* pnode;

int sz(pnode t) { return t ? t->size: 0; }

void upd_sz(pnode t) { if(t) t->size=sz(t->l) + 1 + sz(t->r); }

void lazy(pnode t) {
    if(t && t->lazy) {
        swap(t->l, t->r);
        if(t->l) t->l->lazy ^= 1;
        if(t->r) t->r->lazy ^= 1;
        t->lazy=0;
    }
}
void split(pnode t, pnode& l, pnode& r, int pos, int add=0) {
    if(!t) return void(l=r=NULL);
    lazy(t); int cur = add + sz(t->l);
    if(cur<pos) split(t->r,t->r,r,pos,cur+1),l=t;
    else split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
}

void merge(pnode& t, pnode l, pnode r) {
    lazy(l); lazy(r);
    if(!l || !r) t=l?l:r;
    else if(l->prior > r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
}

pnode init(int val) {
    pnode ret = (pnode) malloc(sizeof(node));
    ret->size = 1, ret->l=ret->r=NULL, ret->val=val, ret->prior=rand(), ret->lazy=0;
    return ret;
}
void insert(pnode& t, pnode it) {
    if(!t) t=it;
    else if(it->prior > t->prior) split(t,it->l,it->r,it->val),t=it;
    else insert(t->val < it->val ? t->r: t->l,it);
    upd_sz(t);
}
void print(pnode t) {
    if(!t) return;
    lazy(t);
    print(t->l);
    cout << t->val << " ";
    print(t->r);
    // free(t);
}
int main() {
    SYNC
    srand(time(0));
    int n, m, a, b, c;
    cin >> n >> m;
    pnode treap=NULL;
    FOR(i, 1, n + 1) {
        insert(treap, init(i));
    }
    while(m--) {
        cin >> a >> b >> c;
        pnode A, B, C;
        split(treap, A, treap, a);
        split(treap, B, treap, b);
        // print(B); cout << newl;
        B->lazy ^= 1;
        merge(treap, A, treap);
        split(treap, C, treap, c);
        merge(treap, B, treap);
        merge(treap, C, treap);
        // print(treap); cout << newl;
    }
    print(treap);
}