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
typedef pair<ii, ii> iii;
const int N = 105;
const int D = 2000 + 5;
int main() {
    SYNC
    int n, dp[N][D];
    iii a[N];
    ii prev[N][D];
    cin >> n;
    FOR(i, 1, n+1) {
        a[i].ff.ss = i;
        cin >> a[i].ss.ff >> a[i].ff.ff >> a[i].ss.ss;
    }
    memset(dp, -63, sizeof dp);
    sort(a + 1, a + n + 1);
    auto ans = mp(-inf, mp(-1,-1));
    dp[0][0] = 0;
    FOR(i, 1, n+1) {
        FOR0(j, i) {
            FOR(t, a[i].ss.ff, a[i].ff.ff) {
                int & cur = dp[i][t];
                if(a[i].ss.ss + dp[j][t-a[i].ss.ff] > cur) {
                    cur = a[i].ss.ss + dp[j][t-a[i].ss.ff];
                    prev[i][t] = mp(j, t-a[i].ss.ff);
                    ans = max(ans, mp(cur, mp(i, t)));
                }
            }
        }
    }
    if(ans.ff >= 0) {
        cout << ans.ff << endl;
        ii cur = ans.ss;
        vi out;
        while(cur.ff) {
            out.pb(a[cur.ff].ff.ss);
            cur = prev[cur.ff][cur.ss];
        }
        reverse(out.begin(), out.end());
        cout << SZ(out) << endl;
        for(int x : out)
            cout << x << " ";
    } else cout << 0 << endl << 0 << endl;
}