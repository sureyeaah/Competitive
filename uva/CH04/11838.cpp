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

int n, m, v, w, p, num[2010], low[2010], vCount, roots;
vvi graph(2010);
bool visited[2010];
vi s;
void dfs(int u) {
    num[u] = low[u] = ++vCount;
    s.pb(u);
    visited[u] = true;
    repi(v, graph[u]) {
        if(low[*v] == INF)
            dfs(*v);
        if(visited[*v])
            low[u] = min(low[u], low[*v]);
    }
    if(low[u] == num[u]) {
        roots++;
        while(true) {
            int v = s.back();
            s.pop_back();
            visited[v] = false;
            if(v == u) break;
        }
    }
}

int main() {
    while(true) {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        FOR0(i, n+1) graph[i].clear();
        while(m--) {
            scanf("%d%d%d", &v, &w, &p);
            graph[v].pb(w);
            if(p == 2) graph[w].pb(v);
        }
        memset(visited, false, sizeof visited);
        FOR0(i, n+1) low[i] = INF;
        vCount = roots = 0;
        s.clear();
        dfs(1);
        bool possible = roots == 1;
        FOR(i, 1, n+1) if(low[i] == INF) possible = false;
        if(possible) cout << 1 << endl;
        else cout << 0 << endl;
    }
}