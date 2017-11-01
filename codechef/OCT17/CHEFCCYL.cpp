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
const int N = 1e5 + 5;
int t, n, q, a;
vector<vector<ll>> dp(N);
ll cycdp[N + 5] = {};
ii e[N][2];
inline int nxt(int i) {return (i==n?1:i+1);}
inline int pre(int i) {return (i==1?n:i-1);}
ll dist(int cyc, int u, int v) {
    ll x = abs(dp[cyc][u] - dp[cyc][v]);
    return min(x, dp[cyc].back()-x);
}
int v1, c1, v2, c2;
ll query() {
    if(c1 > c2) {
        swap(c1, c2);
        swap(v1, v2);
    }
    ll d1 = dist(c1, v1, e[c1][1].ff) + cycdp[c2-1] - cycdp[c1] + e[c2][0].ss + dist(c2, v2, e[c2][0].ff);
    ll d2 = dist(c2, v2, e[c2][1].ff) + cycdp[n] - cycdp[c2] + e[n][1].ss + dist(c1, v1, e[c1][0].ff);
    if(c1 > 1) d2 += cycdp[c1-1] + e[c1][0].ss + dist(1, e[1][0].ff, e[1][1].ff);
    // DEBUG(d1); DEBUG(d2);
    return min(d1, d2);
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> q;
        FOR(i,1,n+1) {
            cin >> a;
            dp[i].clear();
            dp[i].resize(a+2, 0);
            FOR(j, 2, a+2) {
                cin >> dp[i][j];
                dp[i][j] += dp[i][j-1];
            }
        }
        FOR(i,1,n+1) {
            int v1, v2, w;
            cin >> v1 >> v2 >> w;
            e[i][1] = mp(v1, w);
            e[nxt(i)][0] = mp(v2, w);
        }
        cycdp[1] = 0;
        FOR(i,1,n+1) {
            cycdp[i+1] = cycdp[i] + dist(nxt(i), e[nxt(i)][1].ff, e[nxt(i)][0].ff) + e[i][1].ss;
        }
        while(q--) {
            cin >> v1 >> c1 >> v2 >> c2;
            cout << query() << newl;
        }
    }
}