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
#define val(x) (t[x] - p[x])
int main() {
    SYNC
    int w, h, n, g[N], p[N], t[N], ans[N][2];
    cin >> n >> w >> h;
    map<int, vi> m[2];
    FOR0(i, n) {
        cin >> g[i] >> p[i] >> t[i];
        g[i]--;
        m[g[i]][val(i)].pb(i);
        ans[i][0] = w; ans[i][1] = h;
    }
    // vi elem; FOR0(i, n) elem.pb(i); sort(elem.begin(), elem.end())
    for(auto& cur: m[0]) {
        vi& v1 = cur.ss; vi& v2 = m[1][cur.ff];
        int l =  min(SZ(v1), SZ(v2)), i = 0, j = 0;
        if(!l) continue;
        sort(v1.begin(), v1.end(), [&](int lhs, int rhs) {return p[lhs] < p[rhs];});
        sort(v2.begin(), v2.end(), [&](int lhs, int rhs) {return p[lhs] < p[rhs];});
        FOR0(i, l) {
            int u = v1[SZ(v1) - 1 - i], v = v2[i];
            ans[u][!g[u]] = p[v];
        }
        FOR0(i, l) {
            int u = v2[SZ(v2) - 1 - i], v = v1[i];
            ans[u][!g[u]] = p[v];
        }
        FOR0(i,SZ(v1) - l) {
            int oth = SZ(v2);
            int u = v1[i], v = v1[i + oth];
            ans[u][g[u]] = p[v];
        }
        FOR0(i,SZ(v2) - l) {
            int oth = SZ(v1);
            int u = v2[i], v = v2[i + oth];
            ans[u][g[u]] = p[v];
        }
    }
    FOR0(i, n) {
        if(ans[i][0] == w && ans[i][1] == h) ans[i][g[i]] = p[i];
    }
    FOR0(i, n) cout << ans[i][0] << " " << ans[i][1] << '\n';
}