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

vvi graph(1000000 + 5);
int n, m, from, to;
bool visited[1000000 + 5];
vi ordering(1000000+5);

void dfs(int u) {
    visited[u] = true;
    repi(v, graph[u]) {
        if(!visited[*v]) {
            dfs(*v);
        }
    }
    ordering.pb(u);
}

void dfs2(int u) {
    visited[u] = true;
    repi(v, graph[u])
        if(!visited[*v]) dfs2(*v);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int ans = 0;
        scanf("%d%d", &n, &m);
        FOR0(i, n+1) graph[i].clear();
        FOR0(i, n+1) visited[i] = false;
        ordering.clear();
        while(m--) {
            scanf("%d%d", &from, &to);
            graph[from].pb(to);
        }
        FOR(i, 1, n+1)
            if(!visited[i]) dfs(i);
        FOR0(i, n+1) visited[i] = false;
        dwni(i, ordering) {
            if(!visited[*i]) {
                dfs2(*i);
                ans++;
            }
        }
        cout << ans << endl;
    }
}