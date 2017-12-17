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
const int N = 1e5+5, Q = 5005;
int a[N], n, l[Q], r[Q], q, x[Q], st[N*4], m[Q];
long double ans = 0, p[Q], dp[Q][Q] = {};
vvi g(Q);
int build(int p, int l, int r) {
    if(l == r) return st[p] = a[l];
    int mid = (l + r ) >> 1;
    return st[p] = max(build(p << 1, l, mid), build(p<<1|1, mid + 1, r));
}
int query(int p, int l, int r, int lq, int rq) {
    if(l > rq || r < lq) return -1;
    if(lq <= l && r <= rq) return st[p];
    int mid = (l+r) >> 1;
    return max(query(p << 1, l, mid, lq, rq), query(p<<1|1, mid+1, r, lq, rq));
}
void dfs(int i) {
    for(int v : g[i]) {
        dfs(v);
    }
    FOR0(j, q+1) {
        long double p1 = j?p[i]:0, p2 = 1-p[i];
        for(int v : g[i]) {
            if(0 <= m[i] - m[v] + j - 1) p1 *= dp[v][min(q, m[i] - m[v] + j - 1)];
            p2 *= dp[v][min(m[i] - m[v] + j, q)];
        }
        dp[i][j] = p1 + p2;
    }
}
int main() {
    SYNC
    cin >> n >> q;
    FOR0(i, n) {
        cin >> a[i+1];
    }
    build(1,1,n);
    FOR0(i, q) {
        cin >> l[i] >> r[i] >> p[i];
    }
    l[q] = 1; p[q] = 0; r[q] = n; q++;
    FOR0(i, q) {x[i] = i; m[i] = query(1,1,n,l[i],r[i]);}
    sort(x, x + q, [&](int lt, int rt) {return l[lt] != l[rt] ? l[lt] < l[rt]: r[lt] > r[rt];});
    FOR0(j, q) {
        FORD(i, 0, j) {
            if(l[x[i]] <= l[x[j]] && r[x[j]] <= r[x[i]]) {
                g[x[i]].pb(x[j]);
                break;
            }
        }
    }
    dfs(x[0]);
    int i = x[0];
    ans = m[i] * dp[i][0];
    FOR(j, 1, q + 1) {
        ans += (dp[i][j] - dp[i][j-1]) * (m[i] + j);
    }
    cout << fixed << setprecision(10) << ans;
}