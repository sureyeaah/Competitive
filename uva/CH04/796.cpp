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

int n, from, conns, to, parent[200], low[200], num[200], vCount;
vvi graph(200);
set<ii> output;

void dfs(int u) {
    low[u] = num[u] = vCount++;
    int childCount = 0;
    repi(i, graph[u]) {
        int v = *i;
        if(num[v] == -1) {
            parent[v] = u;
            childCount++;
            dfs(v);
            if(low[v] > num[u])
                output.insert(mp(min(v,u), max(v,u)));
            low[u] = min(low[u], low[v]);
        } else if(parent[u] != v) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    
    while(cin >> n) {
        output.clear();
        vCount = 0;

        FOR0(i, n) {
            scanf("%d%*c%*c%d%*c", &from, &conns);
            graph[from].clear();
            parent[from] = from;
            num[from] = -1;
            FOR0(i, conns) {
                scanf("%d", &to);
                graph[from].pb(to);
            }
        }

        FOR0(i, n) if(num[i] == -1) dfs(i);
        printf("%d critical links\n", output.size());
        repi(i, output)
            printf("%d - %d\n", (*i).first, (*i).second);
        printf("\n");
    }
}