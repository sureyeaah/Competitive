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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 300005;
int n,m,l[N],c[N],p[N];
ll q, dp[N] = {}, pre[N] = {}, st[N*4] = {};
int search(int st, ll val) {
    int ans, l = st, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(pre[st] - pre[mid] <= val) {
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    return ans;
}
ll query(int p, int l, int r, int lq, int rq) {
    if(l > rq || r < lq || lq > rq) return INF;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l + r) >> 1;
    return min(query(p << 1, l, mid, lq, rq), query(p << 1 | 1, mid + 1, r, lq, rq));
}
void update(int p, int l, int r, int i, ll val) {
    if(l > i || r < i) return;
    if(l == r) {
        st[p] = min(st[p], val);
        return;
    }
    int mid = (l + r) >> 1;
    update(p << 1, l, mid, i, val); update(p << 1|1, mid + 1, r, i, val);
    st[p] = min(st[p << 1], st[p << 1 | 1]);
}
int main() {
    SYNC
    cin >> n >> m;
    FOR(i,1,n) cin >> l[i];
    FOR(i,1,n) cin >> c[i];
    FOR(i,1,n) cin >> p[i];
    FORD(i,1,n) pre[i] = pre[i+1] + l[i];
    memset(st, 63, sizeof st);
    update(1,1,n,n,dp[n]);
    FORD(i,1,n) {
        int r = search(i,c[i]);
        if(r == i)
            dp[i] = 1e16;
        else
            dp[i] = query(1,1,n,i+1,r) + p[i];
        update(1,1,n,i,dp[i]);
    }
    pre[0] = pre[1];
    while(m--) {
        cin >> q;
        int r = search(0,q);
        ll ans = query(1,1,n,1,r);
        if(ans >= 1e16) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}