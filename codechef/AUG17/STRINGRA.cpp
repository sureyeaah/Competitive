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
int t, n, m, x, y, val[N], cnt[N], par[N];
int main() {
    SYNC
    vvi g(N);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int ans = 0;
        memset(par, 63, sizeof par);
        FOR0(i, n+1) g[i].clear();
        FOR0(i, m) {
            cin >> x >> y;
            if(x >= y) {
                ans = -1;
            }
            g[x].pb(y);
            par[y] = min(par[y], x);
        }
        FOR0(i,n) {
            if(!SZ(g[i])) {
                ans = -1;
                break;
            }
            sort(g[i].begin(), g[i].end());
            FOR0(j, SZ(g[i]) - 1) {
                if(g[i][j] == g[i][j+1]) {
                    ans = -1;
                }
            }
        }
        if(ans != -1) {
            memset(val, 0, sizeof val);
            memset(cnt, 0, sizeof cnt);
            FOR0(i, SZ(g[0])) val[g[0][i]] = i + 1;
            FOR(i, 1, n + 1) {
                if(!val[i])
                    val[i] = val[par[i]];
                cnt[val[i]]++;
            }
            int tot = SZ(g[0]);
            FOR0(i,n) {
                set<int> cur;
                for(int x : g[i]) cur.insert(val[x]);
                if(SZ(cur) != tot || SZ(cur) != SZ(g[i])) ans = -1;
                cnt[val[i+1]]--;
                if(!cnt[val[i+1]]) tot--;
            }
        }
        if(ans == -1) {
            cout << -1 << '\n';
        } else {
            cout << val[1];
            FOR(i,2,n+1) cout << ' ' << val[i];
            cout << '\n';
        }        
    }
}