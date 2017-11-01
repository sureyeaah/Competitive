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
typedef pair<ii, int> iii;
#define N 1005
int n, m,dist[N][N][4]; char g[N][N];
inline bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && g[i][j] != '*';
}

int main() {
    SYNC
    int di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
    ii st, nd;
    cin >> n >> m;
    FOR0(i, n) FOR0(j, m) {
        cin >> g[i][j];
        if(g[i][j] == 'V') st = mp(i, j);
        else if(g[i][j] == 'H') nd = mp(i, j);
    }
    memset(dist, 63, sizeof dist);
    FOR0(i, 4) dist[st.ff][st.ss][i] = 0;
    queue<iii> q;
    FOR0(i, 4) q.push(mp(st, i));
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        FOR0(i, 4) {
            int ni = cur.ff.ff + di[i], nj = cur.ff.ss + dj[i];
            if(!valid(ni, nj)) continue;
            int d = dist[cur.ff.ff][cur.ff.ss][cur.ss] + (i != cur.ss);
            if(d < dist[ni][nj][i]) {
                dist[ni][nj][i] = d;
                q.push(mp(mp(ni, nj), i));
            }
        }
    }
    int ans = 2*INF;
    FOR0(i, 4) ans = min(ans, dist[nd.ff][nd.ss][i]);
    if(ans > INF) ans = -1;
    cout << ans;
}