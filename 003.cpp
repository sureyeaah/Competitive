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
int main() {
    SYNC
    vvi m(20601);
    int n, q, c, x[N], y[N], s[N], pre[12][105][105] = {};
    cin >> n >> q >> c;
    FOR0(i, n) {
        cin >> x[i] >> y[i] >> s[i];
        m[x[i]*105 + y[i]].pb(i);
    }
    FOR(curTime, 0, 12) {
        FOR(i, 1, 101) {
            FOR(j, 1, 101) {
                pre[curTime][i][j] += pre[curTime][i][j-1];
                int k = i*105 + j;
                for(int ind : m[k]) {
                    pre[curTime][i][j] += (s[ind] + curTime) % (c + 1);
                }
            }

        }
    }
    while(q--) {
        int tt, xx1, yy1, xx2, yy2;
        cin >> tt >> xx1 >> yy1 >> xx2 >> yy2;
        tt %= (c+1);
        int ans = 0;
        FOR(i,xx1,xx2 + 1) ans += pre[tt][i][yy2] - pre[tt][i][yy1-1];
        cout << ans << '\n';
    }
}