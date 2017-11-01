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

int main() {
    int n, l, x, y, color[200];
    vvi graph(201);
    while(true) {
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &l);
        queue<int> q; q.push(0);
        color[0] = 0;
        FOR0(i, n) {
            graph[i].clear();
            color[i] = -1; // uncolored
        }
        FOR0(i, l) {
            scanf("%d %d", &x, &y);
            graph[x].pb(y);
            graph[y].pb(x);
        }
        bool bipartite = true;
        while(bipartite && !q.empty()) {
            int curr = q.front(); q.pop();
            repi(i, graph[curr]) {
                if(color[*i] == -1) {
                    color[*i] = 1 - color[curr];
                    q.push(*i);
                }
                else if(color[*i] == color[curr]) {
                    bipartite = false;
                    break;
                }
            }
        }
        if(bipartite) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}