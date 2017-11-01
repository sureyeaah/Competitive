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
const int N = 1e6 + 5;
int t, n, m[N], sorted[N];
ll st[4*N][2];
vvi dish(N);
vector<vector<ll>> val(N);
vector<pair<int , ll>> dp1(N), dp2(N);
ll build(int p, int l, int r, vector<pair<int, ll>>& a, int i) {
    if(l == r) {
        return st[p][i] = a[l].ss;
    }
    int mid = (l + r) >> 1;
    return st[p][i] = max(build(p << 1, l, mid, a, i), build(p << 1 | 1, mid + 1, r, a, i));
}
ll query(int p, int l, int r, int lq, int rq, int i) {
    if(lq > r || rq < l || lq > rq) return -INF;
    if(lq <= l && r <= rq) return st[p][i];
    int mid = (l + r) >> 1;
    return max(query(p << 1, l, mid, lq, rq, i), query(p << 1 | 1, mid + 1, r, lq, rq, i));
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n;
        FOR0(i, n) {
            cin >> m[i];
            val[i].clear();
            dish[i].clear();
            dish[i].resize(m[i]);
            val[i].resize(m[i]);
            FOR0(j, m[i]) cin >> dish[i][j];
        }
        fill(val[n-1].begin(), val[n-1].end(), 0);
        FORD(i, 0, n-1) {
            dp1.clear(); dp2.clear();
            FOR0(j, m[i+1]) {
                dp1.pb(mp(dish[i+1][j], 1LL*dish[i+1][j]*(i+1) + val[i+1][(j+m[i+1]-1) % m[i+1]]));
                dp2.pb(mp(dish[i+1][j], -1LL*dish[i+1][j]*(i+1) + val[i+1][(j+m[i+1]-1) % m[i+1]]));
            }

            sort(dp1.begin(), dp1.end());
            sort(dp2.begin(), dp2.end());
            build(1,0,m[i+1]-1,dp1,0);
            build(1,0,m[i+1]-1,dp2,1);

            FOR0(j, m[i]) {
                int x = lower_bound(dp1.begin(), dp1.end(), mp(dish[i][j], -INF)) - dp1.begin();
                val[i][j] = max(query(1, 0, m[i+1]-1, 0, x-1, 1) + 1LL*(i+1)*dish[i][j], query(1, 0, m[i+1]-1, x, m[i+1] - 1, 0) - 1LL*(i+1)*dish[i][j]);
            }
        }
        cout << *max_element(val[0].begin(), val[0].end()) << newl;
    }
}