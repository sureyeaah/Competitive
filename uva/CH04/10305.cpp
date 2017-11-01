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

int n, m,a,b;
vvi edge(101);
vi order;
bool visited[101];

void dfs(int vertex) {
    visited[vertex] = true;
    repi(i, edge[vertex]) {
        if(!visited[*i])
            dfs(*i);
    }
    order.pb(vertex);
    edge[vertex].clear();
}

int main() {
    
    while(true) {
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        FOR0(i, m) {
            scanf("%d%d", &a, &b);
            edge[a].pb(b);
        }
        memset(visited, false, sizeof visited);
        order.clear();
        FOR(i, 1, n+1) {
            if(!visited[i])
                dfs(i);
        }
        dwni(i, order)
            printf("%d ", *i);
        printf("\n");
    }
}