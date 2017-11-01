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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 100005
#define dist(cur,nxt) (cur > nxt ? n-cur+nxt: nxt - cur)
int st[4*N];int n, a[N]; ll ans = 0;
int cur = INF, ptr = 0;
vvi c(N);
void build(int p, int l, int r) {
    if(l == r) {st[p] = l; return;}
    int mid = (l+ r) >> 1;
    build(p << 1, l, mid); build(p << 1|1, mid + 1, r);
    st[p] = a[st[p << 1]] <= a[st[p<<1|1]] ? st[p << 1]: st[p << 1|1];
}
int query(int p, int l, int r, int lq, int rq) {
    if(lq > r || rq < l || lq > rq) return n;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l+r) >> 1;
    int lans = query(p<<1,l,mid,lq,rq);int rans = query(p<<1|1,mid+1,r,lq,rq);
    return a[lans] <= a[rans] ? lans : rans;
}
void update(int p, int l, int r, int i, int val) {
    if(i > r || i < l) return;
    if(l == r) {st[p] = n; return;}
    int mid = (l+r) >> 1;
    update(p<<1,l,mid,i,val);
    update(p<<1|1,mid+1,r,i,val);
    st[p] = a[st[p << 1]] <= a[st[p<<1|1]] ? st[p << 1]: st[p << 1|1];
}
int ft[N] = {};
int ftquery(int i) {
    int ans = 0;
    i++;
    for(;i;i-=i&(-i)) ans += ft[i];
    return ans;
}
void ftupdate(int i) {
    i++;
    for(;i<=n;i+=i&(-i)) ft[i]++;
}
int main() {
    SYNC
    cin >> n; int largest = 0;
    FOR0(i,n) {
        cin >> a[i];
        largest = max(largest, a[i]);
        cur = min(cur, a[i]);
        c[a[i]].pb(i);
    }
    a[n] = INF;
    build(1,0,n-1);
    while(cur <= largest) {
        if(SZ(c[cur]) == 0) {cur++; continue;}
        int nxt = ptr;
        for(int card : c[cur]) {
            if(dist(ptr, card) > dist(ptr, nxt)) nxt = card;
        }
        ans += dist(ptr,nxt)-(nxt < ptr ?  ftquery(n-1)-ftquery(ptr-1)+ftquery(nxt): ftquery(nxt)-ftquery(ptr-1)) + 1;
        for(int card : c[cur]) {
            update(1,0,n-1,card,INF);
            ftupdate(card);
        }
        ptr = nxt;
        nxt = query(1,0,n-1,ptr+1,n-1);
        if(nxt == n) nxt = query(1,0,n-1,0,ptr-1);
        if(nxt != n) ans += dist(ptr,nxt)-(nxt < ptr ?  ftquery(n-1)-ftquery(ptr-1)+ftquery(nxt): ftquery(nxt)-ftquery(ptr-1));
        cur++; ptr = nxt;
    }
    cout << ans;
}