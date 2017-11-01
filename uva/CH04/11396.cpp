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

int v, a, b;
vvi graph(310);
int color[310];
bool bipartite;

void dfs(int u) {
    if(!bipartite) return;
    repi(v, graph[u]) {
        if(!color[*v]) {
            color[*v] = -color[u];
            dfs(*v);
        } else if(color[*v] == color[u]) {
            bipartite = false;
            return;
        }
    }
}

int main() {
    while(true) {
        scanf("%d", &v);
        if(!v) break;
        FOR0(i, v+1) graph[i].clear();
        memset(color, 0, sizeof color);
        while(true) {
            scanf("%d%d", &a ,&b);
            if(!a && !b) break;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        bipartite = !(v%2);
        color[1] = 1;
        dfs(1);
        if(bipartite) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}