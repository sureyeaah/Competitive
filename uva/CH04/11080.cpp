#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int T, v, e, f, t;
vvi graph(210);
int color[210];
bool bipartite = false;
void dfs(int u) {
    if(!bipartite) return;
    repi(v, graph[u]) {
        if(!color[*v]) {
            color[*v] = -color[u];
            dfs(*v);
        }
        else if(color[*v] == color[u]) {
            bipartite = false;
            return;
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &v, &e);
        FOR0(i, v) graph[i].clear();
        memset(color, 0, sizeof color);
        while(e--) {
            scanf("%d%d", &f, &t);
            graph[f].pb(t);
            graph[t].pb(f);
        }
        bipartite = true;
        int ans = 0, one = 0, none = 0;
        FOR0(i,v) {
            if(!color[i]) {
                color[i] = 1;
                dfs(i);
                int currone = 0, currnone = 0;
                FOR0(i, v) {
                    if(color[i] == 1) currone++;
                    else if(color[i] == -1) currnone++;
                }
                if(currnone - none) ans += min(currone - one, currnone - none);
                else ans += currone - one;
                one = currone; none = currnone;
            }
        }
        if(bipartite) cout << ans << endl;
        else cout << -1 << endl;
    }
}