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
const int N = 100005;
vector<vii> g(N);
int main() {
    SYNC
    int n,m,s,t,a,b,p, dist[N], par[N];
    long double prob[N];
    cin >> n >> m >> s >> t;
    while(m--) {
        cin >> a >> b >> p;
        g[a].pb(mp(b, 100 - p));
        g[b].pb(mp(a, 100 - p));
    }
    FOR(i,1,n+1) prob[i] = -100;
    memset(dist, 63, sizeof dist);
    dist[s] = 0; par[s] = 0; prob[s] = 1;
    queue<int> q({s});
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == t) break;
        for(auto cur : g[u]) {
            int v = cur.ff, p = cur.ss;
            if(dist[v] > dist[u]) {
                if(prob[v] < prob[u]*p/100.0) {
                    prob[v] = prob[u]*p/100.0;
                    par[v] = u;
                }
                if(dist[v] > n) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }
    int u = t; vi out;
    while(u) {
        out.pb(u);
        u = par[u];
    }
    reverse(out.begin(), out.end());
    cout << SZ(out) << " " << fixed << setprecision(10) << 1-prob[t] << endl;
    for(int x : out) cout << x << " ";
}