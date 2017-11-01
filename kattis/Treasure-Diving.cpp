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
#define N 10005
#define S ((1 << 8) + 5)
int avail, t, n, m, a, b, c, idols, p[15], dist[N], d[10][10], dp[10][S], cnt[10];
vector<vii> g(N);
void djikstra(int st) {
    memset(dist, 63, sizeof dist);
    dist[st] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(mp(0, st));
    while(!pq.empty()) {
        int u = pq.top().ss, d = pq.top().ff; pq.pop();
        if(d > dist[u]) continue;
        for(auto cur : g[u]) {
            if(cur.ss + dist[u] < dist[cur.ff]) {
                dist[cur.ff] = cur.ss + dist[u];
                pq.push(mp(dist[cur.ff], cur.ff));
            }
        }
    }
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> m;
        FOR0(i, n+1) g[i].clear();
        FOR0(i, m) {
            cin >> a >> b >> c;
            g[a].pb(mp(b, c));
            g[b].pb(mp(a, c));
        }
        cin >> idols;
        map<int, int> m;
        FOR0(i, idols) {
            cin >> a;
            m[a]++;
        }
        idols = 0;
        for(auto cur : m) {
            if(cur.ff == 0) continue;
            p[idols++] = cur.ff;
        }
        p[idols] = 0;
        cin >> avail;
        FOR0(i, 1+idols) {
            djikstra(p[i]);
            FOR0(j, idols+1) d[i][j] = dist[p[j]];
        }
        int ans = m[0];
        for(int mask = 1; mask < (1 << idols); mask++) {
            FOR0(i, idols) {
                if(mask & (1 << i)) {
                    dp[i][mask] = avail + 1;
                    int curCnt = m[0] + m[p[i]];
                    if((mask ^ (1 << i)) == 0) dp[i][mask] = d[idols][i];
                    FOR0(j, idols) {
                        if(mask & (1 << j) && j != i) {
                            curCnt += m[p[j]];
                            if(dp[j][mask^(1 << i)] <= avail) dp[i][mask] = min(dp[i][mask], d[i][j] + dp[j][mask^(1 << i)]); 
                        }
                    }
                    if(dp[i][mask] + d[i][idols] <= avail) ans = max(ans, curCnt);
                }
            }
        }
        cout << ans << newl;
    }
}