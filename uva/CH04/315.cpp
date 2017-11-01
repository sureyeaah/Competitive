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

int n, from, to;
string input;
vector<vector<int> > graph(101);
int low[110], num[110], parent[110], vCounter, rootChild;
bool articulation[110];

void dfs(int v) {
    num[v] = low[v] = vCounter++; // set as visited.
    repi(i, graph[v]) {
        int next_v = *i;
        if(num[next_v] == -1) {
            parent[next_v] = v;
            dfs(next_v);
            if (v == 1) rootChild++;
            low[v] = min(low[v], low[next_v]);
            if (low[next_v] >= num[v])
                articulation[v] = true;
        } else if(next_v != parent[v])
            low[v] = min(low[v], num[next_v]);
    }
}

int main() {
    while(scanf("%d", &n), n != 0) {
        while(getchar() != '\n') {}
        vCounter = 1;
        rootChild = 0;
        memset(articulation, false, sizeof articulation);
        FOR(i,1,n+1) {
            graph[i].clear();
            num[i] = -1;
            parent[i] = i;
        }
        while(true) {
            getline(cin, input);
            stringstream numbers(input);
            numbers >> from;
            if(from == 0) break;
            while(numbers >> to) {
                graph[from].pb(to);
                graph[to].pb(from);
            }
        }
        dfs(1);
        articulation[1] = rootChild > 1;
        int numArticulationPoints = 0;
        FOR(i, 1, n+1) if(articulation[i]) numArticulationPoints++;
        printf("%d\n", numArticulationPoints);
    }
}