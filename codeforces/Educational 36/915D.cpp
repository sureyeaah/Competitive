// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N=505, M = 1e5 + 5;
using ii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
int n, m;
vvi g(N); ii edge[M];
vi vis(N,0);
bitset<M> special, special2;
stack<int> s;
set<int> check;
int dfs1(int u, int parEdge=-1) {
    s.push(parEdge); vis[u]=1;
    for(int e : g[u]) {
        int v = edge[e].ss;
        if(!vis[v]) {
            if(dfs1(v, e)) return 1;
        }
        else if(vis[v]==1) {
            special[e]=1;
            while(1) {
                auto cur = edge[s.top()];
                special[s.top()]=1;
                if(cur.ff==v) break;
                s.pop();
            }
            return 1;
        }
    }
    vis[u]=2;
    s.pop();
    return 0;
}
int cycle(int u, int rem) {
    vis[u]=1;
    for(int e : g[u]) {
        if(rem==e) continue;
        int v = edge[e].ss;
        if(!vis[v]) {
            if(cycle(v, rem)) return 1;
        }
        else if(vis[v]==1) return 1;
    }
    vis[u]=2;
    return 0;
}
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(i); edge[i]=mp(u,v);
    }
    int ans = 1;
    vis.assign(N+1,0);
    FOR(i, 1, n + 1) {
        if(!vis[i] && dfs1(i)) {
            break;
        }
    }
    ans=special.count()==0;
    FOR0(j, m) {
        if(!special[j]) continue;
        vis.assign(N+1,0);
        int cur=1;
        FOR(i, 1, n + 1) {
            if(!vis[i] && cycle(i, j)) cur=0;
        }
        if(cur) ans=1;
    }
    
    cout << (ans?"YES":"NO");
}