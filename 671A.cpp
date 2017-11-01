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
#define EPS ((long double)1e-9)
int p[2][2], r[2], n, a[N][2];
int neg[2] = {};
pair<long double, int> v[2][N];
ll dist(int x1, int x2, int y1, int y2) {
    return pow((ll)x1- x2, 2) + pow((ll)y1 - y2, 2);
}
bool compare(pair<long double, int>&lhs, pair<long double, int>&rhs ) {
    return abs(lhs.ff - rhs.ff) < EPS ? lhs.ss < rhs.ss: lhs.ff < rhs.ff;
}

int main() {
    SYNC
    FOR0(i, 2) cin >> p[i][0] >> p[i][1];
    cin >> r[0] >> r[1] >> n;
    FOR0(i, n) cin >> a[i][0] >> a[i][1];
    long double ans = 0;
    FOR0(i, n) ans += 2 * hypot((long double)r[0] - a[i][0], (long double)r[1] - a[i][1]);
    FOR0(j, 2) {
        FOR0(i, n) {
            if(dist(p[j][0],a[i][0],p[j][1],a[i][1]) < dist(r[0],a[i][0],r[1],a[i][1])) neg[j]++;
            long double cur = hypot((long double)p[j][0] - a[i][0], (long double)p[j][1] - a[i][1]) - hypot((long double)r[0] - a[i][0], (long double)r[1] - a[i][1]);
            v[j][i] = mp(cur, i);
        }
        sort(v[j], v[j] + n, compare);
    }
    if(neg[0] && neg[1]) {
        if(v[0][0].ss == v[1][0].ss) {
            long double v1 = v[0][0].ff;
            if (neg[1] > 1) v1 += v[1][1].ff;
            long double v2 = v[1][0].ff;
            if (neg[0] > 1) v2 += v[0][1].ff;
            ans += min(v1, v2);
        } else ans += v[0][0].ff + v[1][0].ff;
    }
    else if(neg[0] || neg[1]) {
        if(neg[0]) ans += v[0][0].ff;
        else ans += v[1][0].ff;
    } else ans += min(v[0][0].ff, v[1][0].ff);
    cout << setprecision(9) << fixed << ans;
}