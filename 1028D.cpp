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
int n, p; string s;
typedef struct node{
    int val,prior,size,buy,op;
    struct node *l,*r;
}node;
typedef node* pnode;
int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t) t->size = sz(t->l)+1+sz(t->r);
}
void lazy(pnode t){
    if(!t || !t->op) return;
    if(t->buy==0 || t->buy==t->op) t->buy = t->op;
    else t->buy = -1;
    if(t -> l) t->l->op = t->op;
    if(t -> r) t->r->op = t->op;
    t -> op = 0;
}
void split(pnode t,pnode &l,pnode &r,int key){
    lazy(t);
    if(!t) l=r=NULL;
    else if(t->val<=key) split(t->r,t->r,r,key),l=t; //elem=key comes in l
    else split(t->l,l,t->l,key),r=t;    
    upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r){
    if(!l || !r) t=l?l:r;
    else if(l->prior > r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
}
void insert(pnode &t,pnode it){
    if(!t) t=it;    
    else if(it->prior>t->prior) split(t,it->l,it->r,it->val),t=it;
    else insert(t->val<=it->val?t->r:t->l,it);
    upd_sz(t);
}
void op(pnode t, int x) {
    if(!t) return;
    if(t->op && t->op != x) t->buy = -1;
    t->op = x;
    lazy(t);
}

void erase(pnode &t,int key,int&ans){
    if(!t)return;
    else if(t->val==key){ans *= t->buy == -1 ? 0 : t->buy ? 1 : 2;
        ans %= mod;pnode temp=t;merge(t,t->l,t->r);free(temp);}    
    else erase(t->val<key?t->r:t->l,key,ans);
    upd_sz(t);
}
pnode init(int val){
    pnode ret = (pnode)malloc(sizeof(node));
    ret->val=val;ret->size=1;ret->prior=rand();ret->l=ret->r=NULL;
    ret->op = 0; ret->buy = 0;
    return ret;
}
void traverse(pnode t, int& ans) {
    if(!t) return;
    lazy(t);
    ans *= t->buy == -1 ? 0 : t->buy ? 1 : 2;
    ans %= mod;
    traverse(t->l, ans);
    traverse(t->r, ans);
}
pnode treap=NULL;

int main() {
    SYNC
    srand(0);
    cin >> n;
    int ans = 1;
    FOR0(i, n) {
        cin >> s >> p;
        if(s == "ADD") {
            pnode cur = init(p);
            insert(treap, cur);
            
        } else {
            pnode l=NULL,r=NULL,mid=NULL;
            split(treap, l, mid, p-1);
            split(mid, mid, r, p);
            op(l, 1);
            op(r, 2);
            merge(treap,l,r);
            erase(mid, p, ans);
        }
    }
    cout << ans;
}