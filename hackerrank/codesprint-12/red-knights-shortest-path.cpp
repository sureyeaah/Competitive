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
int n, st[2], nd[2], dist[205][205];
vii moves = {{-2, -1}, {-2, 1}, {0, 2}, {2, 1}, {2, -1}, {0, -2}};
vector<string> m;
int pre[205][205];
unordered_map<int, int> prior;
int main() {
    SYNC
    prior[2] = 10; prior[3] = 9; prior[1] = 8; prior[5] = 7; prior[4] = 6; prior[0] = 5; prior[-1] = -1;
    m.pb("UL"); m.pb("UR"); m.pb("R"); m.pb("LR"); m.pb("LL"); m.pb("L"); 
    cin >> n;
    FOR0(i, 2) cin >> st[i];
    FOR0(i, 2) cin >> nd[i];
    memset(dist, 63, sizeof dist);
    memset(pre, -1, sizeof pre);
    dist[st[0]][st[1]] = 0;
    queue<ii> q;
    q.push(mp(st[0], st[1]));
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.ff, y = cur.ss;
        // if(x == nd[0] && y == nd[1]) break;
        FOR0(i, SZ(moves)) {
            int nx = x + moves[i].ff, ny = y + moves[i].ss;
            if(nx < 0 || nx >= n) continue;
            if(ny < 0 || ny >= n) continue;
            if(dist[x][y] + 1 < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                pre[nx][ny] = i;
                q.push(mp(nx, ny));
            }
            // else if(dist[x][y] + 1 == dist[nx][ny]) {
            //     if(prior[i] > prior[pre[nx][ny]]) pre[nx][ny] = i;
            // }
        }
    }
    if(dist[nd[0]][nd[1]] < inf) {
        cout << dist[nd[0]][nd[1]] << newl;
        int x = nd[0], y = nd[1];
        vector<string> out;
        while(pre[x][y] != -1) {
            out.pb(m[pre[x][y]]);
            int i = pre[x][y];
            x -= moves[i].ff; y -= moves[i].ss;
        }
        reverse(out.begin(), out.end());
        for(auto s : out) cout << s << " ";
    } else cout << "Impossible";
}