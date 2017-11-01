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

vvi graph(100000 + 10);
int n, u, v, c[100010];
bool possible = false, visited[100000 + 10];
int color;
int poss1 = 0, poss2 = 0;
int use = 0;



void dfs(int u) {
    visited[u] = true;
    repi(v, graph[u]) {
        if(!visited[*v]) {
            if(c[*v] != color) {possible = false; return;}
            dfs(*v);
        }
    }
}

void start(int root) {
    memset(visited, false, sizeof visited);
    visited[root] = true;
    repi(i, graph[root]) {
        color = c[*i];
        dfs(*i);
    }
}

int main() {
    cin >> n;
    FOR0(i, n-1) {
        scanf("%d%d", &u , &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    FOR(i, 1, n+1) scanf("%d", &c[i]);

    FOR(u, 1, n+1) {
        repi(v, graph[u]) {
            if(c[u] != c[*v]) {
                poss1 = u;
                poss2 = *v;
                break;
            }
        }
        if(poss1) break;
    }
    if(poss1) {
        possible = true;
        start(poss1);
        if(possible) use = poss1;
        else {
            possible = true;
            start(poss2);
            if(possible) use = poss2;   
        }
    } else possible = true;
    if(possible) {cout << "YES" << endl; if(use) cout << use << endl; else cout << 1 << endl;}
    else cout << "NO" << endl;
}