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

vvi graph(30);
vvi graphT(30);
map<string, int> names;
vi ordering;
int n, m, from, to, setNum = 1, visited;
string s;
vector<string> iToName;
void dfs(int u) {
    visited |= 1 << u;
    repi(v, graph[u]) {
        if(!(visited & (1 << *v))) {
            dfs(*v);
        }
    }
    ordering.pb(u);
}

void dfs2(int u, bool start) {
    visited |= 1 << u;
    if(!start) printf(", ");
    cout << iToName[u];
    repi(v, graphT[u])
        if(!(visited & (1 << *v))) dfs2(*v, false);
}

int main() {
    bool started = false;
    while(true) {
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        while (getchar() != '\n') {}
        int numPeople = 0;
        FOR0(i, n) graph[i].clear();
        FOR0(i, n) graphT[i].clear();
        names.clear();
        ordering.clear();
        iToName.clear();
        visited = 0;
        while(m--) {
            getline(cin, s, ' ');
            if(!names.count(s)) names[s] = numPeople++;
            from = names[s];
            getline(cin, s);
            if(!names.count(s)) names[s] = numPeople++;
            to = names[s];
            graph[from].pb(to);
            graphT[to].pb(from);
        }
        iToName.resize(n+1);
        repi(i, names)
            iToName[i->second] = i->first;
        FOR0(i, n)
            if(!(visited & (1 << i))) dfs(i);
        visited = 0;
        if(started) printf("\n");
        printf("Calling circles for data set %d:\n", setNum);
        started = true;
        setNum++;
        dwni(i, ordering) {
            if(!(visited & (1 << *i))) {
                dfs2(*i, true);
                printf("\n");
            }
        }
    }
}