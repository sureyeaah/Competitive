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
#define inf ((int)2e9)
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
    int val, prior, size;
    struct node *l, *r;
};
typedef node* pnode;

int sz(pnode t) {
    return t ? t->size: 0;
}

void upd_sz(pnode t) {
    if(t) t->size = sz(t->l) + 1 + sz(t->r);
}

void split (pnode t, pnode& l, pnode& r, int key) {
    if(!t) l = r = NULL;
    else if(t->val <= key) split(t->r, t->r, r, key), l = t;
    else split(t->l, l, t->l, key), r = t;
    upd_sz(t);
}

void merge(pnode& t, pnode l, pnode r) {
    if(!l || !r) t = l?l:r;
    else if(l->prior > r->prior) merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
}

void insert(pnode &t, pnode it) {
    if(!t) t=it;
    else if(it->prior > t->prior) split(t, it->l, it->r, it->val),t=it;
    else insert(t->val<=it->val ? t->r: t->l, it);
    upd_sz(t);
}

void erase(pnode& t, int key) {
    if(!t) return;
    if(t->val==key) {pnode tmp=t; merge(t,t->l,t->r); free(tmp);}
    else erase(t->val < key?t->r:t->l,key);
    upd_sz(t);
}

void unite(pnode& t, pnode l, pnode r) {
    if(!l || !r) return void(t=l?l:r);
    if(l->prior < r->prior) swap(l, r);
    pnode lt, rt;
    split (r, lt, rt, l->val);
    unite (l->l, l->l, lt);
    unite (l->r, l->r, rt);
    t = l; upd_sz(t);
}

pnode init(int val) {
    pnode ret = (pnode) malloc(sizeof(node));
    ret->val = val; ret->size = 1; ret->prior=rand(); ret->l=ret->r=NULL;
    return ret;
}

int cnt(pnode t, int x) {
    if(!t) return 0;
    if(t->val < x) return 1 + sz(t->l) + cnt(t->r, x);
    else return cnt(t->l, x);
}
int kth(pnode t, int k) {
    if(!t) return inf;
    if(sz(t->l) >= k) return kth(t->l, k);
    else if(sz(t->l) + 1 == k) return t->val;
    return kth(t->r, k - 1 - sz(t->l)); 
}
int exists(pnode t, int k) {
    if(!t) return 0;
    if(t->val == k) return 1;
    if(k > t->val) return exists(t->r, k);
    return exists(t->l, k);
}
pnode treap=NULL;
int q, val; char x;
int main() {
    SYNC
    srand(time(0));
    cin >> q;
    while(q--) {
        cin >> x >> val;
        if(x=='I') {
            if(!exists(treap, val)) insert(treap, init(val));
        }
        else if(x=='D') erase(treap, val);
        else if(x=='C') cout << cnt(treap, val) << newl;
        else {
            int ans = kth(treap, val);
            if(ans == inf) cout << "invalid" << newl;
            else cout << ans << newl;
        }
    }
}