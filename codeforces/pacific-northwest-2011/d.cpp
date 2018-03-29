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
const int N = 1e6 + 5;
int walls, n;
P<int, int> p[N][3];
int ind[N][3];
ll val(P<int, int> p) {
    return (((ll)p.ff) << 32) + p.ss;
}
V<V<int>> g(N);
unordered_map<ll, int> pm;
unordered_map<ll, int> lm;
void solve(P<int, int> P1, P<int, int> P2) {
    int p1 = pm[val(P1)], p2 = pm[val(P2)];
    int t1 = lm[val(mp(p1, p2))], t2 = lm[val(mp(p2, p1))];
    if(!t2) return;
    if(P1.ff > P2.ff) {
        g[t1].pb(t2);
    }
}
int vis[N];
V<int> st;
void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(!vis[v]) dfs(v);
    }
    st.pb(u);
}
int main() {
    SYNC
    cin >> walls;
    while(walls--) {
        cin >> n;
        st.clear();
        pm.clear(); lm.clear();
        FOR(i, 1, n + 1) {
            g[i].clear();
            vis[i] = 0;
            FOR0(j, 3) {
                cin >> p[i][j].ff >> p[i][j].ss;
                pm[val(p[i][j])] = 1;
            }
        }
        for(auto & cur : pm) {
            static int cnt = 1;
            cur.ss = cnt++;
        }
        FOR(i, 1, n + 1) {
            FOR0(j, 3) {
                ind[i][j] = pm[val(p[i][j])];
            }
        }
        FOR(i, 1, n + 1) {
            FOR0(j, 3) {
                lm[val(mp(ind[i][j], ind[i][(j+1)%3]))]=i;
            }
        }
        FOR(i, 1, n + 1) {
            FOR0(j, 3) {
                solve(p[i][j], p[i][(j+1)%3]);
            }
        }
        FOR(i, 1, n + 1) {
            if(!vis[i]) dfs(i); 
        }
        reverse(st.begin(), st.end());
        for(int x : st) cout << x << " ";
        cout << endl;
    }
}