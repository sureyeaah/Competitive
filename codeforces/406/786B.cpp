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
typedef pair<ll, int> II;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 100005
vector<vii> g(N * 5);
int n, par[N];
void addEdge(int p, int l, int r, int lq, int rq, int w, int v, int dir) {
    if(l > rq || r < lq || lq > rq) return;
    if(lq <= l && r <= rq) {
        FOR(i,l,r+1) {
            if(dir) g[p].pb(mp(par[v], w));
            else g[par[v]].pb(mp(p, w));
        }
        return ;
    }
    int mid = (l + r) >> 1;

    addEdge(p << 1, l, mid, lq, rq, w, v, dir);
    addEdge(p << 1|1, 1 + mid, r, lq, rq, w, v, dir);
}
void build(int p, int l, int r) {
    if(l == r) {
        par[l] = p;
        return;
    }
    g[p].pb(mp(p << 1, 0));
    g[p].pb(mp(p << 1|1, 0));
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
int main() {
    SYNC
    int q, s, type, v, l, r, w;
    cin >> n >> q >> s;
    build(1,1,n);
    while(q--) {
        cin >> type >> v;
        if(type == 1) {
            cin >> l >> w;
            addEdge(1,1,n,l,l,w,v,0);
        } else {
            cin >> l >> r >> w;
            addEdge(1,1,n,l,r,w,v,type-2);
        }
    }

    ll dist[5*N];
    memset(dist, 63, sizeof dist);
    dist[par[s]] = 0;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push(mp(0, par[s]));
    while(!pq.empty()) {
        int u = pq.top().ss; ll d = pq.top().ff; pq.pop();
        if(d > dist[u]) continue;
        for(auto nxt : g[u]) {
            if(nxt.ss + dist[u] < dist[nxt.ff]) {
                dist[nxt.ff] = nxt.ss + dist[u];
                pq.push(mp(dist[nxt.ff], nxt.ff));
            }
        }
    }
    FOR(i, 1, n+1) cout << (dist[par[i]] < 1e14 + 5 ? dist[par[i]]: -1) << " ";
}