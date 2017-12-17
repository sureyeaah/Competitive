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
const int N = 2005;
int t, n, m, x[N], c[N], y[N];
vi v;
inline double slope(int i, int o) {
    return x[i] == x[o] ? 9e18: (y[i] - y[o])/(1.0 * x[i] - x[o]);
}
int solve(int p) {
    v.clear();
    int ret = 0, a[2] = {}, ver = -1;
    FOR0(i, n) {
        if (i != p) {
            v.pb(i);
            if(x[i] < x[p]) a[c[i]]++;
            else if(x[i] == x[p]) ver = i;
        }
    }
    sort(v.begin(), v.end(), [&](int l, int r) {
        return slope(l, p) > slope(r, p);
    });

    for(int cur : v) {
        if(cur == ver) {
            ret = max(ret, a[0] + m - a[1] - c[cur] - c[p] + 2);
            ret = max(ret, a[1] + n - m - a[0] + c[cur] + c[p]);
            if(y[cur] > y[p]) {
                a[c[cur]]++;
            }
            continue;
        }

        if(x[cur] < x[p]) {
            a[c[cur]]--;
        }
        ret = max(ret, a[0] + m - a[1] - c[cur] - c[p] + 2);
        ret = max(ret, a[1] + n - m - a[0] + c[cur] + c[p]);
        if(x[cur] > x[p]) {
            a[c[cur]]++;
        }
    }
    return ret;
}
int main() {
    SYNC
    cin >> t;
    v.reserve(N);
    while(t--) {
        cin >> n >> m;
        FOR0(i, n) {
            cin >> x[i] >> y[i];
            c[i] = 0;
        }
        FOR(i, n, m + n) {
            cin >> x[i] >> y[i];
            c[i] = 1;
        }
        if(!m || !n || n + m <= 3) {
            cout << 0 << newl;
            continue;
        }
        n += m;
        int ans = 0;
        FOR0(i, n) {
            ans = max(ans, solve(i));
        }
        cout << n - ans << newl;
    }
}