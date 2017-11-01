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

class comparator {
    public:
        bool operator()(const ii & a, const ii & b) {
            if(a.first != b.first) return a.first > b.first;
            if(a.second != b.second) return a.second < b.second;
        }
};

int n, m, x, y;
vvi graph(10000);
bool visited[10001];
int vCount, low[10001], num[10001];
vii output;
int piegons[10001], parent[10001];
int rootChild;

void dfs(int u) {
    visited[u] = true;
    num[u] = low[u] = vCount++;
    repi(i, graph[u]) {
        int v = *i;
        if(!visited[v]) {
            if(u == 0) rootChild++;
            parent[v] = u;
            visited[v] = true;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= num[u])
                piegons[u]++;
        }
        else if(parent[u] != v)
            low[u] = min(low[u], num[v]);
    }
    piegons[u] = min(piegons[u] + 1, (int)graph[u].size());
}

int main() {
    while(true) {
        scanf("%d%d", &n, &m);
        if(!m && !n) break;
        memset(visited, false, sizeof visited);
        memset(piegons, 0, sizeof piegons);
        vCount = 0;
        FOR0(i, n) graph[i].clear();
        while(true) {
            scanf("%d%d", &x, &y);
            if(x == -1 && y == -1) break;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        // num pegions[i] = num components
        parent[0] = 0;
        rootChild = 0;
        dfs(0);
        output.clear();
        piegons[0] = rootChild;
        FOR0(i, n) output.pb(mp(piegons[i], i));
        sort(output.begin(), output.end(), comparator());
        FOR0(i, m) {
            ii out = output[i];
            printf("%d %d\n", out.second, out.first);
        }
        printf("\n");
    }
}